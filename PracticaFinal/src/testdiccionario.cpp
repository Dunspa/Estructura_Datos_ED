// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Permite comprobar el buen funcionamiento del TDA Diccionario
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

int main(int argc, char * argv[]){
   if (argc != 2){
      cout << "Los parámetros son: " << endl;
      cout << "1.- El fichero con las palabras";

      return 0;
   }

   ifstream f(argv[1]);
   if (!f){
      cout << "No puedo abrir el fichero " << argv[1] << endl;

      return 0;
   }

   Diccionario D;

   cout << "Cargamos diccionario..." << endl;
   f >> D;
   cout << "Leído el diccionario..." << endl;
   cout << D;

   int longitud;
   cout << "Dime la longitud de las palabras que quieres ver ";
   cin >> longitud;
   vector<string> v = D.PalabrasLongitud(longitud);

   cout << "Palabras de longitud " << longitud << endl;
   for (unsigned int i = 0 ; i < v.size() ; i++){
      cout << v[i] << endl;
   }

   string p;
   cout << "Dime una palabra: ";
   cin >> p;
   if (D.Esta(p))
      cout << "Esa palabra existe";
   else
      cout << "Esa palabra no existe";

   return 0;
}
