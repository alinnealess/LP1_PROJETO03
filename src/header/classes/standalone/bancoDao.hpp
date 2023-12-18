#ifndef BANCO_DAO_HPP
#define BANCO_DAO_HPP
#include <vector>
#include "../derived/professor.hpp"
#include "../derived/tecnicoAdm.hpp"

/**
 * @brief The BancoDao class represents a data access object for managing professors and administrative technicians in a bank.
 * 
 * This class provides methods for reading and saving data from/to files, checking the existence of professors and technicians,
 * registering new professors and technicians, listing all professors and technicians, searching for a specific professor or technician,
 * and deleting professors and technicians.
 */
class BancoDao {
  private:
    std::vector<Professor> professores;
    std::vector<TecnicoAdm> tecnicosAdm;
  public:
    BancoDao();
    void lerArquivoProfessores();
    void salvarArquivoProfessores();

    void lerArquivoTecnicosAdm();
    void salvarArquivoTecnicosAdm();

    bool existeProfessor(std::string matricula);
    bool existeTecnicoAdm(std::string matricula);

    void cadastrarProfessor(Professor professor);
    void cadastrarTecnicoAdm(TecnicoAdm tecnicoAdm);

    void listarProfessores();
    void listarTecnicosAdm();

    Professor buscarProfessor(std::string matricula);
    TecnicoAdm buscarTecnicoAdm(std::string matricula);

    void deletarProfessor(std::string matricula);
    void deletarTecnicoAdm(std::string matricula);
};
#endif