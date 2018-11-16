// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Definición
// TDA Cola con máximo (Usando Pila_max.h y pila de la STL)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Cola_max_vd.h
  * @brief Fichero cabecera del TDA Cola con máximo (usando Pila_max.h y pila de la STL)
  *
  */

#ifndef COLA_MAX_PILA
#define COLA_MAX_PILA

#include <stack>
#include "Pila_max.h"
using namespace std;

/**
  *  @brief T.D.A. Cola con máximo (usando Pila_max.h y pila de la STL)
  *
  * Una instancia @e d del tipo de datos abstracto @d Cola con máximo es un objeto
  * que representa una estructura de datos cola (tipo FIFO).
  * Está compuesto por un único valor que representa la propia cola.
  *
  *
  *
  * @author Jose Luis Gallego Peña
  * @date Noviembre 2018
  */

template <class T>
class Cola_max{
private:
   /**
     * @page repConjunto Rep del TDA Cola con máximo (usando Pila_max.h y pila de la STL)
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.Cola_max!=0
     * (No tiene sentido una cola vacía)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Cola con máximo representa al valor cola_max mediante
     * dos pilas: una para inserciones y otra para consultas, que juntas componen la cola.
     * Está compuesta por dos valores: dato y máximo.
     * Ejemplo:
     *
     *
     * cola_max:
     * dato | maximo
     *     FIN
     * 2    |      2
     * 1    |      2
     * 4    |      4
     * 3    |      4
     *   PRINCIPIO
     *
     */

   Pila_max<T> inserciones; /**< inserciones */
   Pila_max<T> consultas; /**< consultas */
public:
   /**
     * @brief frente
     * @pre Debe haber al menos un valor en la cola
     * @return Devuelve el dato en el frente de la cola (primer dato)
     */
   T frente();

   /**
     * @brief maximo
     * @pre Debe haber al menos un valor en la cola
     * @return Devuelve el máximo valor de la cola (se encuentra en una de las dos pilas que no esté vacía
     * o en el mayor valor de las dos)
     */
   T maximo();

   /**
     * @brief num_elementos
     * @return Devuelve el número de elementos que contiene la cola
     */
   int num_elementos();

   /**
     * @brief vacia
     * @return Devuelve true si la cola está vacía (no tiene ningún dato en ninguna de las dos pilas)
     */
   bool vacia();

   /**
     * @brief quitar
     * @pre Debe haber al menos un valor en la cola
     * @return Modifica la cola eliminando el frente (su dato y maximo) y modificando el máximo
     */
   void quitar();

   /**
     * @brief poner
     * @param elemento a añadir al final de la cola
     * @return Modifica la cola añadiendo el nuevo dato y modificando el máximo
     */
   void poner(const T elemento);
};

#include "Cola_max_pila.cpp"

#endif
