// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 2. Abstracción.
//
// Declaración
// TDA Termino
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

#include "Termino.h"
#include "Vector_Dinamico.h"
#include <iostream>
#include <cassert>

Termino::Termino(){
   palabra = "";
   definiciones = 0;
}

Termino::Termino(const string p, const Vector_Dinamico<string> d){
   assert(p != "");
   palabra = p;
   definiciones = d;
}

Termino::Termino(const Termino & t){
   CopiaTermino(t);
}

string Termino::getPalabra() const{
   return palabra;
}

Vector_Dinamico<string> Termino::getDefiniciones() const{
   return definiciones;
}

int Termino::getNumDefiniciones() const{
   return definiciones.size();
}

void Termino::setPalabra(string p){
   palabra = p;
}

void Termino::aniadir_definicion(const string d){
   definiciones.aniadir(d);
}

void Termino::setDefiniciones(Vector_Dinamico<string> d){
   definiciones = d;
}

Termino & Termino::operator=(const Termino & t){
   if (this != &t)
		CopiaTermino(t);

   return (*this); 
}

bool Termino::operator==(const Termino & t){
   return ((palabra == t.getPalabra()) && (definiciones == t.getDefiniciones()));
}

void Termino::CopiaTermino(const Termino & t){
   palabra = t.getPalabra();
   definiciones = t.definiciones;
}