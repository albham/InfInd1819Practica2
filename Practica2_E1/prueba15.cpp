// Autor: Alberto Hamilton

#define TITULO "Prueba clase Vector: sobrecarga <<"

#include "Vector.hpp"
#include "Punto.hpp"
#include <iostream>
#include <cmath>  //necesario para el std::abs
#include <vector>
#include <iomanip>
#include <sstream>

#define EPS  (1e-6) //error máximo permitido al compara doubles


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<double> magPol { 4.9659, -64.9831, 3.0414, 170.5377, 2.9682,
        -122.6192, 1.1000, 180.0000, 4.2544, -23.5523, 1.7464,
        166.7595, 4.2953, -102.0948};

  const std::vector<std::string> ts_teorico {
    "v(5.0, -65.0)",
    "v(3.0, 170.5)",
    "v(3.0, -122.6)",
    "v(1.1, 180.0)",
    "v(4.3, -23.6)",
    "v(1.7, 166.8)",
    "v(4.3, -102.1)",
  };

  int nPruebas = magPol.size() / 2;

  for( int i = 0; i<nPruebas; i++) {
    double rho = magPol[i*2], tita = magPol[i*2+1];
    std::string toString_teorico(ts_teorico[i]);

    Vector v(rho, tita);

    std::cout << "Considerando el vector " << toString_teorico << std::endl;

    pruebas++;
    std::ostringstream ossTs;
    ossTs << v;
    std::string ts = ossTs.str();
    if ( ts != toString_teorico )
      std::cout << "FALLO " << ++fallos << ": toStringPt ha devuelto '"
          << ts <<"' cuando se esperaba '" << toString_teorico << "'"
          << std::endl;

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
