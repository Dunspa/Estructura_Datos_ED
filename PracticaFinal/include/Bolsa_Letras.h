// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica Final: Letras
//
// Declaración del TDA Bolsa de Letras
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#ifndef BOLSA_LETRAS
#define BOLSA_LETRAS
#include <unordered_set>
#include <vector>
#include "Letra.h"
#include "Diccionario.h"
using namespace std;

class Bolsa_Letras{
private:
   unordered_multiset<char> bolsa;
public:
   Bolsa_Letras();
   Bolsa_Letras(Conjunto_Letras & C);
   unordered_multiset<char> getBolsa();
   Bolsa_Letras letrasJuego(int n);
   bool esCorrecta(string palabra);
   pair<Diccionario, vector<int> > Soluciones(Diccionario & D, Conjunto_Letras & C, char modo, int puntuacion, string & mejor);

   class iterator{
   private:
      unordered_multiset<char>::iterator it;
   public:
      iterator();
      char operator *();
      iterator & operator ++();
      bool operator ==(const iterator & i);
      bool operator !=(const iterator & i);
      friend class Bolsa_Letras;
   };

   iterator begin();
   iterator end();
};

#endif
