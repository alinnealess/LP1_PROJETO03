#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <string>

/**
 * @brief The Funcionario class represents an employee.
 * 
 * This class contains information about an employee, such as their
 * registration number, salary, department, working hours, and date of entry.
 */
class Funcionario {
  private:
    std::string matricula;
    float salario;
    std::string departamento;
    int cargaHoraria;
    std::string dataIngresso;
  public:
    // constructor
    Funcionario(std::string matricula, float salario, std::string departamento, int cargaHoraria, std::string dataIngresso);
    Funcionario();
    // getters
    std::string getMatricula();
    float getSalario();
    std::string getDepartamento();
    int getCargaHoraria();
    std::string getDataIngresso();
    // setters
    void setMatricula(std::string matricula);
    void setSalario(float salario);
    void setDepartamento(std::string departamento);
    void setCargaHoraria(int cargaHoraria);
    void setDataIngresso(std::string dataIngresso);
};

#endif