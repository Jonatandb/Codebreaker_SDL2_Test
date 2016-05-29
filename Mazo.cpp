#include "Mazo.h"

Mazo::Mazo(int x, int y, int cartas)
{
   printf( "Se instancio un nuevo mazo...\n" );
   posicion.x = x;
   posicion.y = y;
   cantCartas = cartas;
   CargarCartas();
}

void Mazo::CargarCartas()
{
   Inicializar();
}

void Mazo::Inicializar()
{
   // Instancias todas sus cartas

}


