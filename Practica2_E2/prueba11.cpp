// Autor: Alberto Hamilton Castro

#define TITULO "Probando salida() de Not"

#include "Not.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Not n0;
  Uno u1;
  Cero c2;

  pruebas++;
  n0.conecta1(&u1);
  {
    int espera = 0;
    int salida = n0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  pruebas++;
  n0.conecta1(&c2);
  {
    int espera = 1;
    int salida = n0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  // Resumen final
  if (fallos == 0)
    std::cout << "\n :-) Todas las " << pruebas << " pruebas correctas\n"
        << std::endl;
  else
    std::cout << "\n :-( Se han producido " << fallos << " FALLOs de "
        << pruebas << " pruebas (" << std::fixed <<  std::setprecision(2)
        << fallos*100.0/pruebas << "%)\n"
        << std::endl;
  return fallos;
}
