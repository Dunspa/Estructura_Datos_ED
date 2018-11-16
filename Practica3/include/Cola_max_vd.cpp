// -----------------------------------------------------------------------------
// Estructura de Datos
// Práctica 3. Estructuras de datos lineales.
//
// Declaración
// TDA Cola con máximo (Usando vector dinámico)
//
// Jose Luis Gallego Peña - A1
// -----------------------------------------------------------------------------

template <class T>
T Cola_max<T>::frente() const{
   return cola_max.front().first;
}

template <class T>
T Cola_max<T>::maximo() const{
   return cola_max.front().second;
}

template <class T>
int Cola_max<T>::num_elementos() const{
   return cola_max.size();
}

template <class T>
bool Cola_max<T>::vacia() const{
   return cola_max.empty();
}

template <class T>
void Cola_max<T>::quitar(){
   cola_max.erase(cola_max.begin());
}

template <class T>
void Cola_max<T>::poner(const T elemento){
   int pos = cola_max.size() - 1;

   for (int i = pos ; i < cola_max.size() ; i--){
      if (elemento > cola_max[i].second){
         cola_max[i].second = elemento;
      }
   }

   cola_max.push_back({elemento, elemento});
}
