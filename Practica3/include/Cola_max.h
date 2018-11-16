/**
  * @file Pila_max.h
  * @brief Fichero cabecera del TDA Cola con máximo que indica qué implementación usar
  *
  */

#define CUAL_COMPILA 2
#if CUAL_COMPILA == 1
   #include "Cola_max_vd.h"
#else
   #include "Cola_max_pila.h"
#endif
