// -----------------------------------------------------------------------------
// Estructura de Datos
// Ejercicios adicionales: prueba de examen de prácticas
//
// Lista que contiene el abecedario y un valor que expresa el número
// de apariciones de este
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimir
 */
/*template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;

  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";

  return s;
}*/

template <class T>
ostream & operator<<(ostream & os, const list<T> & l){
   typename list<T>::const_iterator i;

   for (i = l.begin() ; i != l.end() ; i++){
      os << (*i).first << " | " << (*i).second << endl;
   }

   return os;
}

/**
 * @brief Inicializar el generador de numeros aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
 */
void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero entero positivo aleatorio en el rango [min,max]
 */
int generaEntero(int min, int max){
    int tam = max-min+1;
    return ((rand()%tam)+min);
}

struct par{
   char first;
   double second;

   bool operator<(const par & p){
      return second < p.second;
   }
};

int main(){

   list<par> lista;
   par p;

   for (char c = 'A' ; c <= 'Z' ; c++){
      p.first = c;
      p.second = generaEntero(1, 100);
      lista.push_back(p);
   }

   // 1. Sustituye el número de apariciones de una letra por la frecuencia relativa
   int total_apariciones = 0;
   list<par>::iterator i;

   for (i = lista.begin() ; i != lista.end() ; i++){
      total_apariciones += (*i).second;
   }
   for (i = lista.begin(); i != lista.end(); i++){
      (*i).second = 100.0 * (*i).second / total_apariciones;
   }

   cout << endl << "Lista con frecuencias relativas: " << endl;
   cout << lista;

   // 2. Ordenar por frecuencia relativa de mayor a menor
   lista.sort();
   lista.reverse();

   cout << endl << "Lista ordenada por frecuencia relativa de mayor a menor: " << endl;
   cout << lista;

   // 3. Nueva lista con los 10 mayores
   list<par> nueva_lista;
   list<par>::iterator iter = lista.begin();
   for (int i = 0 ; i < 10 ; i++){
      nueva_lista.push_back(*iter);
      iter++;
   }

   cout << endl << "Lista con los 10 mayores: " << endl;
   cout << nueva_lista;
}
