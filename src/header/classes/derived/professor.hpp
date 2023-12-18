#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include <string>
#include "../../common/enums.hpp"
#include "../abstract/printer.hpp"
#include "../aggregated/endereco.hpp"
#include "../base/pessoa.hpp"
#include "../base/funcionario.hpp"

/**
 * @brief The Professor class represents a professor, which is a derived class of Funcionario and Pessoa.
 * 
 * This class contains information about the professor's level, education, discipline, and provides methods to access and modify this information.
 */
class Professor: public Funcionario, public Pessoa, public Printer {
  private:
    Nivel nivelProfessor = I;
    Formacao formacaoProfessor = GRADUACAO;
    std::string disciplina;
  public:
    // constructor
    Professor(std::string nome, std::string cpf, std::string dataNascimento, Genero genero, Endereco<std::string> endereco, std::string matricula, float salario, std::string departamento, int cargaHoraria, std::string dataIngresso, Nivel nivelProfessor, Formacao formacaoProfessor, std::string disciplina);
    Professor();
    // getters
    Nivel getNivelProfessor();
    Formacao getFormacaoProfessor();
    std::string getDisciplina();
    // setters
    void setNivelProfessor(Nivel nivelProfessor);
    void setFormacaoProfessor(Formacao formacaoProfessor);
    void setDisciplina(std::string disciplina);
    // methods
    void imprimir();
};
#endif