// Autor: Alberto Hamilton Castro

#define TITULO "Probando tabla de verdad de Or no conectada"

#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

Or  o0;
Uno uno;
Cero cero;

void comprueba(int A, int B, int espera) {

  //conectamos la entrada según A y B
  if (A != 9)
    o0.conecta1( A ? (Puerta*)&uno : (Puerta*)&cero );
  if (B != 9)
    o0.conecta2( B ? (Puerta*)&uno : (Puerta*)&cero );

  pruebas++;
  int salida = o0.salida();
  std::cout << "Caso " << A << B << " = " << salida;
  std::cout << " salida correcta " << espera;
  if ( salida == espera)
    std::cout << " CORRECTO " << std::endl;
  else {
    std::cout << " FALLO" << std::endl;
    fallos++;
  }

}

int main() {

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  //especificamos tabla de verdad
  comprueba(9,9,9);
  comprueba(9,1,9);

  o0 = Or();

  comprueba(9,9,9);
  comprueba(1,9,9);

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
