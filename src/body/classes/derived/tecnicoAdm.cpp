#include "../../../header/classes/derived/tecnicoAdm.hpp"
#include "../../../header/common/enums.hpp"
#include <string>
#include <iostream>

using namespace std;

// construtor com parâmetros
/**
 * @brief Constructor for the TecnicoAdm class.
 * 
 * @param nome The name of the technician.
 * @param cpf The CPF of the technician.
 * @param dataNascimento The date of birth of the technician.
 * @param genero The gender of the technician.
 * @param endereco The address of the technician.
 * @param matricula The registration number of the technician.
 * @param salario The salary of the technician.
 * @param departamento The department of the technician.
 * @param cargaHoraria The workload of the technician.
 * @param dataIngresso The date of entry of the technician.
 * @param adicionalProdutividade The productivity bonus of the technician.
 * @param funcaoDesempenhada The role performed by the technician.
 */
TecnicoAdm::TecnicoAdm(string nome, string cpf, string dataNascimento, Genero genero, Endereco<std::string> endereco, string matricula, float salario, string departamento, int cargaHoraria, string dataIngresso, float adicionalProdutividade, string funcaoDesempenhada):
  Pessoa(nome, cpf, dataNascimento, genero, endereco),
  Funcionario(matricula, salario, departamento, cargaHoraria, dataIngresso) {
    this->adicionalProdutividade = adicionalProdutividade;
    this->funcaoDesempenhada = funcaoDesempenhada;
}

// construtor sem parâmetros
/**
 * @brief Default constructor for the TecnicoAdm class.
 * 
 * This constructor initializes the TecnicoAdm object with default values.
 * It calls the default constructors of the base classes Pessoa and Funcionario.
 * The adicionalProdutividade is set to 0 and funcaoDesempenhada is set to an empty string.
 */
TecnicoAdm::TecnicoAdm(): Pessoa(), Funcionario() {
    this->adicionalProdutividade = 0;
    this->funcaoDesempenhada = "";
}

// getters
float TecnicoAdm::getAdicionalProdutividade() {
  return this->adicionalProdutividade;
}
string TecnicoAdm::getFuncaoDesempenhada() {
  return this->funcaoDesempenhada;
}
// setters
void TecnicoAdm::setAdicionalProdutividade(float adicionalProdutividade) {
  this->adicionalProdutividade = adicionalProdutividade;
}
void TecnicoAdm::setFuncaoDesempenhada(string funcaoDesempenhada) {
  this->funcaoDesempenhada = funcaoDesempenhada;
}
// methods
/**
 * Prints the information of a TecnicoAdm object.
 */
void TecnicoAdm::imprimir() {
  cout << "Nome              : " << this->getNome() << endl;
  cout << "CPF               : " << this->getCpf() << endl;
  cout << "Data de nascimento: " << this->getDataNascimento() << endl;
  cout << "Gênero            : " << enumGeneroToString(this->getGenero()) << endl;
  cout << "Matrícula         : " << this->getMatricula() << endl;
  cout << "Salário           : " << this->getSalario() << endl;
  cout << "Departamento      : " << this->getDepartamento() << endl;
  cout << "Carga horária     : " << this->getCargaHoraria() << endl;
  cout << "Data de ingresso  : " << this->getDataIngresso() << endl;
  cout << "Adic. de produtiv.: " << this->getAdicionalProdutividade() << endl;
  cout << "Função desemp.    : " << this->getFuncaoDesempenhada() << endl;
  cout << "....[Endereço]....  " << endl;
  this->getEndereco().imprimir();
}
