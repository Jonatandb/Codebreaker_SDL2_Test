#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include "Cabecera.h"

class GLOBALS
{
public:
   GLOBALS(void);
   ~GLOBALS(void);

   enum NumerosTextures
         {
            CERO,
            UNO,
            DOS,
            TRES,
            CUATRO,
            CINCO,
            SEIS,
            SIETE,
            OCHO,
            NUEVE,
            TOTAL
         };

   static   SDL_Window* Ventana;
   static   SDL_Renderer* Renderer;
   static   SDL_Event* mainEvent;

   //   static   SDL_Texture* numeros[ TOTAL ];
   //   static   SDL_Texture* imagenActual;
   //   static   SDL_Texture* Carta;

   static   void Log( string );
   static   SDL_Texture* LoadTexture( SDL_Renderer*, string );
   static   bool Init();
   static   void Close();
};

#endif
