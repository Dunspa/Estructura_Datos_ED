// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Programa que construye las palabras de longitud mayor de un Diccionario
// a partir de una serie de letras seleccionadas de forma aleatoria
// Función main
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include "Diccionario.h"
#include "Letra.h"
#include "Bolsa_Letras.h"

int main(int argc, char * argv[]){
   if (argc != 5){
      cout << "Los parámetros son: " << endl;
      cout << "1.- El fichero con el diccionario" << endl;
      cout << "2.- El fichero con las letras" << endl;
      cout << "3.- Número de letras que se deben generar de forma aleatoria" << endl;
      cout << "4.- Modalidad de juego: L (Longitud) / P (Puntuación)" << endl;

      return 0;
   }

   int num_letras = atoi(argv[3]);
   char modo = argv[4][0];
   char seguir = 'S';

   if (modo != 'P' && modo != 'L'){
      cout << "Error. El argumento 4 (modo) debe ser L (Longitud) o P (Puntuación)" << endl;

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

   cout << "Cargamos bolsa de letras..." << endl;
   Bolsa_Letras B(C);
   cout << "Bolsa de letras cargada" << endl;

   if (modo == 'P'){
      cout << "******Puntuaciones Letras*******" << endl;
      C.Puntuaciones();
   }

   while (seguir == 'S'){
      cout << endl << "EMPIEZA EL JUEGO" << endl;

      cout << "Las letras son: ";
      Bolsa_Letras::iterator it;
      Bolsa_Letras Bjuego = B.letrasJuego(num_letras);
      for (it = Bjuego.begin() ; it != Bjuego.end() ; ++it){
         cout << (*it) << " ";
      }

      string solucion;
      cout << endl << "Dime tu solución: ";
      cin >> solucion;

      int puntuacion;
      if (D.Esta(solucion)){
         if (Bjuego.esCorrecta(solucion)){
            puntuacion = C.calculaPuntuacion(solucion, modo);
            cout << solucion << "   Puntuación: " << puntuacion << endl;
         }
         else{
            cout << "La palabra que has introducido no usa una o más de las letras dadas" << endl;
         }
      }
      else{
         cout << "La palabra que has introducido no existe" << endl;
      }

      string mejor_solucion;
      pair<Diccionario, vector<int> > soluciones = Bjuego.Soluciones(D, C, modo, puntuacion, mejor_solucion);
      Diccionario::iterator sol_d = soluciones.first.begin();
      vector<int>::iterator sol_p = soluciones.second.begin();
      cout << "Mis soluciones son: " << endl;
      for (; sol_d != soluciones.first.end() && sol_p != soluciones.second.end() ; ++sol_d, ++sol_p){
         solucion = (*sol_d);
         puntuacion = (*sol_p);
         cout << solucion << "   Puntuación: " << puntuacion << endl;;
      }

      cout << endl << "Mejor solución: " << mejor_solucion << endl;

      do{
         cout << "¿Quieres seguir jugando[S/N]? ";
         cin >> seguir;
      }while(seguir != 'S' && seguir != 'N');
   }

   cout << endl << "FIN DEL JUEGO" << endl;

   return 0;
}
