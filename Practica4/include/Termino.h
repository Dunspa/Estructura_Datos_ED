// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 4. STL e iteradores.
//
// Definición y documentación con Doxygen
// TDA Termino
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <vector>
using namespace std;

   /**
     *  @brief T.D.A. Termino
     *
     * Una instancia @e t del tipo de datos abstracto @t Termino es un objeto
     * que representa una palabra en un diccionario, compuesto por dos valores
     * que representan, respectivamente, una palabra y sus definiciones asociadas.
     *
     * @author Jose Luis Gallego Peña
     * @date Octubre 2018
     */

class Termino{
private:
   /**
     * @page repConjunto Rep del TDA Termino
     *
     * @section invConjunto Invariante de la representación
     *
     * El invariante es \e rep.palabra!=0, rep.definiciones!=0
     * (La palabra no puede estar vacía, y debe tener como mínimo una definición)
     *
     * @section faConjunto Función de abstracción
     *
     * Un objeto válido @e rep del TDA Termino representa al valor
     *
     * palabra;definicion1
     * palabra;definicion2
     * palabra;definicionN
     *
     */

   pair<string, vector<string> > termino; /**< termino */

public:
   typedef vector<string>::iterator iterator;
   typedef vector<string>::const_iterator const_iterator;

   /**
     * @brief Constructor por defecto de la clase.
     * Crea el término vacío, es decir, sin palabra ni definiciones.
     */
   Termino();

   /**
     * @brief Constructor por parámetros
     * @param p palabra del término a construir
     * @param d definiciones del término a construir
     * @return Crea el término palabra con sus definiciones
     * @pre d debe ser una o más
     */
   Termino(const string p, const vector<string> d);

   /**
     * @brief Constructor de copia de la clase
     * @param t.palabra palabra del término a construir
     * @param t.definiciones definiciones del término a construir
     */
   Termino(const Termino & t);

   /**
     * @brief Palabra
     * @return Devuelve la palabra del término
     */
   string getPalabra() const;

   /**
     * @brief Definiciones
     * @return Devuelve el vector de definiciones del término
     */
   vector<string> getDefiniciones() const;

   /**
     * @brief Número de definiciones
     * @return Devuelve el número de definiciones que tiene el término
     */
   int getNumDefiniciones() const;

   /**
     * @brief Asignación de una palabra
     * @param p palabra del término a asignar
     * @return Asigna al objeto implícito la palabra p
     * @pre p debería ser un string no vacío
     */
   void setPalabra(string p);

   /**
     * @brief Adición de una definción
     * @param d definición del término a añadir
     * @return Añade una definición al final del vector de definiciones del término
     * @pre d debería ser un string no vacío
     */
   void aniadir_definicion(const string d);

   /**
     * @brief Asignación de definiciones
     * @param d definiciones del término a asignar
     * @return Asigna al objeto implícito el vector de definiciones d d
     * @pre d debería ser distinto de cero (vector no vacío)
     */
   void setDefiniciones(vector<string> d);

   /**
     * @brief Sobrecarga del operador =
     * @param t término a copiar al objeto implícito
     * @return Devuelve una referencia al objeto implícito (copia del objeto explícito)
     */
   Termino & operator=(const Termino & t);

   /**
     * @brief Sobrecarga del operador ==
     * @param t término a comparar con el objeto implícito
     * @return Devuelve true si este objeto es igual a t
     */
   bool operator==(const Termino & t) const;

   /**
     * @brief Sobrecarga del operador <
     * @param t término a comparar con el objeto implícito
     * @return Devuelve true si este objeto es menor que t
     */
   bool operator<(const Termino & t) const;

   /**
     * @brief Iterador a la primera definición del término
     * @return Devuelve un iterador al principio del vector de definiciones
     */
   Termino::iterator begin();

   /**
     * @brief Iterador a la primera definición del término
     * @return Devuelve un iterador al principio del vector de definiciones
     */
   Termino::const_iterator begin() const;

   /**
     * @brief Iterador a la última definición del término
     * @return Devuelve un iterador al final del vector de definiciones
     */
   Termino::iterator end();

   /**
     * @brief Iterador a la última definición del término
     * @return Devuelve un iterador al final del vector de definiciones
     */
   Termino::const_iterator end() const;

   /**
     * @brief Sobrecarga del operador de extracción de flujo <<
     * @param os flujo de salida
     * @param t término
     * @return Envía el objeto término al flujo
     * @pre os debe ser una salida correcta, ya sea por pantalla o archivo
     */
   friend ostream & operator<<(ostream & os, const Termino & t);

private:
   void CopiaTermino(const Termino &);

};

#endif
