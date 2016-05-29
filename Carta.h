#ifndef _CARTA_H_
#define _CARTA_H_

#include "Cabecera.h"
#include "CFG.cpp"

class Carta
{
private:
   SDL_Rect posicion;
   SDL_Texture* textura;

public:
   Carta( SDL_Renderer* );
   ~Carta( void );

	void Update();
	void Draw( SDL_Renderer*, int, int );
	void Draw( SDL_Renderer*, int, int, int, int);
};

#endif // _CARTA_H_
