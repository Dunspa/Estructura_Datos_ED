// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Declaración del TDA Letra y del TDA Conjunto de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#ifndef LETRA
#define LETRA
#include <fstream>
#include <set>
#include <iostream>
#include "Diccionario.h"
using namespace std;

class Letra{
private:
   char caracter;
   int num_apariciones;
   int puntuacion;
public:
   Letra();
   Letra(char c, int n, int p);
   char getCaracter();
   int getNumApariciones();
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

class Conjunto_Letras{
private:
   set<Letra> conjunto_letras;
public:
   set<Letra> getConjunto();
   int calculaPuntuacion(const string & p, const char modo);
   void Puntuaciones();
   Diccionario Soluciones(int puntuacion);

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

   class iterator{
   private:
      set<Letra>::iterator it;
   public:
      iterator();
      Letra operator *();
      iterator & operator ++();
      bool operator ==(const iterator & i);
      bool operator !=(const iterator & i);
      friend class Conjunto_Letras;
   };

   iterator begin();
   iterator end();
};

#endif
