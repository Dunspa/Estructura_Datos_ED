// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Definición del TDA Diccionario
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Diccionario.h"
#include <string>

Diccionario::Diccionario(){}

int Diccionario::size() const{
   return datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
   iterator it;
   vector<string> palabras;

   for (it = begin() ; it != end() ; ++it){
      string p = (*it);

      if (p.length() == longitud){
         palabras.push_back(p);
      }
   }

   return palabras;
}

bool Diccionario::Esta(string palabra){
   bool esta = false;
   iterator it;

   for (it = begin() ; it != end() && !esta ; ++it){
      string p = (*it);

      if (p == palabra){
         esta = true;
      }
   }

   return esta;
}

void Diccionario::setPalabra(const string & p){
   datos.insert(p);
}

istream & operator>>(istream & is, Diccionario & D){
   string p;

   getline(is, p);
   while (!is.eof()){
      D.setPalabra(p);
      getline(is, p);
   }

   return is;
}

ostream & operator<<(ostream & os, Diccionario & D){
   Diccionario::iterator it;

   for (it = D.begin() ; it != D.end() ; ++it){
      os << (*it) << endl;
   }

   return os;
}

Diccionario::iterator::iterator(){}

string Diccionario::iterator::operator*(){
   return (*it);
}

Diccionario::iterator & Diccionario::iterator::operator++(){
   ++it;

   return *this;
}

bool Diccionario::iterator::operator==(const Diccionario::iterator & i){
   return ((*this).it == i.it);
}

bool Diccionario::iterator::operator!=(const Diccionario::iterator & i){
   return !((*this) == i);
}

Diccionario::iterator Diccionario::begin(){
   iterator iter;
   iter.it = datos.begin();

   return iter;
}

Diccionario::iterator Diccionario::end(){
   iterator iter;
   iter.it = datos.end();

   return iter;
}
