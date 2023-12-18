#ifndef ENUMS_HPP
#define ENUMS_HPP
#include <string>

enum Formacao {
  GRADUACAO = 1,
  ESPECIALIZACAO,
  MESTRADO,
  DOUTORADO
};
std::string enumFormacaoToString(Formacao formacao);

enum Nivel {
  I = 1,
  II,
  III,
  IV,
  V,
  VI,
  VII,
  VIII
};
std::string enumNivelToString(Nivel nivel);

enum Genero {
  MASCULINO = 1,
  FEMININO,
  OUTRO
};

std::string enumGeneroToString(Genero genero);

#endif
