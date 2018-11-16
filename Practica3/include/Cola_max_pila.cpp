// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Declaración
// TDA Cola con máximo (Usando Pila_max.h y pila de la STL)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

template <class T>
T Cola_max<T>::frente(){
   while (!inserciones.vacia()){
      consultas.poner(inserciones.tope());
      inserciones.quitar();
   }

   return consultas.tope();
}

template <class T>
T Cola_max<T>::maximo(){
   T maximo;
   if (inserciones.vacia()){
      maximo = consultas.maximo();
   }
   else if (consultas.vacia()){
      maximo = inserciones.maximo();
   }
   else{
      if (inserciones.maximo() > consultas.maximo()){
         maximo = inserciones.maximo();
      }
      else{
         maximo = consultas.maximo();
      }
   }

   return maximo;
}

template <class T>
int Cola_max<T>::num_elementos(){
   return (inserciones.num_elementos() + consultas.num_elementos());
}

template <class T>
bool Cola_max<T>::vacia(){
   return (inserciones.vacia() && consultas.vacia());
}

template <class T>
void Cola_max<T>::quitar(){
   while (!inserciones.vacia()){
      consultas.poner(inserciones.tope());
      inserciones.quitar();
   }

   consultas.quitar();
}

template <class T>
void Cola_max<T>::poner(const T elemento){
   inserciones.poner(elemento);
}
