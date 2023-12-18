#include "../../../header/classes/base/pessoa.hpp"
#include <string>

using namespace std;

// constructor com parâmetros
/**
 * @brief Constructor for the Pessoa class.
 * 
 * @param nome The name of the person.
 * @param cpf The CPF (Cadastro de Pessoas Físicas) of the person.
 * @param dataNascimento The date of birth of the person.
 * @param genero The gender of the person.
 * @param endereco The address of the person.
 */
Pessoa::Pessoa(string nome, string cpf, string dataNascimento, Genero genero, Endereco<std::string> endereco) {
  this->nome = nome;
  this->cpf = cpf;
  this->dataNascimento = dataNascimento;
  this->genero = genero;
  this->endereco = endereco;
}

// constructor sem parâmetros
/**
 * @brief Default constructor for the Pessoa class.
 * Initializes the attributes of the Pessoa object with default values.
 */
Pessoa::Pessoa() {
  this->nome = "";
  this->cpf = "";
  this->dataNascimento = "";
  this->genero = OUTRO;
  this->endereco = Endereco<std::string>();
}
// getters
string Pessoa::getNome() {
  return this->nome;
}
string Pessoa::getCpf() {
  return this->cpf;
}
string Pessoa::getDataNascimento() {
  return this->dataNascimento;
}
Genero Pessoa::getGenero() {
  return this->genero;
}
Endereco<std::string> Pessoa::getEndereco() {
  return this->endereco;
}
// setters
void Pessoa::setNome(string nome) {
  this->nome = nome;
}
void Pessoa::setCpf(string cpf) {
  this->cpf = cpf;
}
void Pessoa::setDataNascimento(string dataNascimento) {
  this->dataNascimento = dataNascimento;
}
void Pessoa::setGenero(Genero genero) {
  this->genero = genero;
}
void Pessoa::setEndereco(Endereco<std::string> endereco) {
  this->endereco = endereco;
}
