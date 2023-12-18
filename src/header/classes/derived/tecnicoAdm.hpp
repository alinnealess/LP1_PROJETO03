#ifndef TECNICO_ADM_HPP
#define TECNICO_ADM_HPP
#include <string>
#include "../../common/enums.hpp"
#include "../abstract/printer.hpp"
#include "../aggregated/endereco.hpp"
#include "../base/pessoa.hpp"
#include "../base/funcionario.hpp"

/**
  * @brief The `TecnicoAdm` class represents a administrative technician.
  * 
  * This class inherits from the `Funcionario` and `Pessoa` classes.
  * It contains additional attributes and methods specific to administrative technicians.
  */
class TecnicoAdm: public Funcionario, public Pessoa, public Printer {
  private:
    float adicionalProdutividade = 0.25;
    std::string funcaoDesempenhada;
  public:
    // construtor
    TecnicoAdm(std::string nome, std::string cpf, std::string dataNascimento, Genero genero, Endereco<std::string> endereco, std::string matricula, float salario, std::string departamento, int cargaHoraria, std::string dataIngresso, float adicionalProdutividade, std::string funcaoDesempenhada);
    TecnicoAdm();
    // getters
    float getAdicionalProdutividade();
    std::string getFuncaoDesempenhada();
    // setters
    void setAdicionalProdutividade(float adicionalProdutividade);
    void setFuncaoDesempenhada(std::string funcaoDesempenhada);
    // methods
    void imprimir();
};
#endif