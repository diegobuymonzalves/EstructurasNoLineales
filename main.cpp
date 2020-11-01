#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "Arbol.h"

int main() {
   Arbol<double> arbol;

   std::cout << "Agregar valores numericos al arbol, no se guardan valores duplicados\n"
   << "Escriba \"fin\" dejar de ingresar datos.\n" << std::endl;

   std::string dataIn;
   double valor;
   while(true) {
        std::cout << "numero> ";
        std::cin >> dataIn;
        if(dataIn == "fin")
            break;
        try {
            valor = std::stod(dataIn);
            arbol.insertarNodo(valor);
        } catch(std::invalid_argument &exp) {
            std::cout << "ingresa solo numeros" << std::endl;
        }
   }

   std::cout << "\nRecorrido preorden\n";
   arbol.recorridoPreOrden();

   std::cout << "\n\nRecorrdo inorden\n";
   arbol.recorridoInOrden();

   std::cout << "\n\nRecorrido postorden\n";
   arbol.recorridoPostOrden();
   std::cout << std::endl;

   return 0;
}
