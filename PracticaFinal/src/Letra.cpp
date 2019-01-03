// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Definición del TDA Letra y del TDA Conjunto de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Letra.h"

Letra::Letra(){}

Letra::Letra(char c, int n, int p){
   caracter = c;
   num_apariciones = n;
   puntuacion = p;
}

char Letra::getCaracter(){
   return caracter;
}

int Letra::getNumApariciones(){
   return num_apariciones;
}

int Letra::getPuntuacion(){
   return puntuacion;
}

istream & operator>>(istream & is, Letra & L){
   char c;
   int n, p;

   is >> c;
   is >> n;
   is >> p;
   L.caracter = c;
   L.num_apariciones = n;
   L.puntuacion = p;

   return is;
}

ostream & operator<<(ostream & os, Letra & L){
   os << L.caracter << " " << L.num_apariciones << " " << L.puntuacion << endl;

   return os;
}

bool Letra::operator<(const Letra & L) const{
   return ((*this).caracter < L.caracter);
}

set<Letra> Conjunto_Letras::getConjunto(){
   return conjunto_letras;
}

int Conjunto_Letras::calculaPuntuacion(const string & p, const char modo){
   int puntuacion = 0;

   if (modo == 'L'){
      puntuacion = p.length();
   }
   else if (modo == 'P'){
      iterator it;

      for (int i = 0 ; i < p.length() ; i++){
         char c = p[i];

         bool encontrado = false;
         for (it = begin() ; it != end() && !encontrado ; ++it){
            if (tolower((*it).getCaracter()) == c){
               puntuacion += (*it).getPuntuacion();
               encontrado = true;
            }
         }
      }
   }

   return puntuacion;
}

void Conjunto_Letras::Puntuaciones(){
   iterator it;
   for (it = begin() ; it != end() ; ++it){
      cout << (*it).getCaracter() << " " << (*it).getPuntuacion() << endl;
   }
}

istream & operator>>(istream & is, Conjunto_Letras & C){
   // Ignorar primera línea
   string str;
   getline(is, str);

   while (!is.eof()){
      Letra L;
      is >> L;
      C.conjunto_letras.insert(L);
   }

   return is;
}

/*ostream & operator<<(ostream & os, Conjunto_Letras & C){
   return os;
}*/

Conjunto_Letras::iterator::iterator(){}

Letra Conjunto_Letras::iterator::operator*(){
   return (*it);
}

Conjunto_Letras::iterator & Conjunto_Letras::iterator::operator++(){
   ++it;

   return *this;
}

bool Conjunto_Letras::iterator::operator==(const Conjunto_Letras::iterator & i){
   return ((*this).it == i.it);
}

bool Conjunto_Letras::iterator::operator!=(const Conjunto_Letras::iterator & i){
   return !((*this) == i);
}

Conjunto_Letras::iterator Conjunto_Letras::begin(){
   iterator iter;
   iter.it = conjunto_letras.begin();

   return iter;
}

Conjunto_Letras::iterator Conjunto_Letras::end(){
   iterator iter;
   iter.it = conjunto_letras.end();

   return iter;
}
