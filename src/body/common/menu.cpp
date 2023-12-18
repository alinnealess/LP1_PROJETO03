#include <iostream>
#include <list>
#include <limits>
#include <stdexcept>
#include "../../header/classes/standalone/bancoDao.hpp"

using namespace std;

/**
 * @brief Ends the program.
 *
 * This function prints a farewell message and ends the program.
 */
void encerraPrograma()
{
  cout << "Até a próxima!" << endl;
  exit(0);
}

/**
 * @brief Represents a person.
 */
Pessoa criaPessoa()
{
  cout << "(Dados de pessoa)" << endl;
  cout << "Nome: ";
  string nome;
  getline(cin, nome);
  if (nome.empty())
  {
    throw std::invalid_argument("Nome não pode ser vazio");
  }

  cout << "CPF: ";
  string cpf;
  cin >> cpf;
  cin.ignore();

  cout << "Data de nascimento: ";
  string dataNascimento;
  cin >> dataNascimento;
  cin.ignore();

  cout << "Gênero (1 - masculino, 2 - feminino, 3 - outro): ";
  int genero;
  while (true)
  {
    try
    {
      cin >> genero;
      if (genero >= 1 && genero <= 3)
      {
        break;
      }
      else
      {
        throw std::invalid_argument("Gênero fora dos previstos. Digite um número válido: ");
      }
    }
    catch (const std::invalid_argument &e)
    {
      cout << e.what() << endl;
    }
  }
  cin.ignore();
  Genero generoEnum = (Genero)genero;

  cout << "...Dados do Endereço..." << endl;

  cout << "Rua: ";
  string rua;
  getline(cin, rua);

  cout << "Bairro: ";
  string bairro;
  getline(cin, bairro);

  cout << "Cidade: ";
  string cidade;
  getline(cin, cidade);

  cout << "CEP: ";
  string cep;
  cin >> cep;
  cin.ignore();

  cout << "Número do imóvel: ";
  int numero;
  cin >> numero;
  cin.ignore();

  Endereco<std::string> endereco_to_add(rua, bairro, cidade, cep, numero);
  Pessoa pessoa_to_create(nome, cpf, dataNascimento, generoEnum, endereco_to_add);
  return pessoa_to_create;
}

/**
 * @brief Represents an employee.
 *
 * This class stores information about an employee, including their ID, salary, department,
 * working hours, and date of entry.
 */
Funcionario criaFuncionario()
{
  cout << "(Dados de funcionario)" << endl;

  cout << "Matrícula: ";
  string matricula;
  cin >> matricula;
  cin.ignore();

  cout << "Salário: ";
  float salario;
  cin >> salario;
  cin.ignore();

  cout << "Departamento: ";
  string departamento;
  getline(cin, departamento);

  cout << "Carga horária: ";
  int cargaHoraria;
  cin >> cargaHoraria;
  cin.ignore();

  cout << "Data de ingresso: ";
  string dataIngresso;
  cin >> dataIngresso;
  cin.ignore();

  Funcionario funcionario_to_create(matricula, salario, departamento, cargaHoraria, dataIngresso);
  return funcionario_to_create;
}

/**
 * @brief Creates a Professor object by gathering information from the user.
 *
 * @return The created Professor object.
 */
Professor criaProfessor()
{
  cout << "-- Cadastro de Professor(a) --" << endl;
  cin.ignore();
  Pessoa pessoa_to_add = criaPessoa();
  Funcionario funcionario_to_add = criaFuncionario();

  cout << "(Dados de prof)" << endl;

  int nivelProfessor;
  while (true)
  {
    cout << "Nível (1 a 8): ";
    cin >> nivelProfessor;
    if (nivelProfessor >= 1 && nivelProfessor <= 8)
    {
      break;
    }
    else
    {
      cout << "Nível fora dos previstos." << endl;
    }
  }
  cin.ignore();
  Nivel nivelProfessorEnum = (Nivel)nivelProfessor;

  cout << "Formação (1 - graduação, 2 - especialização, 3 - mestrado, 4 - doutorado): ";
  int formacaoProfessor;
  while (true)
  {
    cin >> formacaoProfessor;
    if (formacaoProfessor >= 1 && formacaoProfessor <= 4)
    {
      break;
    }
    else
    {
      cout << "Formação fora dos previstos." << endl;
    }
  }
  cin.ignore();
  Formacao formacaoProfessorEnum = (Formacao)formacaoProfessor;

  cout << "Disciplina: ";
  string disciplina;
  getline(cin, disciplina);

  Professor prof_to_create(
      pessoa_to_add.getNome(),
      pessoa_to_add.getCpf(),
      pessoa_to_add.getDataNascimento(),
      pessoa_to_add.getGenero(),
      pessoa_to_add.getEndereco(),
      funcionario_to_add.getMatricula(),
      funcionario_to_add.getSalario(),
      funcionario_to_add.getDepartamento(),
      funcionario_to_add.getCargaHoraria(),
      funcionario_to_add.getDataIngresso(),
      nivelProfessorEnum,
      formacaoProfessorEnum,
      disciplina);
  return prof_to_create;
}

