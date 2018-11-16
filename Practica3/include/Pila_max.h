// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Definición
// TDA Pila con máximo (Usando pila de la STL)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Pila_max.h
  * @brief Fichero cabecera del TDA Pila con máximo
  *
  */

#ifndef PILA_MAX
#define PILA_MAX

#include <stack>
using namespace std;

/**
  *  @brief T.D.A. Pila con máximo
  *
  * Una instancia @e d del tipo de datos abstracto @d Pila con máximo es un objeto
  * que representa una estructura de datos pila (tipo LIFO).
  * Está compuesto por un único valor que representa la propia pila.
  *
  *
  *
  * @author Jose Luis Gallego Peña
  * @date Noviembre 2018
  */

template <class T>
class Pila_max{
private:
   /**
     * @page repConjunto Rep del TDA Pila con máximo
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.Pila_max!=0
     * (No tiene sentido una pila vacía)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Pila con máximo representa al valor pila_max,
     * compuesto por dos valores: dato y máximo.
     * Ejemplo:
     *
     *
     * pila_max:
     * dato | maximo
     *     TOPE
     * 2    |      4
     * 1    |      4
     * 4    |      4
     * 3    |      3
     *
     */

   stack <pair<T, T>> pila_max; /**< pila_max */
public:
   /**
     * @brief tope
     * @pre Debe haber al menos un valor en la pila
     * @return Devuelve el dato en el tope de la pila (primer dato)
     */
   T tope();

   /**
     * @brief maximo
     * @pre Debe haber al menos un valor en la pila
     * @return Devuelve el máximo valor de la pila (se encuentra en el tope siempre)
     */
   T maximo();

   /**
     * @brief num_elementos
     * @return Devuelve el número de elementos que contiene la pila
     */
   int num_elementos();

   /**
     * @brief vacia
     * @return Devuelve true si la pila está vacía (no tiene ningún dato)
     */
   bool vacia();

   /**
     * @brief quitar
     * @pre Debe haber al menos un valor en la pila
     * @return Modifica la pila eliminando el tope (su dato y maximo)
     */
   void quitar();

   /**
     * @brief poner
     * @param elemento a añadir en el tope de la pila
     * @return Modifica la pila añadiendo el nuevo dato y modificando el máximo de esta
     */
   void poner(const T elemento);
};

#include "Pila_max.cpp"

#endif
