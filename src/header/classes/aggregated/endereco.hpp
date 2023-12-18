#ifndef ENDERECO_HPP
#define ENDERECO_HPP
#include <string>
#include "../abstract/printer.hpp"

/**
 * @brief A class representing an address.
 * 
 * This class stores information about an address, including the street, neighborhood, city, postal code, and house number.
 * It inherits from the Printer class.
 * 
 * @tparam T The type of the street.
 */
template <typename T>
class Endereco: public Printer {
  private:
    T rua;
    std::string bairro;
    std::string cidade;
    std::string cep;
    int numero;
  public:
    // constructor
    Endereco(T rua, std::string bairro, std::string cidade, std::string cep, int numero);
    Endereco();
    // getters
    T getRua();
    std::string getBairro();
    std::string getCidade();
    std::string getCep();
    int getNumero();
    // setters
    void setRua(T rua);
    void setBairro(std::string bairro);
    void setCidade(std::string cidade);
    void setCep(std::string cep);
    void setNumero(int numero);
    // methods
    void imprimir();
};

#endif