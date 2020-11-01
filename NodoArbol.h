#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED

template<typename TIPONODO> class Arbol;

template<typename TIPONODO>
class NodoArbol{
   friend class Arbol<TIPONODO>;
public:
   NodoArbol(const TIPONODO &d)
      : izquierdoPtr(nullptr), datos(d),
        derechoPtr(nullptr) {
      // cuerpo vac�o
   }

   TIPONODO obtenerDatos() const {
      return datos;
   }
private:
   NodoArbol<TIPONODO> *izquierdoPtr;
   TIPONODO datos;
   NodoArbol<TIPONODO> *derechoPtr;
};

#endif
