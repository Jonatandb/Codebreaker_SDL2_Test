#ifndef _CARTA_CPP_
#define _CARTA_CPP_

#include "Carta.h"

Carta::Carta( SDL_Renderer* renderer )
{
   textura = GLOBALS::LoadTexture( renderer, PATH_IMAGES + "carta.png" );
   int w, h;
   SDL_QueryTexture(textura, NULL, NULL, &w, &h);
   posicion.x = 0;
   posicion.y = 0;
   posicion.w = w;
   posicion.h = h;
}

Carta::~Carta()
{
   SDL_DestroyTexture( textura );
}

void Carta::Draw( SDL_Renderer* renderer, int x, int y )
{
   posicion.x = x;
   posicion.y = y;
   SDL_RenderCopy( renderer, textura, NULL, &posicion );
}

void Carta::Draw( SDL_Renderer* renderer, int x, int y, int w, int h )
{
   posicion.x = x;
   posicion.y = y;
   posicion.w = w;
   posicion.h = h;
   SDL_RenderCopy( renderer, textura, NULL, &posicion );
}

#endif
