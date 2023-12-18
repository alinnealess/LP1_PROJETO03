#include "../../../header/classes/standalone/bancoDao.hpp"
#include "../../../header/classes/aggregated/endereco.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// constructor
/**
 * Constructor for the BancoDao class.
 * Initializes the professores and tecnicosAdm member variables as empty vectors.
 */
BancoDao::BancoDao() {
  this->professores = {};
  this->tecnicosAdm = {};
}

/**
 * Reads the "professores.txt" file and populates the "professores" vector with Professor objects.
 * Each line of the file represents a Professor object, with the following format:
 * [nome] [cpf] [dataNascimento] [genero] [endereco.rua] [endereco.bairro] [endereco.cidade] [endereco.cep] [endereco.numero] [matricula] [salario] [departamento] [cargaHoraria] [dataIngresso] [nivelProfessor] [formacaoProfessor] [disciplina]
 * The file is read line by line, and each line is split into its respective fields to create a Professor object.
 * The created Professor objects are then added to the "professores" vector.
 */
void BancoDao::lerArquivoProfessores() {
  vector<string> txt;
  fstream file;
  file.open("./data/professores.txt", ios::in);
  string lineBuffer;
  while (getline(file, lineBuffer)) {
    txt.push_back(lineBuffer);
  }
  file.close();
  cout << "Arquivo de professores lido!" << endl;
  cout << "Quantidade de linhas: ";
  if (txt.empty()) {
    cout << "0" << endl;
  } else {
    cout << txt.size() << endl;
    for (int i = 0; i < txt.size(); i += 18) {
      Endereco<std::string> endereco(
        txt[i+4],                   // endereco.rua
        txt[i+5],                   // endereco.bairro
        txt[i+6],                   // endereco.cidade
        txt[i+7],                   // endereco.cep
        stoi(txt[i+8])              // endereco.numero
      );

      Professor prof(
        txt[i],                     // nome
        txt[i+1],                   // cpf
        txt[i+2],                   // dataNascimento
        (Genero) stoi(txt[i+3]),    // genero
        endereco,                   // endereco
        txt[i+9],                   // matricula
        stof(txt[i+10]),            // salario
        txt[i+11],                  // departamento
        stoi(txt[i+12]),            // cargaHoraria
        txt[i+13],                  // dataIngresso
        (Nivel) stoi(txt[i+14]),    // nivelProfessor
        (Formacao) stoi(txt[i+15]), // formacaoProfessor
        txt[i+16]                   // disciplina
      );

      this->professores.push_back(prof);
    }
  }
}


/**
 * Reads the file "tecnicosAdm.txt" and populates the vector of TecnicoAdm objects.
 * Each line of the file represents a TecnicoAdm object with its attributes.
 * The file is expected to have the following format:
 * - Line 1: nome
 * - Line 2: cpf
 * - Line 3: dataNascimento
 * - Line 4: genero (0 for male, 1 for female, 2 for other)
 * - Line 5: endereco.rua
 * - Line 6: endereco.bairro
 * - Line 7: endereco.cidade
 * - Line 8: endereco.cep
 * - Line 9: endereco.numero
 * - Line 10: matricula
 * - Line 11: salario
 * - Line 12: departamento
 * - Line 13: cargaHoraria
 * - Line 14: dataIngresso
 * - Line 15: adicionalProdutividade
 * - Line 16: funcaoDesempenhada
 * 
 * After reading the file, the method prints the number of lines read and
 * creates TecnicoAdm objects based on the file content, adding them to the
 * "tecnicosAdm" vector.
 */
void BancoDao::lerArquivoTecnicosAdm() {
  vector<string> txt;
  fstream file;
  file.open("./data/tecnicosAdm.txt", ios::in);
  string lineBuffer;
  while (getline(file, lineBuffer)) {
    txt.push_back(lineBuffer);
  }
  file.close();
  cout << "Arquivo de técnicos adm lido!" << endl;
  cout << "Quantidade de linhas: ";
  if (txt.empty()) {
    cout << "0" << endl;
  } else {
    cout << txt.size() << endl;
    for (int i = 0; i < txt.size(); i += 17) {
      Endereco<std::string> endereco(
        txt[i+4],                   // endereco.rua
        txt[i+5],                   // endereco.bairro
        txt[i+6],                   // endereco.cidade
        txt[i+7],                   // endereco.cep
        stoi(txt[i+8])              // endereco.numero
      );

      TecnicoAdm tecAdm(
        txt[i],                     // nome
        txt[i+1],                   // cpf
        txt[i+2],                   // dataNascimento
        (Genero) stoi(txt[i+3]),    // genero
        endereco,                   // endereco
        txt[i+9],                   // matricula
        stof(txt[i+10]),            // salario
        txt[i+11],                  // departamento
        stoi(txt[i+12]),            // cargaHoraria
        txt[i+13],                  // dataIngresso
        stof(txt[i+14]),            // adicionalProdutividade
        txt[i+15]                   // funcaoDesempenhada
      );

      this->tecnicosAdm.push_back(tecAdm);
    }
  }
}

