// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Declaración
// TDA Pila con máximo (Usando pila de la STL)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

template <class T>
T Pila_max<T>::tope(){
   return pila_max.top().first;
}

template <class T>
T Pila_max<T>::maximo(){
   return pila_max.top().second;
}

template <class T>
int Pila_max<T>::num_elementos(){
   return pila_max.size();
}

template <class T>
bool Pila_max<T>::vacia(){
   return pila_max.empty();
}

template <class T>
void Pila_max<T>::quitar(){
   pila_max.pop();
}

template <class T>
void Pila_max<T>::poner(const T elemento){
   T max = -1;
   if (!pila_max.empty())
      max = pila_max.top().second;

   pila_max.push({elemento, elemento});

   if (max > pila_max.top().second){
      pila_max.top().second = max;
   }
}