/**
 * @brief Represents a Technical Administrative employee.
 *
 * This class inherits from the Funcionario class and adds additional attributes specific to a Technical Administrative employee.
 */
TecnicoAdm criaTecAdm()
{
  cout << "-- Cadastro de Técnico(a) Administrativo(a) --" << endl;
  cin.ignore();
  Pessoa pessoa_to_add = criaPessoa();
  Funcionario funcionario_to_add = criaFuncionario();

  cout << "(Dados de técnico(a) administrativo(a))" << endl;

  cout << "Adicional de produtividade: ";
  float adicionalProdutividade;
  cin >> adicionalProdutividade;
  cin.ignore();

  cout << "Função desempenhada: ";
  string funcaoDesempenhada;
  cin >> funcaoDesempenhada;
  cin.ignore();

  TecnicoAdm tec_adm_to_create(
      pessoa_to_add.getNome(),
      pessoa_to_add.getCpf(),
      pessoa_to_add.getDataNascimento(),
      pessoa_to_add.getGenero(),
      pessoa_to_add.getEndereco(),
      funcionario_to_add.getMatricula(),
      funcionario_to_add.getSalario(),
      funcionario_to_add.getDepartamento(),
      funcionario_to_add.getCargaHoraria(),
      funcionario_to_add.getDataIngresso(),
      adicionalProdutividade,
      funcaoDesempenhada);
  return tec_adm_to_create;
}

/**
 * @brief Searches for a Professor object in the database based on the provided matricula.
 *
 * @param bancoDao The BancoDao object used to access the database.
 * @return The Professor object found in the database.
 */
Professor buscarProf(BancoDao bancoDao)
{
  cout << "-- Busca de professor(a) --" << endl;
  cout << "Informe a matrícula a buscar: ";
  string matricula;
  cin >> matricula;
  Professor prof_buscado = bancoDao.buscarProfessor(matricula);
  return prof_buscado;
}

/**
 * @brief Searches for a TecnicoAdm object in the database based on the provided matricula.
 *
 * @param bancoDao The BancoDao object used to access the database.
 * @return The TecnicoAdm object found in the database.
 */
TecnicoAdm buscarTecAdm(BancoDao bancoDao)
{
  cout << "-- Busca de técnico(a) administrativo(a) --" << endl;
  cout << "Informe a matrícula a buscar: ";
  string matricula;
  cin >> matricula;
  TecnicoAdm tec_adm_buscado = bancoDao.buscarTecnicoAdm(matricula);
  return tec_adm_buscado;
}

/**
 * Executes the user menu operations.
 * This function displays a menu with different options for the user to choose from.
 * Based on the user's input, it performs various operations such as adding, listing, searching, and deleting records.
 * The function takes a BancoDao object as a parameter to interact with the database.
 * It continues to display the menu until the user chooses to exit the program.
 *
 * @param bancoDao The BancoDao object used to interact with the database.
 */
