// Autor: Alberto Hamilton Castro
// Fichero de prueba AndM

#define TITULO "Probando AndM: info () conexiones con índice NO existente"

#include "AndM.hpp"
#include "Uno.hpp"
#include "Cero.hpp"
#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  AndM am0;
  Uno u1;
  Cero c2;
  
  pruebas++;
  {
    std::string espera = "Puerta ANDM (id=0) salida = 9\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&c2,1);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 9\n  NO CONECTADA\n  Puerta CERO (id=2)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1,3);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 9\n  NO CONECTADA\n  Puerta CERO (id=2)\n  NO CONECTADA\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1, 0);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 9\n  Puerta UNO (id=1)\n  Puerta CERO (id=2)\n  NO CONECTADA\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1, 2);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 0\n  Puerta UNO (id=1)\n  Puerta CERO (id=2)\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1, 1);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 1\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1, 10);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 9\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n  NO CONECTADA\n  NO CONECTADA\n  NO CONECTADA\n  NO CONECTADA\n  NO CONECTADA\n  NO CONECTADA\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
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
