// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Definición del TDA Bolsa de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Bolsa_Letras.h"
#include <random>    // dispositivos, generadores y distribuciones aleatorias
#include <chrono>    // duraciones (duration), unidades de tiempo
#include <string>

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------
template< int min, int max > int aleatorio(){
   static default_random_engine generador((random_device())());
   static uniform_int_distribution<int> distribucion_uniforme(min, max);
   return distribucion_uniforme(generador);
}

Bolsa_Letras::Bolsa_Letras(){}

Bolsa_Letras::Bolsa_Letras(Conjunto_Letras & C){
   Conjunto_Letras::iterator it;
   for (it = C.begin() ; it != C.end(); ++it){
      char p = tolower((*it).getCaracter());
      int n = (*it).getNumApariciones();
      for (int i = 0 ; i < n ; i++){
         bolsa.insert(p);
      }
   }
}

unordered_multiset<char> Bolsa_Letras::getBolsa(){
   return bolsa;
}

Bolsa_Letras Bolsa_Letras::letrasJuego(int n){
   Bolsa_Letras B;
   int i;

   for (i = 0 ; i < n ; i++){
      iterator it = begin();
      int salto = int(aleatorio<0, 500>()) % bolsa.size();
      for (int j = 0 ; j < salto ; j++, ++it);

      char c = (*it);
      B.bolsa.insert(c);
      bolsa.erase(it.it);
   }

   return B;
}

bool Bolsa_Letras::esCorrecta(string palabra){
   bool palabra_correcta = true;
   iterator it;

   for (int i = 0 ; i < palabra.length() && palabra_correcta ; i++){
      bool encontrado = false;
      char c = palabra[i];

      for (it = begin() ; it != end() && !encontrado ; ++it){
         if ((*it) == c){
            encontrado = true;
         }
      }

      if (!encontrado){
         palabra_correcta = false;
      }
   }

   return palabra_correcta;
}

pair<Diccionario, vector<int> > Bolsa_Letras::Soluciones(Diccionario & D, Conjunto_Letras & C, char modo, int puntuacion, string & mejor){
   pair<Diccionario, vector<int> > soluciones;
   Diccionario::iterator it_d;
   Bolsa_Letras::iterator it_b;
   string palabra;
   int puntos = 0;
   int mejor_puntos = 0;

   for (it_d = D.begin() ; it_d != D.end() ; ++it_d){
      bool valida = true;
      palabra = (*it_d);
      Bolsa_Letras aux = (*this);

      for (int i = 0 ; i < palabra.length() && valida ; i++){
         bool encontrado = false;

         for (it_b = aux.begin() ; it_b != aux.end() && !encontrado ; ++it_b){
            char c = (*it_b);
            if (palabra[i] == c){
               encontrado = true;
               aux.bolsa.erase(c);
            }
         }

         if (!encontrado){
            valida = false;
         }
      }

      if (valida){
         puntos = C.calculaPuntuacion(palabra, modo);

         if (puntos >= puntuacion){
            soluciones.first.setPalabra(palabra);
            soluciones.second.push_back(puntos);

            if (puntos > mejor_puntos){
               mejor = palabra;
               mejor_puntos = puntos;
            }
         }
      }
   }

   return soluciones;
}

Bolsa_Letras::iterator::iterator(){}

char Bolsa_Letras::iterator::operator*(){
   return (*it);
}

Bolsa_Letras::iterator & Bolsa_Letras::iterator::operator++(){
   ++it;

   return *this;
}

bool Bolsa_Letras::iterator::operator==(const Bolsa_Letras::iterator & i){
   return ((*this).it == i.it);
}

bool Bolsa_Letras::iterator::operator!=(const Bolsa_Letras::iterator & i){
   return !((*this) == i);
}

Bolsa_Letras::iterator Bolsa_Letras::begin(){
   iterator iter;
   iter.it = bolsa.begin();

   return iter;
}

Bolsa_Letras::iterator Bolsa_Letras::end(){
   iterator iter;
   iter.it = bolsa.end();

   return iter;
}
