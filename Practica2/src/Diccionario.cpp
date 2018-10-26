// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 2. Abstracción.
//
// Declaración
// TDA Diccionario
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Diccionario::Diccionario(){
   diccionario = 0;
}

Diccionario::Diccionario(const Vector_Dinamico<Termino> d){
   diccionario = d;
}

Diccionario::Diccionario(const Diccionario & d){
   diccionario = d.diccionario;
}

Vector_Dinamico<string> Diccionario::getDefiniciones(string p) const{
   Vector_Dinamico<string> defs;
   bool encontrada = false;

   for (int i = 0 ; i < getNumTerminos() && !encontrada; i++){
      if (diccionario[i].getPalabra() == p){
         defs.resize(diccionario[i].getNumDefiniciones());
         defs = diccionario[i].getDefiniciones();
         encontrada = true;
      }
   } 

   return defs;
}

Vector_Dinamico<Termino> Diccionario::getDiccionario() const{
   return diccionario;
}

int Diccionario::getNumTerminos() const{
   return diccionario.size();
}

void Diccionario::setTermino(const Termino & t){
   diccionario.aniadir(t);
}

void Diccionario::EliminaTermino(const Termino & t){
   diccionario.elimina(t);
   diccionario.resize(diccionario.size() - 1);
}

ostream & operator<<(ostream & os, const Diccionario & d){
   Vector_Dinamico<Termino> dic = d.getDiccionario();

   for (int i = 0 ; i < d.getNumTerminos() ; i++){
      for (int j = 0 ; j < dic[i].getNumDefiniciones() ; j++){
         os << dic[i].getPalabra() << ";" << dic[i].getDefiniciones()[j] << endl;
      }
   }

   return os;
}

istream & operator>>(istream & is, Diccionario & d){
   string str;

   getline(is, str);
   string palabra = str.substr(0, str.find(";"));
   while (!is.eof()){
      string palabra_actual = palabra;
      Termino t;
      t.setPalabra(palabra);

      while(palabra == palabra_actual){
         string definicion = str.substr(str.find(";") + 1);
         t.aniadir_definicion(definicion);

         getline(is, str);
         palabra = str.substr(0, str.find(";"));
      }

      d.setTermino(t);
   }

   return is;
}

Diccionario Diccionario::FiltradoIntervalo(const char inicio, const char fin){
   Diccionario nuevo_diccionario;
   bool encontrado_inicio = false;
   bool llegado_final = false;
   int i;

   for (i = 0 ; i < getNumTerminos() && !encontrado_inicio ; i++){
      if (diccionario[i].getPalabra()[0] == inicio)
         encontrado_inicio = true;
   }

   char f = fin + 1;
   for (int j = i ; i < getNumTerminos() && !llegado_final ; j++){
      if (diccionario[j].getPalabra()[0] == f){
         llegado_final = true;
      }
      else{
         nuevo_diccionario.setTermino(diccionario[j]);
      }
   }

   return nuevo_diccionario;
}

Diccionario Diccionario::FiltradoPalabraClave(const string palabra_clave){
   Diccionario nuevo_diccionario;

   for (int i = 0 ; i < getNumTerminos() ; i++){
      Vector_Dinamico<string> defs = diccionario[i].getDefiniciones();
      Vector_Dinamico<string> d;
      string p = diccionario[i].getPalabra();
      Termino t;
      bool termino_con_clave = false;

      for (int j = 0 ; j < defs.size() ; j++){
         if (defs[j].find(palabra_clave) != string::npos){
            d.aniadir(defs[j]);
            termino_con_clave = true;
         }
      }

      if (termino_con_clave){
         t.setPalabra(p);
         t.setDefiniciones(d);
         nuevo_diccionario.setTermino(t);
      }
   }

   return nuevo_diccionario;
}

void Diccionario::RecuentoDefiniciones(){
   int total_definiciones = 0;
   int maximo_definiciones = 0, num_definiciones;
   Termino mayor_palabra;

   for (int i = 0 ; i < getNumTerminos() ; i++){
      num_definiciones = 0;
      for (int j = 0 ; j < diccionario[i].getNumDefiniciones() ; j++){
         total_definiciones++;
         num_definiciones++;
      }

      if (num_definiciones > maximo_definiciones){
         maximo_definiciones = num_definiciones;
         mayor_palabra = diccionario[i];
      }
   }

   
   cout << "\n--------------Recuento de definiciones--------------\n";
   cout << "El diccionario tiene un total de " << total_definiciones 
        << " definiciones." << endl;
   cout << "La palabra '"  << mayor_palabra.getPalabra() 
        << "' tiene el máximo número de definiciones asociadas (" 
        << maximo_definiciones << ")." << endl;
   cout << "El promedio de definiciones por palabra (" << total_definiciones
        << "/" << getNumTerminos() << ") es de " 
        << (double)total_definiciones/getNumTerminos();  
   cout << endl;   
}