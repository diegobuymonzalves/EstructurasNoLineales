#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <iostream>
#include "NodoArbol.h"

template<typename TIPONODO> class Arbol {
public:
   Arbol();
   void insertarNodo(const TIPONODO &);
   void recorridoPreOrden() const;
   void recorridoInOrden() const;
   void recorridoPostOrden() const;
private:
   NodoArbol<TIPONODO> *raizPtr;

   void insertarNodo(NodoArbol<TIPONODO> **, const TIPONODO &);
   void preOrden(NodoArbol<TIPONODO> *) const;
   void inOrden(NodoArbol<TIPONODO> *) const;
   void postOrden(NodoArbol<TIPONODO> *) const;
};

template<typename TIPONODO>
Arbol<TIPONODO>::Arbol() {
   raizPtr = nullptr;
}

template<typename TIPONODO>
void Arbol<TIPONODO>::insertarNodo(const TIPONODO &valor) {
   insertarNodo(&raizPtr, valor);
}

template< typename TIPONODO >
void Arbol<TIPONODO>::insertarNodo(
   NodoArbol<TIPONODO> **ptr, const TIPONODO &valor) {
   if (*ptr == nullptr)
      *ptr = new NodoArbol<TIPONODO>(valor);
   else {
      if (valor < (*ptr)->datos)
         insertarNodo(&((*ptr)->izquierdoPtr), valor);
      else {
         if (valor > (*ptr)->datos)
            insertarNodo(&((*ptr)->derechoPtr), valor);
         else
            std::cout << valor << " duplicado." << std::endl;
      }
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPreOrden() const
{
   preOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::preOrden(NodoArbol<TIPONODO> *ptr) const {
   if (ptr != nullptr) {
      std::cout << ptr->datos << ' ';
      preOrden(ptr->izquierdoPtr);
      preOrden(ptr->derechoPtr);
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoInOrden() const {
   inOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::inOrden(NodoArbol<TIPONODO> *ptr) const {
   if ( ptr != nullptr ) {
      inOrden(ptr->izquierdoPtr);
      std::cout << ptr->datos << ' ';
      inOrden(ptr->derechoPtr);
   }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPostOrden() const {
   postOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::postOrden(
   NodoArbol<TIPONODO> *ptr) const {
   if (ptr != nullptr) {
      postOrden(ptr->izquierdoPtr);
      postOrden(ptr->derechoPtr);
      std::cout << ptr->datos << ' ';
   }
}

#endif // ARBOL_H_INCLUDED
