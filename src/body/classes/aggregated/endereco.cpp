#include "../../../header/classes/aggregated/endereco.hpp"
#include <string>
#include <iostream>

using namespace std;

// constructor com parâmetros
/**
 * @brief Constructor for the Endereco class.
 * 
 * @tparam T The type of the street.
 * @param rua The street name.
 * @param bairro The neighborhood name.
 * @param cidade The city name.
 * @param cep The postal code.
 * @param numero The street number.
 */
template <typename T>
Endereco<T>::Endereco(T rua, string bairro, string cidade, string cep, int numero) {
  this->rua =rua;
  this->bairro = bairro;
  this->cidade = cidade;
  this->cep = cep;
  this->numero = numero;
}
// constructor sem parâmetros
template <typename T>
Endereco<T>::Endereco() {
  this->rua = "";
  this->bairro = "";
  this->cidade = "";
  this->cep = "";
  this->numero = 0;
}
// getters
template <typename T>
T Endereco<T>::getRua() {
  return this->rua;
}
template <typename T>
string Endereco<T>::getBairro() {
  return this->bairro;
}
template <typename T>
string Endereco<T>::getCidade() {
  return this->cidade;
}
template <typename T>
string Endereco<T>::getCep() {
  return this->cep;
}
template <typename T>
int Endereco<T>::getNumero() {
  return this->numero;
}
// setters
template <typename T>
void Endereco<T>::setRua(T rua) {
  this->rua = rua;
}
template <typename T>
void Endereco<T>::setBairro(string bairro) {
  this->bairro = bairro;
}
template <typename T>
void Endereco<T>::setCidade(string cidade) {
  this->cidade = cidade;
}
template <typename T>
void Endereco<T>::setCep(string cep) {
  this->cep = cep;
}
template <typename T>
void Endereco<T>::setNumero(int numero) {
  this->numero = numero;
}
// methods
/**
 * @brief Prints the address information.
 * 
 * This function prints the street, neighborhood, city, ZIP code, and number of the address.
 * 
 * @tparam T The type of the address.
 */
template <typename T>
void Endereco<T>::imprimir() {
  cout << "Rua               : " << this->getRua() << endl;
  cout << "Bairro            : " << this->getBairro() << endl;
  cout << "Cidade            : " << this->getCidade() << endl;
  cout << "CEP               : " << this->getCep() << endl;
  cout << "Número            : " << this->getNumero() << endl;
}

/**
 * @brief Explicit instantiation of the template class Endereco with the specified template argument.
 * 
 * This line of code explicitly instantiates the template class Endereco with the template argument
 * std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>.
 * 
 * @tparam T The template argument for the Endereco class.
 */
template class Endereco<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>;