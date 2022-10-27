#include <SDL.h>

/*
  we can think of the structure of a game as follows
  init -> get_input -> do_physics -> render -> exit
            |                         |
	    +-------------------------+
*/

#define WINDOW_TITLE "Setting up SDL"

SDL_Window *g_pWindow = NULL;
SDL_Renderer *g_pRenderer = NULL;
int g_bRunning = 0;


int init(const char *title, int xpos, int ypos, int h, int w, int flags) {
  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, w, h, flags);

    if (g_pWindow != NULL) {
      // it is always better to use our own renderer for better access to opengl API
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    } else {
      fprintf(stderr, "can not create SDL Window %s\n", SDL_GetError());
      return 0;
    }
    
  } else {
    fprintf(stderr, "can not initialize SDL %s\n", SDL_GetError());
    return 0;
  }  

  return 1;
}

void render() {
  /* every thing successed let draw the window */
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  // clear the window to black
  SDL_RenderClear(g_pRenderer);

  // show the window
  SDL_RenderPresent(g_pRenderer);
  
}

int main() {

  if (init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)) {
    g_bRunning = 1;
  } else {
    return 1;
  }

  while (g_bRunning) {
    render();
  }
  
  // clean SDL
  SDL_Quit();

  return 0;
  

  
}