/**
 * Saves the list of professors to a file.
 * The file is saved in the "./data/professores.txt" path.
 * Each professor's information is written in a specific format.
 * The information includes the professor's name, CPF, date of birth, gender, address, matriculation number,
 * salary, department, workload, date of entry, professor level, professor's education, and assigned discipline.
 */
void BancoDao::salvarArquivoProfessores() {
  fstream file;
  file.open("./data/professores.txt", ios::out);
  for (int i = 0; i < this->professores.size(); i++) {
    file << this->professores[i].getNome() << endl;                     // L01
    file << this->professores[i].getCpf() << endl;                      // L02
    file << this->professores[i].getDataNascimento() << endl;           // L03
    file << this->professores[i].getGenero() << endl;                   // L04
    file << this->professores[i].getEndereco().getRua() << endl;        // L05
    file << this->professores[i].getEndereco().getBairro() << endl;     // L06
    file << this->professores[i].getEndereco().getCidade() << endl;     // L07
    file << this->professores[i].getEndereco().getCep() << endl;        // L08
    file << this->professores[i].getEndereco().getNumero() << endl;     // L09
    file << this->professores[i].getMatricula() << endl;                // L10
    file << this->professores[i].getSalario() << endl;                  // L11
    file << this->professores[i].getDepartamento() << endl;             // L12
    file << this->professores[i].getCargaHoraria() << endl;             // L13
    file << this->professores[i].getDataIngresso() << endl;             // L14
    file << this->professores[i].getNivelProfessor() << endl;           // L15
    file << this->professores[i].getFormacaoProfessor() << endl;        // L16
    file << this->professores[i].getDisciplina() << endl;               // L17
    file << endl;                                                       // L18
  }
  file.close();
  cout << "******* ** *********** ******" << endl;
  cout << "Arquivo de professores salvo!" << endl;
  cout << "******* ** *********** ******" << endl;
}

/**
 * Saves the information of technical administrators to a file.
 * The information includes name, CPF, date of birth, gender, address, matriculation,
 * salary, department, working hours, date of entry, productivity bonus, and job function.
 */
void BancoDao::salvarArquivoTecnicosAdm() {
  fstream file;
  file.open("./data/tecnicosAdm.txt", ios::out);
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    file << this->tecnicosAdm[i].getNome() << endl;                     // L01
    file << this->tecnicosAdm[i].getCpf() << endl;                      // L02
    file << this->tecnicosAdm[i].getDataNascimento() << endl;           // L03
    file << this->tecnicosAdm[i].getGenero() << endl;                   // L04
    file << this->tecnicosAdm[i].getEndereco().getRua() << endl;        // L05
    file << this->tecnicosAdm[i].getEndereco().getBairro() << endl;     // L06
    file << this->tecnicosAdm[i].getEndereco().getCidade() << endl;     // L07
    file << this->tecnicosAdm[i].getEndereco().getCep() << endl;        // L08
    file << this->tecnicosAdm[i].getEndereco().getNumero() << endl;     // L09
    file << this->tecnicosAdm[i].getMatricula() << endl;                // L10
    file << this->tecnicosAdm[i].getSalario() << endl;                  // L11
    file << this->tecnicosAdm[i].getDepartamento() << endl;             // L12
    file << this->tecnicosAdm[i].getCargaHoraria() << endl;             // L13
    file << this->tecnicosAdm[i].getDataIngresso() << endl;             // L14
    file << this->tecnicosAdm[i].getAdicionalProdutividade() << endl;   // L15
    file << this->tecnicosAdm[i].getFuncaoDesempenhada() << endl;       // L16
    file << endl;                                                       // L17
  }
  file.close();
  cout << "******* ** ******** *************** ******" << endl;
  cout << "Arquivo de técnicos administrativos salvo!" << endl;
  cout << "******* ** ******** *************** ******" << endl;
}

/**
 * Checks if a professor with the given matricula exists in the list of professors.
 * @param matricula The matricula of the professor to check.
 * @return True if a professor with the given matricula exists, false otherwise.
 */
bool BancoDao::existeProfessor(string matricula) {
  for (int i = 0; i < this->professores.size(); i++) {
    if (this->professores[i].getMatricula() == matricula) {
      return true;
    }
  }
  return false;  
}

/**
 * Checks if a technician administrator with the given matricula exists in the BancoDao.
 * 
 * @param matricula The matricula of the technician administrator to check.
 * @return True if a technician administrator with the given matricula exists, false otherwise.
 */
bool BancoDao::existeTecnicoAdm(string matricula) {
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    if (this->tecnicosAdm[i].getMatricula() == matricula) {
      return true;
    }
  }
  return false;  
}

/**
 * Cadastro de um professor no banco de dados.
 * Verifica se o professor já está cadastrado antes de adicioná-lo.
 * 
 * @param professor O objeto Professor a ser cadastrado.
 */
