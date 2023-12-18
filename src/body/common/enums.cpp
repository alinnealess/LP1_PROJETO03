#include "../../header/common/enums.hpp"
#include <string>
#include <iostream>

using namespace std;

/**
 * Converts the given Formacao enum value to its corresponding string representation.
 * 
 * @param formacao The Formacao enum value to convert.
 * @return The string representation of the given Formacao value.
 */
string enumFormacaoToString(Formacao formacao) {
  string strFormacao;
  switch (formacao) {
    case GRADUACAO:
      strFormacao = "Graduação";
      break;
    case ESPECIALIZACAO:
      strFormacao = "Especialização";
      break;
    case MESTRADO:
      strFormacao = "Mestrado";
      break;
    case DOUTORADO:
      strFormacao = "Doutorado";
      break;
    default:
      strFormacao = "Formação não prevista";
      break;
  }
  return strFormacao;
}

/**
 * Converts the given Nivel enum value to its corresponding string representation.
 *
 * @param nivel The Nivel enum value to convert.
 * @return The string representation of the Nivel enum value.
 */
string enumNivelToString(Nivel nivel) {
  string strNivel;
  switch (nivel) {
    case I:
      strNivel = "I";
      break;
    case II:
      strNivel = "II";
      break;
    case III:
      strNivel = "III";
      break;
    case IV:
      strNivel = "IV";
      break;
    case V:
      strNivel = "V";
      break;
    case VI:
      strNivel = "VI";
      break;
    case VII:
      strNivel = "VII";
      break;
    case VIII:
      strNivel = "VIII";
      break;
    default:
      strNivel = "Nível não previsto";
      break;
  }
  return strNivel;
}

/**
 * Converts the given Genero enum value to its corresponding string representation.
 * 
 * @param genero The Genero enum value to convert.
 * @return The string representation of the Genero enum value.
 */
string enumGeneroToString(Genero genero) {
  string strGenero;
  switch (genero) {
    case MASCULINO:
      strGenero = "Masculino";
      break;
    case FEMININO:
      strGenero = "Feminino";
      break;
    case OUTRO:
      strGenero = "Outro";
      break;
    default:
      strGenero = "Gênero não previsto";
      break;
  }
  return strGenero;
}