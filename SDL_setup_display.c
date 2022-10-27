#include <SDL.h>
#include <SDL_render.h>

#define WINDOW_TITLE "Setting up SDL"


SDL_Window *g_pWindow = NULL;
SDL_Renderer *g_pRenderer = NULL;

int main() {

  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
    g_pWindow = SDL_CreateWindow(WINDOW_TITLE,
				   SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED,
				   640, 480, SDL_WINDOW_SHOWN);

    if (g_pWindow != NULL) {
      // it is always better to use our own renderer for better access to opengl API
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    } else {
      fprintf(stderr, "can not create SDL Window %s\n", SDL_GetError());
    }
    
  } else {
    fprintf(stderr, "can not initialize SDL %s\n", SDL_GetError());
    return -1;
  }

  /* every thing successed let draw the window */
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  // clear the window to black
  SDL_RenderClear(g_pRenderer);

  // show the windows
  SDL_Delay(5000);


  // clean SDL
  SDL_Quit();

  return 0;
  

  
}
