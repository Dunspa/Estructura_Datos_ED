// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Definición
// TDA Cola con máximo (Usando vector dinámico)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Cola_max_vd.h
  * @brief Fichero cabecera del TDA Cola con máximo (usando vector dinámico)
  *
  */

#ifndef COLA_MAX_VD
#define COLA_MAX_VD

#include <vector>
using namespace std;

/**
  *  @brief T.D.A. Cola con máximo (usando vector dinámico)
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
     * @page repConjunto Rep del TDA Cola con máximo (usando vector dinámico)
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.Cola_max!=0
     * (No tiene sentido una cola vacía)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Cola con máximo representa al valor cola_max,
     * compuesto por dos valores: dato y máximo.
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

   vector <pair<T, T>> cola_max; /**< cola_max */
public:
   /**
     * @brief frente
     * @pre Debe haber al menos un valor en la cola
     * @return Devuelve el dato en el frente de la cola (primer dato)
     */
   T frente() const;

   /**
     * @brief maximo
     * @pre Debe haber al menos un valor en la cola
     * @return Devuelve el máximo valor de la cola (se encuentra en el frente siempre)
     */
   T maximo() const;

   /**
     * @brief num_elementos
     * @return Devuelve el número de elementos que contiene la cola
     */
   int num_elementos() const;

   /**
     * @brief vacia
     * @return Devuelve true si la cola está vacía (no tiene ningún dato)
     */
   bool vacia() const;

   /**
     * @brief quitar
     * @pre Debe haber al menos un valor en la cola
     * @return Modifica la cola eliminando el frente (su dato y maximo)
     */
   void quitar();

   /**
     * @brief poner
     * @param elemento a añadir al final de la cola
     * @return Modifica la cola añadiendo el nuevo dato y modificando el máximo de esta
     */
   void poner(const T elemento);
};

#include "Cola_max_vd.cpp"

#endif
