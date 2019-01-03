// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Declaración del TDA Diccionario
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
#include <set>
#include <vector>
#include <iostream>
using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia @e d del tipo de datos abstracto @d Diccionario es un objeto
  * que representa un conjunto de palabras ordenadas, es decir, un diccionario.
  * Está compuesto por un único valor que representa el propio diccionario.
  *
  *
  * Un ejemplo de su uso:
  * @include src/testdiccionario.cpp
  *
  * @author Jose Luis Gallego Peña
  * @date Diciembre 2018
  */

class Diccionario{
private:
   /**
     * @page repConjunto Rep del TDA Diccionario
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.datos!=0
     * (No tiene sentido un diccionario vacío)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Diccionario representa al valor diccionario
     *
     *
     * termino1
     *
     * termino2
     *
     * terminoN
     *
     *
     */

   set<string> datos; /**< datos */
public:
   /**
   @brief Construye un diccionario vacío.
   **/
   Diccionario();

   /**
   @brief Devuelve el numero de palabras en el diccionario
   **/
   int size() const;

   /**
   @brief Obtiene todas las palabras en el diccionario de un longitud dada
   @param longitud: la longitud de las palabras de salida
   @return un vector con las palabras de longitud especifica en el parametro de entrada
   **/
   vector<string> PalabrasLongitud(int longitud);

   /**
   @brief Indica si una palabra está en el diccionario o no
   @param palabra: la palabra que se quiere buscar
   @return true si la palabra esta en el diccionario. False en caso contrario
   **/
   bool Esta(string palabra);

   /**
   @brief Adición de una palabra al diccionario
   @param p palabra a añadir al diccionario
   @return Asigna al objeto implícito diccionario la palabra p
   @pre p debería ser no vacía
   **/
   void setPalabra(const string & p);

   /**
   @brief Lee de un flujo de entrada un diccionario
   @param is:flujo de entrada
   @param D: el objeto donde se realiza la lectura.
   @return el flujo de entrada
   **/
   friend istream & operator>>(istream & is, Diccionario & D);

   /**
   @brief Escribe en un flujo de salida un diccionario
   @param os:flujo de salida
   @param D: el objeto diccionario que se escribe
   @return el flujo de salida
   **/
   friend ostream & operator<<(ostream & os, Diccionario & D);

   /**
     * @brief Iterador de Diccionario
     *
     * Iterador personalizado para recorrer y acceder a las palabras del diccionario.
     *
     *
     * Un ejemplo de su uso:
     * @include src/testdiccionario.cpp
     *
     * @author Jose Luis Gallego Peña
     * @date Diciembre 2018
     */

   class iterator{
   private:
      /**
        * @page repConjunto Rep del Iterador de Diccionario
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @i rep del Iterador de Diccionario representa al valor diccionario
        *
        *
        * iter = termino1
        *
        * iter = termino2
        *
        * iter = terminoN
        *
        *
        */

      set<string>::iterator it;
   public:
      /**
      @brief Construye un Iterador de Diccionario
      **/
      iterator();

      /**
      @brief Accede al valor del iterador (palabra del diccionario)
      @return Palabra del diccionario referenciada por el iterador
      @pre Iterador debe estar entre begin y end (incluidos)
      **/
      string operator *();

      /**
      @brief Incrementa el valor del iterador (siguiente palabra del diccionario)
      @return Iterador con su valor incrementado en 1
      @pre Iterador no debe superar a end al ejecutarse
      **/
      iterator & operator ++();

      /**
      @brief Compara si dos iteradores referencian la misma palabra del diccionario
      @return True si es la misma palabra, False si no
      **/
      bool operator ==(const iterator & i);

      /**
      @brief Compara si dos iteradores referencian una distinta palabra del diccionario
      @return True si es una palabra distinta, False si no
      **/
      bool operator !=(const iterator & i);

      friend class Diccionario;
   };

   /**
   @brief Iterador referenciando el principio del diccionario
   @return Iterador referenciando el principio del diccionario
   **/
   iterator begin();

   /**
   @brief Iterador referenciando el final del diccionario
   @return Iterador referenciando el final del diccionario
   **/
   iterator end();
};

#endif
