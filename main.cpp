#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "config.cpp"
using namespace std;

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

SDL_Window*  gVentana      = NULL;                 // Usar SDL_DestroyWindow
SDL_Texture* numeros[ TOTAL ];
SDL_Texture* imagenActual = NULL;                  // Usar SDL_FreeSurface

SDL_Texture* loadTexture( string path );
SDL_Texture* gCarta = NULL;                      // Usar SDL_DesstroyTexture
SDL_Renderer* gRenderer = NULL;                    // Usar SDL_DesstroyRenderer

void log ( string message )
{
   if (DEBUG)  { printf( "%s\n", message.c_str() );  SDL_Delay( DELAY_MS );  }
}

bool init()
{
   log( "init()" );

   bool result = true;

   // Inicio SDL:
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL Error: %s\n", SDL_GetError() );
		result = false;
	}
	else
	{
	   // Creo una ventana:
      gVentana = SDL_CreateWindow( "Codebreaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN /*SDL_WINDOW_FULLSCREEN_DESKTOP*/ );
      if( gVentana == NULL )
      {
         printf( "SDL Error: %s\n", SDL_GetError() );
         result = false;
      }
      else
      {
         // Creo un renderer:
         gRenderer = SDL_CreateRenderer( gVentana, -1, SDL_RENDERER_ACCELERATED );
         if( gRenderer == NULL )
         {
            printf( "SDL Error: %s\n", SDL_GetError() );
            result = false;
         }
         else
         {
            // Inicializo SDL2_Image:
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
               printf( "SDL_image Error: %s\n", IMG_GetError() );
               result = false;
            }
            else
            {
               //gSupVentana = SDL_GetWindowSurface( gVentana );
            }
         }
      }
	}

	return result;
}

//SDL_Surface* loadSurface( string path )
//{
//   log( "loadSurface()" );
//
//   printf( "Cargando: %s\t", path.c_str() );
//
//   SDL_Surface* imagenOptimizada = NULL;
//   //SDL_Surface* imagenCargada = SDL_LoadBMP( path.c_str() ); // Con SDL_Image ahora cuento con IMG_Load que carga archivos png.
//   SDL_Surface* imagenCargada = IMG_Load( path.c_str() );
//   if( imagenCargada == NULL )
//   {
//      printf( "SDL Error: %s\n", IMG_GetError() ); // IMG_GetError devuelve errores de SDL_Image.
//   }
//   else
//   {
//      imagenOptimizada = SDL_ConvertSurface( imagenCargada, gSupVentana->format, 0 );
//      if( imagenOptimizada == NULL )
//      {
//         printf( "SDL Error: %s\n", SDL_GetError() );
//      }
//      SDL_FreeSurface( imagenCargada );
//   }
//   printf( "OK!\n"  );
//   return imagenOptimizada;
//}

SDL_Texture* loadTexture( string path )
{
   log( "loadTexture()" );
   printf( "Cargando: %s\t", path.c_str() );

   SDL_Texture* nuevaTextura = NULL;
   SDL_Surface* imagenCargada = IMG_Load( path.c_str() );
   if( imagenCargada == NULL )
   {
      printf( "SDL2_Image Error: %s\n", IMG_GetError() );
   }
   else
   {
      // Creo la textura desde la superficie:
      nuevaTextura = SDL_CreateTextureFromSurface( gRenderer, imagenCargada );
      if( nuevaTextura == NULL )
      {
         printf( "SDL Error: %s\n", SDL_GetError() );
      }
      // Descargo la superficie utilizada:
      SDL_FreeSurface( imagenCargada );
   }
   return nuevaTextura;
}

