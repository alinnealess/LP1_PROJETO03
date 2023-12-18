#include "../../../header/classes/base/funcionario.hpp"
#include <string>

using namespace std;

// constructor com parâmetros
/**
 * @brief Constructor for the Funcionario class.
 * 
 * @param matricula The employee's registration number.
 * @param salario The employee's salary.
 * @param departamento The employee's department.
 * @param cargaHoraria The employee's workload.
 * @param dataIngresso The employee's admission date.
 */
Funcionario::Funcionario(string matricula, float salario, string departamento, int cargaHoraria, string dataIngresso) {
  this->matricula = matricula;
  this->salario = salario;
  this->departamento = departamento;
  this->cargaHoraria = cargaHoraria;
  this->dataIngresso = dataIngresso;
}
// constructor sem parâmetros
/**
 * @brief Default constructor for the Funcionario class.
 * Initializes the member variables with default values.
 */
Funcionario::Funcionario() {
  this->matricula = "";
  this->salario = 0;
  this->departamento = "";
  this->cargaHoraria = 0;
  this->dataIngresso = "";
}
// getters
string Funcionario::getMatricula() {
  return this->matricula;
}
float Funcionario::getSalario() {
  return this->salario;
}
string Funcionario::getDepartamento() {
  return this->departamento;
}
int Funcionario::getCargaHoraria() {
  return this->cargaHoraria;
}
string Funcionario::getDataIngresso() {
  return this->dataIngresso;
}
// setters
void Funcionario::setMatricula(string matricula) {
  this->matricula = matricula;
}
void Funcionario::setSalario(float salario) {
  this->salario = salario;
}
void Funcionario::setDepartamento(string departamento) {
  this->departamento = departamento;
}
void Funcionario::setCargaHoraria(int cargaHoraria) {
  this->cargaHoraria = cargaHoraria;
}
void Funcionario::setDataIngresso(string dataIngresso) {
  this->dataIngresso = dataIngresso;
}