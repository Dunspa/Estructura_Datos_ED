// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Declaración del TDA Letra y del TDA Conjunto de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Letra.h
  * @brief Fichero cabecera del TDA Letra y del TDA Conjunto de Letras
  *
  */

#ifndef LETRA
#define LETRA
#include <fstream>
#include <set>
#include <iostream>
#include "Diccionario.h"
using namespace std;

/**
  * @brief T.D.A. Letra
  *
  * Una instancia @e l del tipo de datos abstracto @l Letra es un objeto
  * que representa una caracter de cualquier alfabeto, con un valor que indica
  * cuantas veces se repite este y otro valor que indica su puntuación en el juego.
  *
  *
  * Un ejemplo de su uso:
  * @include src/letras.cpp
  *
  * @author Jose Luis Gallego Peña
  * @date Diciembre 2018
  */

class Letra{
private:
   /**
     * @page repConjunto Rep del TDA Letra
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es:
     * \e rep.caracter!=0
     * \e rep.num_apariciones!=0
     * \e rep.puntuacion!=0
     * (No tiene sentido una letra no existente)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Letra representa al valor
     * Letra: (caracter, número de apariciones, puntuación)
     *
     */

   char caracter; /**< caracter */
   int num_apariciones; /**< num_apariciones */
   int puntuacion; /**< puntuacion */
public:
   /**
   @brief Construye una letra vacía
   **/
   Letra();

   /**
   @brief Constructor por parámetros, construye una letra según valores dados
   @param c: caracter nuevo
   @param n: número de apariciones del carácter
   @param p: puntuación asociada a ese carácter
   **/
   Letra(char c, int n, int p);

   /**
   @brief Obtiene el carácter de la letra
   @return Carácter asociado a la letra
   **/
   char getCaracter();

   /**
   @brief Obtiene el número de apariciones de la letra
   @return Número de apariciones asociado a la letra
   **/
   int getNumApariciones();

   /**
   @brief Obtiene la puntuación de la letra
   @return Puntuación asociada a la letra
   **/
   int getPuntuacion();

   /**
   @brief Lee de un flujo de entrada una letra
   @param is:flujo de entrada
   @param L: el objeto donde se realiza la lectura.
   @return el flujo de entrada
   **/
   friend istream & operator>>(istream & is, Letra & L);

   /**
   @brief Escribe en un flujo de salida una letra
   @param os:flujo de salida
   @param L: el objeto letra que se escribe
   @return el flujo de salida
   **/
   friend ostream & operator<<(ostream & os, Letra & L);

   /**
   @brief Sobrecarga del operador <
   @param L letra a comparar con el objeto implícito
   @return Devuelve true si este objeto es menor que L
   **/
   bool operator<(const Letra & L) const;
};

/**
  * @brief T.D.A. Conjunto_Letras
  *
  * Una instancia @e c del tipo de datos abstracto @c Conjunto_Letras es un objeto
  * que representa una colección de Letras, es decir, una colección de objetos Letra
  * que representan un caracter de cualquier alfabeto, con un valor que indica
  * cuantas veces se repite este y otro valor que indica su puntuación en el juego.
  *
  *
  * Un ejemplo de su uso:
  * @include src/letras.cpp
  *
  * @author Jose Luis Gallego Peña
  * @date Diciembre 2018
  */

class Conjunto_Letras{
private:
   set<Letra> conjunto_letras;
public:
   /**
   @brief Obtiene el conjunto de letras
   @return Set de letras del juego
   **/
   set<Letra> getConjunto();

   /**
   @brief Calcula la puntuación de una letra según el modo de juego
   @param p: palabra a calcular su puntuación
   @param modo: modo de juego (Puntos (P) o Longitud (L))
   @return Puntuación de la palabra
   @pre La palabra debe existir y el modo debe ser P o L
   **/
   int calculaPuntuacion(const string & p, const char modo);

   /**
   @brief Puntuaciones de todas las letras
   @return Muestra por pantalla una lista completa de todas las letras y sus puntuaciones
   **/
   void Puntuaciones();

   /**
   @brief Lee de un flujo de entrada un fichero de conjunto de letras
   @param is:flujo de entrada
   @param C: el objeto donde se realiza la lectura.
   @return el flujo de entrada
   @pre El fichero debe estar formateado correctamente
   **/
   friend istream & operator>>(istream & is, Conjunto_Letras & C);

   /**
   @brief Escribe en un flujo de salida un conjunto de letras con sus frecuencias
   @param os:flujo de salida
   @param C: el objeto conjunto_letras que se escribe
   @return el flujo de salida
   **/
   friend ostream & operator<<(ostream & os, Conjunto_Letras & C);

   /**
     * @brief Iterador de Conjunto_Letras
     *
     * Iterador personalizado para recorrer y acceder a todas las letras del conjunto
     *
     *
     * Un ejemplo de su uso:
     * @include src/letras.cpp
     *
     * @author Jose Luis Gallego Peña
     * @date Diciembre 2018
     */

   class iterator{
   private:
      /**
        * @page repConjunto Rep del Iterador de Conjunto_Letras
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @i rep del Iterador de Conjunto_Letras representa al objeto Letra
        *
        *
        * iter = Letra1: (caracter1, número de apariciones1, puntuación1)
        *
        * iter = Letra2: (caracter2, número de apariciones2, puntuación2)
        *
        * iter = Letra3: (caracter3, número de apariciones3, puntuación3)
        *
        *
        */

      set<Letra>::iterator it;
   public:
      /**
      @brief Construye un Iterador de Conjunto_Letras
      **/
      iterator();

      /**
      @brief Accede al valor del iterador (Letra del conjunto)
      @return Letra del conjunto referenciada por el iterador
      @pre Iterador debe estar entre begin y end (incluidos)
      **/
      Letra operator *();

      /**
      @brief Incrementa el valor del iterador (siguiente Letra del conjunto)
      @return Iterador con su valor incrementado en 1
      @pre Iterador no debe superar a end al ejecutarse
      **/
      iterator & operator ++();

      /**
      @brief Compara si dos iteradores referencian la misma Letra del conjunto
      @return True si es la misma Letra, False si no
      **/
      bool operator ==(const iterator & i);

      /**
      @brief Compara si dos iteradores referencian un distinto conjunto de letras
      @return True si es un conjunto distinto, False si no
      **/
      bool operator !=(const iterator & i);

      friend class Conjunto_Letras;
   };

   /**
   @brief Iterador referenciando el principio del conjunto de letras
   @return Iterador referenciando el principio del conjunto de letras
   **/
   iterator begin();

   /**
   @brief Iterador referenciando el final del conjunto de letras
   @return Iterador referenciando el final del conjunto de letras
   **/
   iterator end();
};

#endif
