// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 4. STL e iteradores.
//
// Declaración
// TDA Diccionario
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Diccionario.h"
#include "Termino.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Diccionario::Diccionario(){}

Diccionario::Diccionario(const set<Termino> d){
   diccionario = d;
}

Diccionario::Diccionario(const Diccionario & d){
   diccionario = d.diccionario;
}

vector<string> Diccionario::getDefiniciones(string p) const{
   vector<string> defs;
   Diccionario::iterator it;
   bool encontrada = false;

   for (it = diccionario.begin() ; it != diccionario.end() && !encontrada; ++it){
      if ((*it).getPalabra() == p){
         defs = (*it).getDefiniciones();
         encontrada = true;
      }
   }

   return defs;
}

set<Termino> Diccionario::getDiccionario() const{
   return diccionario;
}

int Diccionario::getNumTerminos() const{
   return diccionario.size();
}

void Diccionario::setTermino(const Termino & t){
   diccionario.insert(t);
}

void Diccionario::EliminaTermino(const Termino & t){
   diccionario.erase(t);
}

Diccionario Diccionario::FiltradoIntervalo(const char inicio, const char fin){
   Diccionario nuevo_diccionario;
   Diccionario::iterator it;
   bool encontrado_inicio = false;
   bool llegado_final = false;
   int i;

   for (it = diccionario.begin() ; it != diccionario.end() && !encontrado_inicio ; ++it){
      if ((*it).getPalabra()[0] == inicio)
         encontrado_inicio = true;
   }

   char f = fin + 1;
   for (it ; it != diccionario.end() && !llegado_final ; ++it){
      if ((*it).getPalabra()[0] == f){
         llegado_final = true;
      }
      else{
         nuevo_diccionario.setTermino(*it);
      }
   }

   return nuevo_diccionario;
}

Diccionario Diccionario::FiltradoPalabraClave(const string palabra_clave){
   Diccionario nuevo_diccionario;
   Diccionario::iterator it;

   for (it = diccionario.begin() ; it != diccionario.end() ; ++it){
      vector<string> defs = (*it).getDefiniciones();
      vector<string> d;
      string p = (*it).getPalabra();
      Termino t;
      bool termino_con_clave = false;

      vector<string>::iterator i;
      for (i = defs.begin() ; i != defs.end() ; ++i){
         if ((*i).find(palabra_clave) != string::npos){
            d.push_back(*i);
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
   int maximo_definiciones = 0, num_definiciones = 0;
   Termino mayor_palabra;
   Diccionario::iterator it;

   for (it = diccionario.begin() ; it != diccionario.end() ; ++it){
      num_definiciones = (*it).getNumDefiniciones();
      total_definiciones += num_definiciones;

      if (num_definiciones > maximo_definiciones){
         maximo_definiciones = num_definiciones;
         mayor_palabra = (*it);
      }
   }


   cout << endl << "--------------Recuento de definiciones--------------" << endl;
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

Diccionario::iterator Diccionario::begin(){
   return diccionario.begin();
}

Diccionario::const_iterator Diccionario::begin() const{
   return diccionario.begin();
}

Diccionario::iterator Diccionario::end(){
   return diccionario.end();
}

Diccionario::const_iterator Diccionario::end() const{
   return diccionario.end();
}

ostream & operator<<(ostream & os, const Diccionario & d){
   Diccionario::const_iterator it;

   for (it = d.begin() ; it != d.end() ; ++it){
      os << (*it);
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
