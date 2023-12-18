#include "../../../header/classes/derived/professor.hpp"
#include "../../../header/common/enums.hpp"
#include <string>
#include <iostream>

using namespace std;

// constructor com parâmetros
/**
 * @brief Constructor for the Professor class.
 * 
 * @param nome The name of the professor.
 * @param cpf The CPF of the professor.
 * @param dataNascimento The date of birth of the professor.
 * @param genero The gender of the professor.
 * @param endereco The address of the professor.
 * @param matricula The registration number of the professor.
 * @param salario The salary of the professor.
 * @param departamento The department of the professor.
 * @param cargaHoraria The workload of the professor.
 * @param dataIngresso The date of entry of the professor.
 * @param nivelProfessor The level of the professor.
 * @param formacaoProfessor The education level of the professor.
 * @param disciplina The discipline taught by the professor.
 */
Professor::Professor(string nome, string cpf, string dataNascimento, Genero genero, Endereco<std::string> endereco, string matricula, float salario, string departamento, int cargaHoraria, string dataIngresso, Nivel nivelProfessor, Formacao formacaoProfessor, string disciplina):
  Pessoa(nome, cpf, dataNascimento, genero, endereco),
  Funcionario(matricula, salario, departamento, cargaHoraria, dataIngresso) {
    this->nivelProfessor = nivelProfessor;
    this->formacaoProfessor = formacaoProfessor;
    this->disciplina = disciplina;
}

// constructor sem parâmetros
/**
 * @brief Default constructor for the Professor class.
 * 
 * This constructor initializes a Professor object with default values for its member variables.
 * It calls the default constructors of the base classes Pessoa and Funcionario.
 * The nivelProfessor is set to I, formacaoProfessor is set to GRADUACAO, and disciplina is set to an empty string.
 */
Professor::Professor(): Pessoa(), Funcionario() {
  this->nivelProfessor = I;
  this->formacaoProfessor = GRADUACAO;
  this->disciplina = "";
}

// getters
Nivel Professor::getNivelProfessor() {
  return this->nivelProfessor;
}
Formacao Professor::getFormacaoProfessor() {
  return this->formacaoProfessor;
}
string Professor::getDisciplina() {
  return this->disciplina;
}
// setters
void Professor::setNivelProfessor(Nivel nivelProfessor) {
  this->nivelProfessor = nivelProfessor;
}
void Professor::setFormacaoProfessor(Formacao formacaoProfessor) {
  this->formacaoProfessor = formacaoProfessor;
}
void Professor::setDisciplina(string disciplina) {
  this->disciplina = disciplina;
}

// methods
/**
 * Prints the details of a Professor object.
 * Prints the name, CPF, date of birth, gender, registration number, salary, department,
 * workload, date of entry, level, education, and discipline of the Professor.
 * Also prints the address of the Professor.
 */
void Professor::imprimir() {
  cout << "Nome              : " << this->getNome() << endl;
  cout << "CPF               : " << this->getCpf() << endl;
  cout << "Data de nascimento: " << this->getDataNascimento() << endl;
  cout << "Gênero            : " << enumGeneroToString(this->getGenero()) << endl;
  cout << "Matrícula         : " << this->getMatricula() << endl;
  cout << "Salário           : " << this->getSalario() << endl;
  cout << "Departamento      : " << this->getDepartamento() << endl;
  cout << "Carga horária     : " << this->getCargaHoraria() << endl;
  cout << "Data de ingresso  : " << this->getDataIngresso() << endl;
  cout << "Nível             : " << enumNivelToString(this->getNivelProfessor()) << endl;
  cout << "Formação          : " << enumFormacaoToString(this->getFormacaoProfessor()) << endl;
  cout << "Disciplina        : " << this->getDisciplina() << endl;
  cout << "....[Endereço]....  " << endl;
  this->getEndereco().imprimir();
}