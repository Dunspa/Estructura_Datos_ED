// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 4. STL e iteradores.
//
// Declaración
// TDA Termino
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Termino.h"
#include <iostream>
#include <cassert>

Termino::Termino(){
   termino.first = "";
}

Termino::Termino(const string p, const vector<string> d){
   assert(p != "");
   termino.first = p;
   termino.second = d;
}

Termino::Termino(const Termino & t){
   CopiaTermino(t);
}

string Termino::getPalabra() const{
   return termino.first;
}

vector<string> Termino::getDefiniciones() const{
   return termino.second;
}

int Termino::getNumDefiniciones() const{
   return termino.second.size();
}

void Termino::setPalabra(string p){
   termino.first = p;
}

void Termino::aniadir_definicion(const string d){
   termino.second.push_back(d);
}

void Termino::setDefiniciones(vector<string> d){
   termino.second = d;
}

Termino & Termino::operator=(const Termino & t){
   if (this != &t)
		CopiaTermino(t);

   return (*this);
}

bool Termino::operator==(const Termino & t) const{
   return ((termino.first == t.getPalabra()) && (termino.second == t.getDefiniciones()));
}

bool Termino::operator<(const Termino & t) const{
   return ((*this).getPalabra() < t.getPalabra());
}

Termino::iterator Termino::begin(){
   return termino.second.begin();
}

Termino::const_iterator Termino::begin() const{
   return termino.second.begin();
}

Termino::iterator Termino::end(){
   return termino.second.end();
}

Termino::const_iterator Termino::end() const{
   return termino.second.end();
}

ostream & operator<<(ostream & os, const Termino & t){
   Termino::const_iterator it;

   for (it = t.begin() ; it != t.end() ; ++it){
      os << t.termino.first << "-->" << (*it) << endl;
   }

   return os;
}

void Termino::CopiaTermino(const Termino & t){
   termino.first = t.getPalabra();
   termino.second = t.getDefiniciones();
}