bool loadMedia()
{
   log( "loadMedia()" );

   bool result = true;

   numeros[ CERO ] = loadTexture( PATH_IMAGES + "CERO.png" );
   if( numeros[ CERO ] == NULL )
   {
      printf( "SDL Error: %s\n", SDL_GetError() );
      result = false;
   }
   else
   {
      numeros[ UNO ] = loadTexture( PATH_IMAGES + "UNO.png" );
      if( numeros[ UNO ] == NULL )
      {
         printf( "SDL Error: %s\n", SDL_GetError() );
         result = false;
      }
      else
      {
         numeros[ DOS ] = loadTexture( PATH_IMAGES + "DOS.png" );
         if( numeros[ DOS ] == NULL )
         {
            printf( "SDL Error: %s\n", SDL_GetError() );
            result = false;
         }
         else
         {
            numeros[ TRES ] = loadTexture( PATH_IMAGES + "TRES.png" );
            if( numeros[ TRES ] == NULL )
            {
               printf( "SDL Error: %s\n", SDL_GetError() );
               result = false;
            }
            else
            {
               numeros[ CUATRO ] = loadTexture( PATH_IMAGES + "CUATRO.png" );
               if( numeros[ CUATRO ] == NULL )
               {
                  printf( "SDL Error: %s\n", SDL_GetError() );
                  result = false;
               }
               else
               {
                  numeros[ CINCO ] = loadTexture( PATH_IMAGES + "CINCO.png" );
                  if( numeros[ CINCO ] == NULL )
                  {
                     printf( "SDL Error: %s\n", SDL_GetError() );
                     result = false;
                  }
                  else
                  {
                     numeros[ SEIS ] = loadTexture( PATH_IMAGES + "SEIS.png" );
                     if( numeros[ SEIS ] == NULL )
                     {
                        printf( "SDL Error: %s\n", SDL_GetError() );
                        result = false;
                     }
                     else
                     {
                        numeros[ SIETE ] = loadTexture( PATH_IMAGES + "SIETE.png" );
                        if( numeros[ SIETE ] == NULL )
                        {
                           printf( "SDL Error: %s\n", SDL_GetError() );
                           result = false;
                        }
                        else
                        {
                           numeros[ OCHO ] = loadTexture( PATH_IMAGES + "OCHO.png" );
                           if( numeros[ OCHO ] == NULL )
                           {
                              printf( "SDL Error: %s\n", SDL_GetError() );
                              result = false;
                           }
                           else
                           {
                              numeros[ NUEVE ] = loadTexture( PATH_IMAGES + "NUEVE.png" );
                              if( numeros[ NUEVE ] == NULL )
                              {
                                 printf( "SDL Error: %s\n", SDL_GetError() );
                                 result = false;
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }

   gCarta = loadTexture( PATH_IMAGES + "carta.png" );
   if( gCarta == NULL )
   {
      printf( "SDL Error: %s\n", SDL_GetError() );
      result = false;
   }

   return result;
}

void close()
{
   log( "close()" );

   for( int i = 0; i < TOTAL; i++)
   {
      SDL_DestroyTexture( numeros[ i ] );
      numeros[ i ] = NULL;
   }

/*
//   Código para liberar la memoria de la imagen pequeña:
//   if( imagenPequenia != NULL )
//   {
//      SDL_FreeSurface( imagenPequenia );
//      imagenPequenia = NULL;
//   }
*/

   SDL_DestroyTexture( gCarta );
   gCarta = NULL;

   SDL_DestroyRenderer( gRenderer );
   SDL_DestroyWindow( gVentana );
   gVentana = NULL;
   gRenderer = NULL;

/*
//   if( imagenActual != NULL )
//   {
//      imagenActual = NULL;
//   }
*/

   log( "Fin!" );

   IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
   log( "main()" );

   bool salir = false;
/*
//   int mostrarHelloOriginal = true;
//   bool mostrarHelloAmpliado = false;
//   bool mostrarTeclaPresionada = false;
//   int contador = 0;
*/
   SDL_Event e;

   if( !init() )
      close();

   if( !loadMedia() )
      close();

/*
//   Codigo para redimensionar la imagen pequeña:
//   SDL_Rect rect;
//   rect.x = 0;
//   rect.y = 0;
//   rect.h = 768;
//   rect.w = 1024;

//   imagenActual = imagenes[ KEY_PRESS_SURFACE_DEFAULT ];

//  int _x = 0, _y = 0, distancia = 25, _ancho = 10, _alto = 10, contador = 0;
//   Uint8 rojo = 255, verde = 0, azul = 0;
//   bool mostrarCuadrado = true, mostrarLinea = false, mostrarPunto = false, mostrarImagen = false;
*/
   int numeroActual = 0, posActual = 0;
   int cartaW = 181, cartaH = 280;
   while( !salir )
   {
      while( SDL_PollEvent( &e ) != 0 )
      {
         if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
         {
            salir = true;
            break;
         }
         else if( e.type == SDL_KEYDOWN )
         {
            switch( e.key.keysym.sym )
            {
               case SDLK_UP:
                           numeroActual++;
                           break;
               case SDLK_DOWN:
                           numeroActual--;
                           break;
               case SDLK_LEFT:
                           posActual--;
                           break;
               case SDLK_RIGHT:
                           posActual++;
                           break;
               case SDLK_KP_PLUS:
                           break;
               case SDLK_KP_MINUS:
                           break;
               case SDLK_RETURN:
               case SDLK_KP_ENTER:
                           break;
               case SDLK_SPACE:
                           break;
               default:
                           break;
            }
         } // End if( e.type
      } // End while( SDL_PollEvent( &e ) != 0 )


if( posActual > 3 ) posActual = 0;
if( posActual < 0 ) posActual = 3;


if( numeroActual > 9 ) numeroActual = 0;
if( numeroActual < 0 ) numeroActual = 9;
imagenActual = numeros[ numeroActual ];


// Cartas:
         // 1:
         SDL_Rect viewPortCard;
         viewPortCard.x = 15;
         viewPortCard.y = 25;
         viewPortCard.w = cartaW;
         viewPortCard.h = cartaH;
         SDL_RenderSetViewport( gRenderer, &viewPortCard );
         SDL_RenderCopy( gRenderer, gCarta, NULL, NULL );
         // 2:
         viewPortCard.x = 211;
         SDL_RenderSetViewport( gRenderer, &viewPortCard );
         SDL_RenderCopy( gRenderer, gCarta, NULL, NULL );
         // 3:
         viewPortCard.x = 407;
         SDL_RenderSetViewport( gRenderer, &viewPortCard );
         SDL_RenderCopy( gRenderer, gCarta, NULL, NULL );
         // 4:
         viewPortCard.x = 603;
         SDL_RenderSetViewport( gRenderer, &viewPortCard );
         SDL_RenderCopy( gRenderer, gCarta, NULL, NULL );

// Numeros:
         // 1:
         SDL_Rect viewPortNumero;
         viewPortNumero.x = 15;
         viewPortNumero.y = 310;
         viewPortNumero.w = cartaW;
         viewPortNumero.h = cartaH;
         SDL_RenderSetViewport( gRenderer, &viewPortNumero );
         SDL_RenderCopy( gRenderer, imagenActual, NULL, NULL );
         // 2:
         viewPortNumero.x = 211;
         SDL_RenderSetViewport( gRenderer, &viewPortNumero );
         SDL_RenderCopy( gRenderer, imagenActual, NULL, NULL );
         // 3:
         viewPortNumero.x = 407;
         SDL_RenderSetViewport( gRenderer, &viewPortNumero );
         SDL_RenderCopy( gRenderer, imagenActual, NULL, NULL );
         // 4:
         viewPortNumero.x = 603;
         SDL_RenderSetViewport( gRenderer, &viewPortNumero );
         SDL_RenderCopy( gRenderer, imagenActual, NULL, NULL );


// Bordes:
         SDL_Rect borde;
         switch( posActual )
         {
            case 0:
                  SDL_RenderSetViewport( gRenderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
                  borde.x = 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  break;
            case 1:
                  SDL_RenderSetViewport( gRenderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  break;
            case 2:
                  SDL_RenderSetViewport( gRenderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  break;
            case 3:
                  SDL_RenderSetViewport( gRenderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( gRenderer, &borde );
                  break;
         } // End switch( posActual )

      SDL_RenderPresent( gRenderer );  // Muestro por pantalla el Renderer

   }  // End while( !salir )

   close();

	return 0;
} // End main


/*
// Logica para controlar movimiento:
//if( _x < 0 ) _x = 0;
//if( _y < 0 ) _y = 0;
//if( _x > SCREEN_WIDTH - _ancho ) _x = SCREEN_WIDTH - _ancho;
//if( _y > SCREEN_HEIGHT - _alto ) _y = SCREEN_HEIGHT - _alto;


// Dibujado:

SDL_Rect borde;
borde.x = 0;
borde.y = 0;
borde.w = 185;
borde.h = 290;

SDL_SetRenderDrawColor( gRenderer, 100, 200, 100, 255 ); // Seteo color de fondo
SDL_RenderFillRect( gRenderer, &rectangulo );
//SDL_RenderClear( gRenderer ); // Pinto el render de negro

//SDL_SetRenderDrawColor( gRenderer, rojo, verde, azul, 255 ); // Seteo color

//SDL_Rect rectangulo;
//rectangulo.x = _x;
//rectangulo.y = _y;
//rectangulo.w = _ancho;
//rectangulo.h = _alto;
//
//if( mostrarCuadrado )   SDL_RenderFillRect( gRenderer, &rectangulo );
//
//if( mostrarLinea )      SDL_RenderDrawLine( gRenderer, _x, _y, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
//
//if( mostrarPunto )      SDL_RenderDrawPoint ( gRenderer, _x, _y );

//if( mostrarImagen )     SDL_RenderCopy( gRenderer, gTextura, NULL, &rectangulo );
*/

/*
viewPortCard.x = 202;
SDL_RenderSetViewport( gRenderer, &viewPortCard );
SDL_RenderCopy( gRenderer, gTextura, NULL, &viewPortCard );

viewPortCard.x = 350;
SDL_RenderSetViewport( gRenderer, &viewPortCard );
SDL_RenderCopy( gRenderer, gTextura, NULL, &viewPortCard );


SDL_RenderSetViewport( gRenderer, NULL );
*/

/*
//      printf( "Esperando... No se que color deberia ver... ¿Negro?\n" );
//      SDL_Delay( 1500 );
//
//      SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
//      SDL_RenderClear( gRenderer );
//      SDL_RenderPresent( gRenderer );
//
//      printf( "Esperando... Deberia ver Rojo...\n" );
//      SDL_Delay( 1500 );
//
//      SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
//      SDL_RenderClear( gRenderer );
//      SDL_RenderPresent( gRenderer );
//
//      printf( "Esperando... Deberia ver Azul...\n" );
//      SDL_Delay( 1500 );
*/
/*
      //------------------------
      if( contador > 1000 && contador < 2000 )
      {
         mostrarHelloOriginal = false;
         mostrarHelloAmpliado = true;
      }
      if( contador > 2000 )
      {
         mostrarHelloAmpliado = false;
         mostrarTeclaPresionada = true;
      }
      //------------------------

      // Pinto la superficie de verde:
      SDL_FillRect( gSupVentana, NULL, SDL_MapRGB( gSupVentana->format, 0, 180, 0 ) );

      //------------------------
      if( mostrarHelloOriginal )
      {
         SDL_BlitSurface( imagenPequenia, NULL, gSupVentana, NULL ); // Cargo en la superficie de la ventana la imagen
         //printf( "Original!\n" );
      }
      //------------------------

      //------------------------
      if( mostrarHelloAmpliado )
      {
         SDL_BlitScaled( imagenPequenia, NULL, gSupVentana, &rect); // Pego una imagen con un tamaño redimensionado
         //printf( "Ampliada!\n" );
      }
      //------------------------

      //------------------------
      if( mostrarTeclaPresionada )
      {
         SDL_BlitSurface( imagenActual, NULL, gSupVentana, NULL ); // Cargo en la superficie de la ventana la imagen
         //printf( "TeclaPresionada!\n" );
      }
      //------------------------

      contador++;

      SDL_RenderClear( gRenderer );
      SDL_RenderCopy( gRenderer, gTextura, NULL, NULL );
      SDL_RenderPresent( gRenderer );

    // SDL_UpdateWindowSurface( gVentana ); // Muestro por pantalla el resultado final.
*/

//
//void cambiarDeColor( Uint8& rojo, Uint8& verde, Uint8& azul )
//{
//   log( "cambiarDeColor()" );
//   if( rojo  == 255 ){ rojo = 0; verde = 255; azul = 0; return;}
//   if( verde == 255 ){ rojo = 0; verde = 0; azul = 255; return;}
//   if( azul  == 255 ){ rojo = 255; verde = 0; azul = 0; return;}
//}
//
//void cambiarDeFigura( bool& cuadrado, bool& linea, bool& punto, bool &imagen)
//{
//   log( "cambiarDeFigura()" );
//   if( cuadrado ) { cuadrado = false; linea = true; punto = false; imagen = false; return;}
//   if( linea    ) { cuadrado = false; linea = false; punto = true; imagen = false; return;}
//   if( punto    ) { cuadrado = false; linea = false; punto = false; imagen = true; return;}
//   if( imagen   ) { cuadrado = true;  linea = false; punto = false; imagen = false; return;}
//}
