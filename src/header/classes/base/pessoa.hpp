#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
#include "../../common/enums.hpp"
#include "../aggregated/endereco.hpp"

/**
 * @brief The Pessoa class represents a person.
 * 
 * This class contains information about a person, such as their name, CPF, date of birth, gender, and address.
 * It provides methods to get and set these attributes.
 */
class Pessoa {
  private:
    std::string nome = "";
    std::string cpf = "";
    std::string dataNascimento = "";
    Genero genero = MASCULINO;
    Endereco<std::string>  endereco;
  public:
    // constructor
    Pessoa(std::string nome, std::string cpf, std::string dataNascimento, Genero genero, Endereco<std::string>  endereco);
    Pessoa();
    // getters
    std::string getNome();
    std::string getCpf();
    std::string getDataNascimento();
    Genero getGenero();
    Endereco<std::string>  getEndereco();
    // setters
    void setNome(std::string nome);
    void setCpf(std::string cpf);
    void setDataNascimento(std::string dataNascimento);
    void setGenero(Genero genero);
    void setEndereco(Endereco<std::string>  endereco);
};

#endif
