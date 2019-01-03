// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Declaración del TDA Bolsa de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Bolsa_Letras.h
  * @brief Fichero cabecera del TDA Bolsa_Letras
  *
  */

#ifndef BOLSA_LETRAS
#define BOLSA_LETRAS
#include <unordered_set>
#include <vector>
#include "Letra.h"
#include "Diccionario.h"
using namespace std;

/**
  * @brief T.D.A. Bolsa_Letras
  *
  * Una instancia @e d del tipo de datos abstracto @b Bolsa_Letras es un objeto
  * que representa un conjunto de objetos Letra desordenados, repetidos X veces
  * y generados de forma aleatoria a partir de un Conjunto de Letras.
  *
  *
  * Un ejemplo de su uso:
  * @include src/letras.cpp
  *
  * @author Jose Luis Gallego Peña
  * @date Diciembre 2018
  */

class Bolsa_Letras{
private:
   /**
     * @page repConjunto Rep del TDA Bolsa_Letras
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.bolsa!=0
     * (No tiene sentido una bolsa vacía)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Bolsa_Letras representa al objeto Letra
     *
     *
     * letra1 letra2 ... letraN
     *
     *
     */

   unordered_multiset<char> bolsa; /**< bolsa */
public:
   /**
   @brief Construye una bolsa de letras vacía
   **/
   Bolsa_Letras();

   /**
   @brief Constructor por parámetros, construye una bolsa de letras a partir de un conjunto de letras
   @param C: Conjunto de Letras
   **/
   Bolsa_Letras(Conjunto_Letras & C);

   /**
   @brief Obtiene la bolsa de letras
   @return Bolsa de letras con letras desordenadas
   **/
   unordered_multiset<char> getBolsa();

   /**
   @brief Genera una bolsa de letras aleatoria
   @param n: número de letras a generar
   @return Bolsa de Letras con n letras ordenadas aleatoriamente
   @pre n positivo
   **/
   Bolsa_Letras letrasJuego(int n);

   /**
   @brief Comprueba si todos los caracteres de una palabra están en la bolsa
   @param palabra: palabra a comprobar si es correcta
   @return True si la palabra tiene todos sus caracteres en la bolsa, False en caso contrario
   **/
   bool esCorrecta(string palabra);

   /**
   @brief Obtiene todas las palabras que se pueden construir con las letras de la bolsa (mejores que una puntuación mínima)
   @param D: diccionario donde buscar las palabras para formar
   @param C: conjunto de letras válidas y sus puntuaciones
   @param modo: modo de juego (Puntos (P) o Longitud (L))
   @param puntuacion: puntuación mínima para buscar palabras
   @param mejor: referencia donde guardar la mejor palabra (palabra con mayor puntuación)
   @return Estructura con todas las palabras formadas y la puntuación de cada una
   @pre El modo debe ser P o L
   **/
   pair<Diccionario, vector<int> > Soluciones(Diccionario & D, Conjunto_Letras & C, char modo, int puntuacion, string & mejor);

   /**
     * @brief Iterador de Bolsa_Letras
     *
     * Iterador personalizado para recorrer y acceder a todas las letras de la bolsa
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
        * @page repConjunto Rep del Iterador de Bolsa_Letras
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @i rep del Iterador de Bolsa_Letras representa al objeto Letra
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

      unordered_multiset<char>::iterator it;
   public:
      /**
      @brief Construye un Iterador de Bolsa_Letras
      **/
      iterator();

      /**
      @brief Accede al valor del iterador (Letra de la bolsa)
      @return Letra de la bolsa referenciada por el iterador
      @pre Iterador debe estar entre begin y end (incluidos)
      **/
      char operator *();

      /**
      @brief Incrementa el valor del iterador (siguiente Letra de la bolsa)
      @return Iterador con su valor incrementado en 1
      @pre Iterador no debe superar a end al ejecutarse
      **/
      iterator & operator ++();

      /**
      @brief Compara si dos iteradores referencian la misma bolsa de letras
      @return True si es la misma bolsa, False si no
      **/
      bool operator ==(const iterator & i);

      /**
      @brief Compara si dos iteradores referencian una distinta bolsa de letras
      @return True si es ua bolsa distinta, False si no
      **/
      bool operator !=(const iterator & i);

      friend class Bolsa_Letras;
   };

   /**
   @brief Iterador referenciando el principio de la bolsa de letras
   @return Iterador referenciando el principio de la bolsa de letras
   **/
   iterator begin();

   /**
   @brief Iterador referenciando el final de la bolsa de letras
   @return Iterador referenciando el final de la bolsa de letras
   **/
   iterator end();
};

#endif
