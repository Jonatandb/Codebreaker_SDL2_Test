#include "CFG.cpp"

#include "Carta.h"

int main( int argc, char* args[] )
{
   bool salir = false;

   if( !GLOBALS::Init() )
      GLOBALS::Close();

   Carta* carta1 = new Carta( GLOBALS::Renderer );
   Carta* carta2 = new Carta( GLOBALS::Renderer );
   Carta* carta3 = new Carta( GLOBALS::Renderer );
   Carta* carta4 = new Carta( GLOBALS::Renderer );

   int numeroActual = 0, posActual = 0;
   int cartaW = 181, cartaH = 280;

   while( !salir )
   {
      while( SDL_PollEvent( GLOBALS::mainEvent ) != 0 )
      {
         if( GLOBALS::mainEvent->type == SDL_QUIT || GLOBALS::mainEvent->key.keysym.sym == SDLK_ESCAPE)
         {
            salir = true;
            break;
         }
         else if( GLOBALS::mainEvent->type == SDL_KEYDOWN )
         {
            switch( GLOBALS::mainEvent->key.keysym.sym )
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
//imagenActual = numeros[ numeroActual ];


// Cartas:
         carta1->Draw( GLOBALS::Renderer, 15, 25, 181, 280 );
         carta2->Draw( GLOBALS::Renderer, 211, 25, 181, 280 );
         carta3->Draw( GLOBALS::Renderer, 407, 25, 181, 280 );
         carta4->Draw( GLOBALS::Renderer, 603, 25, 181, 280 );

// Numeros:
         // 1:
//         SDL_Rect viewPortNumero;
//         viewPortNumero.x = 15;
//         viewPortNumero.y = 310;
//         viewPortNumero.w = cartaW;
//         viewPortNumero.h = cartaH;
//         SDL_RenderSetViewport( GLOBALS::Renderer, &viewPortNumero );
//         SDL_RenderCopy( GLOBALS::Renderer, imagenActual, NULL, NULL );
//         // 2:
//         viewPortNumero.x = 211;
//         SDL_RenderSetViewport( GLOBALS::Renderer, &viewPortNumero );
//         SDL_RenderCopy( GLOBALS::Renderer, imagenActual, NULL, NULL );
//         // 3:
//         viewPortNumero.x = 407;
//         SDL_RenderSetViewport( GLOBALS::Renderer, &viewPortNumero );
//         SDL_RenderCopy( GLOBALS::Renderer, imagenActual, NULL, NULL );
//         // 4:
//         viewPortNumero.x = 603;
//         SDL_RenderSetViewport( GLOBALS::Renderer, &viewPortNumero );
//         SDL_RenderCopy( GLOBALS::Renderer, imagenActual, NULL, NULL );


// Bordes:
         SDL_Rect borde;
         switch( posActual )
         {
            case 0:
                  SDL_RenderSetViewport( GLOBALS::Renderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 255, 0, 0, 255 );
                  borde.x = 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  break;
            case 1:
                  SDL_RenderSetViewport( GLOBALS::Renderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  break;
            case 2:
                  SDL_RenderSetViewport( GLOBALS::Renderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  break;
            case 3:
                  SDL_RenderSetViewport( GLOBALS::Renderer, NULL );
                  // 1:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 15; borde.y = 310; borde.w = cartaW; borde.h = cartaH;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 2:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 16; borde.y = 311; borde.w = cartaW-2; borde.h = cartaH-2;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 3:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 0, 0, 255, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 17; borde.y = 312; borde.w = cartaW-4; borde.h = cartaH-4;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  // 4:
                  SDL_SetRenderDrawColor( GLOBALS::Renderer, 255, 0, 0, 255 );
                  borde.x = 15 + cartaW + 15 + cartaW + 15 + cartaW + 18; borde.y = 313; borde.w = cartaW-6; borde.h = cartaH-6;
                  SDL_RenderDrawRect( GLOBALS::Renderer, &borde );
                  break;
         } // End switch( posActual )

      SDL_RenderPresent( GLOBALS::Renderer );  // Muestro por pantalla el Renderer

      // Add a 16msec delay to make our game run at ~60 fps
		//SDL_Delay( 16 );

   }  // End while( !salir )

   GLOBALS::Close();

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