void executaMenuUser(BancoDao bancoDao)
{
  while (true)
  {
    int userOption;
    cout << endl;
    cout << "==========================" << endl;
    cout << "Usuário: menu de operações" << endl;
    cout << endl;
    cout << " Opção  | Operação  | Registro     " << endl;
    cout << "--------+-----------+--------------" << endl;
    cout << "    1   | cadastrar | professor    " << endl;
    cout << "    2   | cadastrar | tecnico adm  " << endl;
    cout << "--------+-----------+--------------" << endl;
    cout << "    3   | listar    | professor    " << endl;
    cout << "    4   | listar    | tecnico adm  " << endl;
    cout << "--------+-----------+--------------" << endl;
    cout << "    5   | buscar    | professor    " << endl;
    cout << "    6   | buscar    | tecnico adm  " << endl;
    cout << "--------+-----------+--------------" << endl;
    cout << "    7   | deletar   | professor    " << endl;
    cout << "    8   | deletar   | tecnico adm  " << endl;
    cout << "--------+-----------+--------------" << endl;
    cout << "    0   | (sair)    | (do programa)" << endl;
    cout << endl;
    cout << "Escolha a operação: ";
    cin >> userOption;

    try
    {
      if (userOption < 0 || userOption > 8)
      {
        throw std::invalid_argument("Opção inválida. Digite um número de 0 a 8.");
      }
      if (userOption == 1)
      {
        Professor prof_to_add = criaProfessor();
        bancoDao.cadastrarProfessor(prof_to_add);
        bancoDao.salvarArquivoProfessores();
      }
      else if (userOption == 2)
      {
        TecnicoAdm tec_adm_to_add = criaTecAdm();
        bancoDao.cadastrarTecnicoAdm(tec_adm_to_add);
        bancoDao.salvarArquivoTecnicosAdm();
      }
      else if (userOption == 3)
      {
        bancoDao.listarProfessores();
      }
      else if (userOption == 4)
      {
        bancoDao.listarTecnicosAdm();
      }
      else if (userOption == 5)
      {
        Professor prof_buscado = buscarProf(bancoDao);
        if (prof_buscado.getMatricula() == "")
        {
          cout << endl;
          cout << "*** ************ *** ************* ***" << endl;
          cout << "*** Professor(a) não encontrado(a) ***" << endl;
          cout << "*** ************ *** ************* ***" << endl;
        }
        else
        {
          cout << endl;
          cout << "*** ************ ************* ***" << endl;
          cout << "*** Professor(a) encontrado(a) ***" << endl;
          cout << "*** ************ ************* ***" << endl;
          prof_buscado.imprimir();
        }
      }
      else if (userOption == 6)
      {
        TecnicoAdm tec_adm_buscado = buscarTecAdm(bancoDao);
        if (tec_adm_buscado.getMatricula() == "")
        {
          cout << endl;
          cout << "*** ********** *** *** ************* ***" << endl;
          cout << "*** Técnico(a) Adm não encontrado(a) ***" << endl;
          cout << "*** ********** *** *** ************* ***" << endl;
        }
        else
        {
          cout << endl;
          cout << "*** ********** *** ************* ***" << endl;
          cout << "*** Técnico(a) Adm encontrado(a) ***" << endl;
          cout << "*** ********** *** ************* ***" << endl;
          tec_adm_buscado.imprimir();
        }
      }
      else if (userOption == 7)
      {
        Professor prof_buscado = buscarProf(bancoDao);
        if (prof_buscado.getMatricula() == "")
        {
          cout << endl;
          cout << "*** ************ * ******* *** ************* ***" << endl;
          cout << "*** Professor(a) a deletar não encontrado(a) ***" << endl;
          cout << "*** ************ * ******* *** ************* ***" << endl;
        }
        else
        {
          bancoDao.deletarProfessor(prof_buscado.getMatricula());
          bancoDao.salvarArquivoProfessores();
        }
      }
      else if (userOption == 8)
      {
        TecnicoAdm tec_adm_buscado = buscarTecAdm(bancoDao);
        if (tec_adm_buscado.getMatricula() == "")
        {
          cout << endl;
          cout << "*** ********** *** * ******* *** ************* ***" << endl;
          cout << "*** Técnico(a) Adm a deletar não encontrado(a) ***" << endl;
          cout << "*** ********** *** * ******* *** ************* ***" << endl;
        }
        else
        {
          bancoDao.deletarTecnicoAdm(tec_adm_buscado.getMatricula());
          bancoDao.salvarArquivoTecnicosAdm();
        }
      }
      else if (userOption == 0)
      {
        encerraPrograma();
      }
    }
    catch (const std::invalid_argument &e)
    {
      cout << e.what() << " Tente novamente." << endl;
      // Limpar o buffer de entrada para evitar loops infinitos em caso de entrada inválida
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  };
}

/**
 * Executes the main menu of the IMDCorp System.
 * This function displays the system title and calls other functions to read data from files and execute the user menu.
 */
void executaMenu()
{
  cout << "-------------------------" << endl;
  cout << "     IMDCorp System      " << endl;
  cout << "-------------------------" << endl
       << endl;

  BancoDao bancoDao;
  bancoDao.lerArquivoProfessores();
  bancoDao.lerArquivoTecnicosAdm();

  executaMenuUser(bancoDao);
}