void BancoDao::cadastrarProfessor(Professor professor) {
  if(this->existeProfessor(professor.getMatricula())) {
    cout << "*** ********* ** *********** ***" << endl;
    cout << "*** Professor já cadastrado! ***" << endl;
    cout << "*** ********* ** *********** ***" << endl;
  } else {
    this->professores.push_back(professor);
    cout << "*** ********* *********** ***" << endl;
    cout << "*** Professor cadastrado! ***" << endl;
    cout << "*** ********* *********** ***" << endl;
  }
}

/**
 * @brief Registers a administrative technician in the database.
 *
 * Checks if the administrative technician is already registered, and if not,
 * adds them to the list of administrative technicians in the database.
 *
 * @param tecnicoAdm The TecnicoAdm object to be registered.
 */
void BancoDao::cadastrarTecnicoAdm(TecnicoAdm tecnicoAdm) {
  if(this->existeTecnicoAdm(tecnicoAdm.getMatricula())) {
    cout << "*** ******* ************** ** *********** ***" << endl;
    cout << "*** Técnico administrativo já cadastrado! ***" << endl;
    cout << "*** ******* ************** ** *********** ***" << endl;
  } else {
    this->tecnicosAdm.push_back(tecnicoAdm);
    cout << "*** ******* ************** *********** ***" << endl;
    cout << "*** Técnico administrativo cadastrado! ***" << endl;
    cout << "*** ******* ************** *********** ***" << endl;
  }
}

/**
 * Lists all the professors in the database.
 * If there are no professors registered, it displays a message indicating that.
 * Otherwise, it displays a numbered list of professors and calls the imprimirProfessor() function for each professor.
 */
void BancoDao::listarProfessores() {
  if (this->professores.empty()) {
    cout << "*** Não há professores cadastrados! ***" << endl;
  } else {
    cout << "-----------------------------" << endl;
    cout << "   Listagem de Professores   " << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < this->professores.size(); i++) {
      cout << "--------------------" << endl;
      cout << "| Professor nº: " << i+1 << " |" << endl;
      cout << "--------------------" << endl;
      this->professores[i].imprimir();
      cout << endl;
    }
    cout << endl;
  }
}

/**
 * Lists all administrative technicians.
 * If there are no administrative technicians registered, it displays a message indicating that.
 * Otherwise, it displays a list of administrative technicians with their respective details.
 */
void BancoDao::listarTecnicosAdm() {
  if (this->tecnicosAdm.empty()) {
    cout << "*** Não há técnicos administrativos cadastrados! ***" << endl;
  } else {
    cout << "-----------------------------" << endl;
    cout << "    Listagem de Tecs Adm     " << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < this->tecnicosAdm.size(); i++) {
      cout << "---------------------------------" << endl;
      cout << "| Técnico administrativo nº: " << i+1 << " |" << endl;
      cout << "---------------------------------" << endl;
      this->tecnicosAdm[i].imprimir();
      cout << endl;
    }
    cout << endl;
  }
}

/**
 * @brief Searches for a professor with the given matricula in the list of professors.
 * 
 * @param matricula The matricula of the professor to search for.
 * @return The professor object if found, otherwise an empty professor object.
 */
Professor BancoDao::buscarProfessor(string matricula) {
  for (int i = 0; i < this->professores.size(); i++) {
    if (this->professores[i].getMatricula() == matricula) {
      return this->professores[i];
    }
  }
  return Professor();
}

/**
 * @brief Searches for a TecnicoAdm object in the list of tecnicosAdm based on the given matricula.
 * 
 * @param matricula The matricula of the TecnicoAdm to search for.
 * @return The found TecnicoAdm object if it exists, otherwise a default-constructed TecnicoAdm object.
 */
TecnicoAdm BancoDao::buscarTecnicoAdm(string matricula) {
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    if (this->tecnicosAdm[i].getMatricula() == matricula) {
      return this->tecnicosAdm[i];
    }
  }
  return TecnicoAdm();
}

/**
 * Deletes a professor from the list of professors.
 * @param matricula The matricula of the professor to be deleted.
 */
void BancoDao::deletarProfessor(string matricula) {
  for (int i = 0; i < this->professores.size(); i++) {
    if (this->professores[i].getMatricula() == matricula) {
      this->professores.erase(this->professores.begin() + i);
      cout << "*** ********* ********* ***" << endl;
      cout << "*** Professor deletado! ***" << endl;
      cout << "*** ********* ********* ***" << endl;
    }
  }
}

/**
 * Deletes a technical administrative from the list of technical administrators.
 * @param matricula The matricula of the technical administrative to be deleted.
 */
void BancoDao::deletarTecnicoAdm(string matricula) {
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    if (this->tecnicosAdm[i].getMatricula() == matricula) {
      this->tecnicosAdm.erase(this->tecnicosAdm.begin() + i);
      cout << "*** ******* ************** ********* ***" << endl;
      cout << "*** Técnico administrativo deletado! ***" << endl;
      cout << "*** ******* ************** ********* ***" << endl;
    }
  }
}