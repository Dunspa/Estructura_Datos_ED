// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 2. Abstracción.
//
// Realiza varias pruebas sobre los TDA Diccionario y Termino
// Función main
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include "Diccionario.h"
#include "Vector_Dinamico.h"

using namespace std;

int main(int argc, char * argv[]){

   if (argc != 2){
      cout << "Dime el nombre del fichero con el diccionario" << endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
      cout << "No puedo abrir el fichero " << argv[1] << endl;
      return 0;
   }
   
   Diccionario mi_diccionario;
   f >> mi_diccionario;          // Cargamos en memoria el diccionario
   f.close();                    // Cerramos el flujo de fichero
   
   // Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
   string str;
   char caracter_inicial, caracter_final;

   // - Obtener el diccionario completo
   cout << mi_diccionario << endl;

   // - Obtener las definiciones asociadas a una palabra   
   cout << endl << "Introduzca la palabra de la que quiere obtener su(s) definición(es)"
        << endl;
   cin >> str;
   Vector_Dinamico<string> definiciones = mi_diccionario.getDefiniciones(str);
   cout << endl << "Las definiciones de la palabra " << str << " son: " << endl;
   for (int i = 0 ; i < definiciones.size() ; i++){
      cout << definiciones[i] << endl;
   }

   // - Obtener el (sub)diccionario de términos comprendidos en 
   // [caracter_inicial, caracter_final]
   cout << endl << "Introduzca un caracter inicial y final para obtener el diccionario"
        << " de términos comprendidos entre ellos" << endl;
   cin >> caracter_inicial >> caracter_final;
   cout << mi_diccionario.FiltradoIntervalo(caracter_inicial, caracter_final);

   // - Obtener el (sub)diccionario de términos asociados a una palabra clave. 
   // Ejemplo: el diccionario de terminos asociados a "color"   
   cout << endl << "Introduzca una palabra para obtener el diccionario de términos" 
        << " asociados a esa palabra clave" << endl;
   cin >> str;
   cout << mi_diccionario.FiltradoPalabraClave(str);

   // - Obtener el numero total de definiciones, el maximo de definiciones 
   // asociadas a una unica palabra y el promedio de definiciones por palabra
   cout << endl;
   mi_diccionario.RecuentoDefiniciones();

   return 0;

}
