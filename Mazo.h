#ifndef _MAZO_H_
#define _MAZO_H_

#include "Cabecera.h"
#include "Carta.h"

class Mazo
{
private:
   SDL_Rect posicion;
   int cantCartas;
   Carta* cartas[];
   void CargarCartas();
   void Inicializar();

public:
   Mazo(int, int, int);
};


#endif // _MAZO_H_
