#ifndef _GLOBALS_CPP_
#define _GLOBALS_CPP_

#include "Globals.h"
#include "CFG.cpp"

/* ******************************************** */

SDL_Event*     GLOBALS::mainEvent   = new SDL_Event();
SDL_Window*    GLOBALS::Ventana     = NULL;
SDL_Renderer*  GLOBALS::Renderer    = NULL;

/* ******************************************** */

GLOBALS::GLOBALS(void)
{
}

GLOBALS::~GLOBALS(void)
{
   Close();
}

/* ******************************************** */

void GLOBALS::Log( string message )
{
   if (DEBUG)  { printf( "%s", message.c_str() );  SDL_Delay( LOG_DELAY_MS );  }
}

SDL_Texture* GLOBALS::LoadTexture( SDL_Renderer* gRenderer, string path )
{
   Log( "LoadTexture() " );
   //printf( "Cargando: %s\t", path.c_str() );

   SDL_Texture* nuevaTextura = NULL;
   SDL_Surface* imagenCargada = IMG_Load( path.c_str() );
   if( imagenCargada == NULL )
   {
      printf( "   SDL2_Image Error: %s\n", IMG_GetError() );
   }
   else
   {
      // Creo la textura desde la superficie:
      nuevaTextura = SDL_CreateTextureFromSurface( gRenderer, imagenCargada );
      if( nuevaTextura == NULL )
      {
         printf( "   SDL Error: %s\n", SDL_GetError() );
      }
      // Descargo la superficie utilizada:
      SDL_FreeSurface( imagenCargada );
   }
   Log( "LoadTexture() OK.\n" );
   return nuevaTextura;
}

bool GLOBALS::Init()
{
   Log( "Init()\n" );
   bool result = true;
   Log( "   Inicio SDL\n" );
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "   SDL Error: %s\n", SDL_GetError() );
		result = false;
	}
	else
	{
	   Log( "   Creo la ventana\n" );
      Ventana = SDL_CreateWindow( "Codebreaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, (FULLSCREEN) ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN );
      if( Ventana == NULL )
      {
         printf( "   SDL Error: %s\n", SDL_GetError() );
         result = false;
      }
      else
      {
         Log( "   Creo el Renderer\n" );
         Renderer = SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED );
         if( Renderer == NULL )
         {
            printf( "   SDL Error: %s\n", SDL_GetError() );
            result = false;
         }
         else
         {
            Log( "   Inicializo SDL2_Image\n" );
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
               printf( "   SDL_image Error: %s\n", IMG_GetError() );
               result = false;
            }
         }
      }
	}
	Log( "Init() OK.\n" );
	return result;
}

void GLOBALS::Close()
{
   Log( "Close()\n" );

//   for( int i = 0; i < TOTAL; i++)
//   {
//      SDL_DestroyTexture( numeros[ i ] );
//      numeros[ i ] = NULL;
//   }
//
//   SDL_DestroyTexture( gCarta );
//   gCarta = NULL;

   SDL_DestroyRenderer( Renderer );
   SDL_DestroyWindow( Ventana );
   Ventana = NULL;
   Renderer = NULL;

   Log( "Fin!\n" );

   IMG_Quit();
	SDL_Quit();
}

//bool loadMedia()
//{
//   log( "loadMedia()" );
//
//   bool result = true;
//
//   numeros[ CERO ] = loadTexture( gRenderer, PATH_IMAGES + "CERO.png" );
//   if( numeros[ CERO ] == NULL )
//   {
//      printf( "SDL Error: %s\n", SDL_GetError() );
//      result = false;
//   }
//   else
//   {
//      numeros[ UNO ] = loadTexture( gRenderer, PATH_IMAGES + "UNO.png" );
//      if( numeros[ UNO ] == NULL )
//      {
//         printf( "SDL Error: %s\n", SDL_GetError() );
//         result = false;
//      }
//      else
//      {
//         numeros[ DOS ] = loadTexture( gRenderer, PATH_IMAGES + "DOS.png" );
//         if( numeros[ DOS ] == NULL )
//         {
//            printf( "SDL Error: %s\n", SDL_GetError() );
//            result = false;
//         }
//         else
//         {
//            numeros[ TRES ] = loadTexture( gRenderer, PATH_IMAGES + "TRES.png" );
//            if( numeros[ TRES ] == NULL )
//            {
//               printf( "SDL Error: %s\n", SDL_GetError() );
//               result = false;
//            }
//            else
//            {
//               numeros[ CUATRO ] = loadTexture( gRenderer, PATH_IMAGES + "CUATRO.png" );
//               if( numeros[ CUATRO ] == NULL )
//               {
//                  printf( "SDL Error: %s\n", SDL_GetError() );
//                  result = false;
//               }
//               else
//               {
//                  numeros[ CINCO ] = loadTexture( gRenderer, PATH_IMAGES + "CINCO.png" );
//                  if( numeros[ CINCO ] == NULL )
//                  {
//                     printf( "SDL Error: %s\n", SDL_GetError() );
//                     result = false;
//                  }
//                  else
//                  {
//                     numeros[ SEIS ] = loadTexture( gRenderer, PATH_IMAGES + "SEIS.png" );
//                     if( numeros[ SEIS ] == NULL )
//                     {
//                        printf( "SDL Error: %s\n", SDL_GetError() );
//                        result = false;
//                     }
//                     else
//                     {
//                        numeros[ SIETE ] = loadTexture( gRenderer, PATH_IMAGES + "SIETE.png" );
//                        if( numeros[ SIETE ] == NULL )
//                        {
//                           printf( "SDL Error: %s\n", SDL_GetError() );
//                           result = false;
//                        }
//                        else
//                        {
//                           numeros[ OCHO ] = loadTexture( gRenderer, PATH_IMAGES + "OCHO.png" );
//                           if( numeros[ OCHO ] == NULL )
//                           {
//                              printf( "SDL Error: %s\n", SDL_GetError() );
//                              result = false;
//                           }
//                           else
//                           {
//                              numeros[ NUEVE ] = loadTexture( gRenderer, PATH_IMAGES + "NUEVE.png" );
//                              if( numeros[ NUEVE ] == NULL )
//                              {
//                                 printf( "SDL Error: %s\n", SDL_GetError() );
//                                 result = false;
//                              }
//                           }
//                        }
//                     }
//                  }
//               }
//            }
//         }
//      }
//   }
//
//   gCarta = loadTexture( gRenderer, PATH_IMAGES + "carta.png" );
//   if( gCarta == NULL )
//   {
//      printf( "SDL Error: %s\n", SDL_GetError() );
//      result = false;
//   }
//
//   return result;
//}

#endif
