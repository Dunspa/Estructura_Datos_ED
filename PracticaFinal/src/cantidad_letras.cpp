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
#include "Bolsa_Letras.h"

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

   ifstream b(argv[2]);
   if (!b){
      cout << "No puedo abrir el fichero " << argv[2] << endl;

      return 0;
   }

   Bolsa_Letras B;
   cout << "Cargamos bolsa de letras..." << endl;
   f >> B;
   cout << "Bolsa de letras cargada" << endl;

   ofstream s(argv[3]);
   if (!s){
      cout << "No puedo abrir el fichero " << argv[3] << endl;

      return 0;
   }

   char * buffer = "#Letra FAbs. Frel.";
   s.write(buffer, strlen(buffer));
}
