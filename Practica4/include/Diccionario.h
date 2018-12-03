// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 4. STL e iteradores.
//
// Definición y documentación con Doxygen
// TDA Diccionario
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef DICCIONARIO
#define DICCIONARIO

#include "Termino.h"
#include <set>
#include <iostream>
using namespace std;

   /**
     *  @brief T.D.A. Diccionario
     *
     * Una instancia @e d del tipo de datos abstracto @d Diccionario es un objeto
     * que representa un conjunto de palabras ordenadas, es decir, un diccionario.
     * Está compuesto por un único valor que representa el propio diccionario.
     *
     *
     * Un ejemplo de su uso:
     * @include pruebadiccionario.cpp
     *
     * @author Jose Luis Gallego Peña
     * @date Octubre 2018
     */

class Diccionario{
private:
   /**
     * @page repConjunto Rep del TDA Diccionario
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.diccionario!=0
     * (No tiene sentido un diccionario vacío)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Diccionario representa al valor diccionario
     *
     *
     * termino1:
     *
     * palabra;definicion1
     *
     * palabra;definicion2
     *
     * palabra;definicionN
     *
     * terminoN:
     *
     * palabra;definicion1
     *
     * palabra;definicion2
     *
     * palabra;definicionN
     *
     */

   set<Termino> diccionario; /**< diccionario */

public:
   typedef set<Termino>::iterator iterator;
   typedef set<Termino>::const_iterator const_iterator;

   /**
     * @brief Constructor por defecto de la clase.
     * Crea el diccionario vacío, es decir, sin términos.
     */
   Diccionario();

   /**
     * @brief Constructor por parámetros
     * @param d set de términos del diccionario a construir
     * @return Crea el diccionario con sus términos
     * @pre d debería no estar vacío
     */
   Diccionario(const set<Termino> d);

   /**
     * @brief Constructor de copia de la clase
     * @param d.diccionario diccionario del nuevo diccionario a construir
     */
   Diccionario(const Diccionario & d);

   /**
     * @brief Definiciones
     * @param p palabra del término a obtener sus definiciones
     * @return Devuelve las definiciones asociadas a una palabra
     */
   vector<string> getDefiniciones(string p) const;

   /**
     * @brief Diccionario
     * @return Devuelve un set de términos con todos los términos del diccionario
     */
   set<Termino> getDiccionario() const;

   /**
     * @brief NumTerminos
     * @return Devuelve el número de términos que tiene el diccionario
     */
   int getNumTerminos() const;

   /**
     * @brief Adición de un término al final del diccionario
     * @param t término a añadir al diccionario
     * @return Asigna al objeto implícito diccionario el término t
     * @pre t debería ser no vacío
     */
   void setTermino(const Termino & t);

   /**
     * @brief Elimina un término del diccionario
     * @param t término a eliminar del diccionario
     * @return Elimina en el objeto implícito diccionario el término t
     * @pre t debería existir
     */
   void EliminaTermino(const Termino & t);

   /**
     * @brief Sobrecarga del operador =
     * @param d diccionario a copiar al objeto implícito
     * @return Devuelve una referencia al objeto implícito (copia del objeto explícito)
     */
   Diccionario & operator=(const Diccionario & d);

   /**
     * @brief Filtrado por intervalo
     * @param caracter_inicio principio del intervalo
     * @param caracter_fin fin del intervalo
     * @return Subdiccionario que incluye únicamente los términos cuya palabra
     * asociada está en el intervalo especificado.
     * @pre caracter_inicio y caracter_fin deben estar entre 'a' y 'z'
     */
   Diccionario FiltradoIntervalo(const char caracter_inicio, const char caracter_fin);

   /**
     * @brief Filtrado por palabra clave
     * @param palabra_clave palabra buscada en las definiciones
     * @return Subdiccionario que incluye únicamente las palabras en cuya definición
     * asociada aparezca la palabra clave. Si una palabra tiene varias definiciones,
     * solo se devuelven como resultado del filtrado aquellas definiciones relacionadas
     * con la palabra clave.
     */
   Diccionario FiltradoPalabraClave(const string palabra_clave);

   /**
     * @brief Recuento de definiciones
     * @return Obtiene el número total de definiciones, el máximo de definiciones
     * asociadas a una única palabra y el promedio de definiciones por palabra
     * del objeto implícito diccionario.
     */
   void RecuentoDefiniciones();

   /**
     * @brief Sobrecarga del operador de extracción de flujo <<
     * @param os flujo de salida
     * @param d diccionario del que se obtienen los términos
     * @return Muestra en la salida especificada os el contenido de un diccionario d
     * @pre os debe ser una salida correcta, ya sea por pantalla o archivo
     */
   friend ostream & operator<<(ostream & os, const Diccionario & d);

   /**
     * @brief Sobrecarga del operador de inserción de flujo >>
     * Crea un diccionario a partir de los términos en un archivo de texto plano
     * @param is flujo de entrada
     * @param d diccionario que se crea
     * @return Asigna al objeto d diccionario los términos del archivo de texto
     * @pre is debe ser un archivo de texto plano con un formato correcto
     */
   friend istream & operator>>(istream & is, Diccionario & d);

   /**
     * @brief Iterador al primer término del diccionario
     * @return Devuelve un iterador al principio del diccionario
     */
   Diccionario::iterator begin();

   /**
     * @brief Iterador al primer término del diccionario
     * @return Devuelve un iterador al principio del diccionario
     */
   Diccionario::const_iterator begin() const;

   /**
     * @brief Iterador al último término del diccionario
     * @return Devuelve un iterador al final del diccionario
     */
   Diccionario::iterator end();

   /**
     * @brief Iterador al último término del diccionario
     * @return Devuelve un iterador al final del diccionario
     */
   Diccionario::const_iterator end() const;

};

#endif
