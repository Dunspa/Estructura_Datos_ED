// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Programa que obtiene la cantidad de instancias de cada letra
// Función main
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Diccionario.h"
#include "Letra.h"

int main(int argc, char * argv[]){
   if (argc != 4){
      cout << "Los parámetros son: " << endl;
      cout << "1.- El fichero con el diccionario" << endl;
      cout << "2.- El fichero con las letras" << endl;
      cout << "3.- El fichero donde escribir el conjunto de letras "
           << "con la cantidad de apariciones calculada" << endl;

      return 0;
   }

   ifstream d(argv[1]);
   if (!d){
      cout << "No puedo abrir el fichero " << argv[1] << endl;

      return 0;
   }

   Diccionario D;
   cout << "Cargamos diccionario..." << endl;
   d >> D;
   cout << "Diccionario cargado" << endl;

   ifstream c(argv[2]);
   if (!c){
      cout << "No puedo abrir el fichero " << argv[2] << endl;

      return 0;
   }

   Conjunto_Letras C;
   cout << "Cargamos conjunto de letras..." << endl;
   c >> C;
   cout << "Conjunto de letras cargado" << endl;

   ofstream s(argv[3]);
   if (!s){
      cout << "No puedo abrir el fichero " << argv[3] << endl;

      return 0;
   }

   Conjunto_Letras::iterator it;
   double total_apariciones = 0;
   for (it = C.begin() ; it != C.end() ; ++it){
      total_apariciones += (*it).getNumApariciones();
   }

   double total_frel = 0;
   s << "#Letra FAbs. Frel." << endl;
   for (it = C.begin() ; it != C.end() ; ++it){
      char c = (*it).getCaracter();
      double fab = (*it).getNumApariciones();
      double frel = 100.0 * (fab / total_apariciones);
      s << c << "\t";
      s << fab << "\t";
      s << frel << "% " << endl;
      total_frel += frel;
   }
   s << "Total:\t" << total_apariciones << "\t" << total_frel << "%" << endl;

   return 0;
}
