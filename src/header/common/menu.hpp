#ifndef MENU_HPP
#define MENU_HPP
#include "../classes/standalone/bancoDao.hpp"
#include "../classes/base/pessoa.hpp"
#include "../classes/base/funcionario.hpp"
#include "../classes/derived/professor.hpp"
#include "../classes/derived/tecnicoAdm.hpp"

void encerraPrograma();

Pessoa criaPessoa();
Funcionario criaFuncionario();

Professor criaProfessor();
TecnicoAdm criaTecAdm();

Professor buscarProf(BancoDao bancoDao);
TecnicoAdm buscarTecAdm(BancoDao bancoDao);

void executaMenuUser(BancoDao bancoDao);
void executaMenu();

#endif
