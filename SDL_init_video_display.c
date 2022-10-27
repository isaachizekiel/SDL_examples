#include <stdio.h>
#include <SDL2/SDL.h>


int main() {
    printf("Initializing SDL \n");

    /* Initializing with the video subsystem */
    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
      fprintf(stderr, "could not initialize SDL %s \n", SDL_GetError());
      return -1;
    }


    atexit(SDL_Quit);
    
    /*
      Initialize the display in 640xx480 8-bit paletixed mode,
      requesting a software surface
     */
    SDL_Window *screen = SDL_CreateWindow("My Game Window",
					  SDL_WINDOWPOS_UNDEFINED,
					  SDL_WINDOWPOS_UNDEFINED,
					  640, 480,
					  SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);

    if (screen == NULL) {
      fprintf(stderr, "Could not set 640 x 480 video mode: %s\n", SDL_GetError());
    }
    

    /* shutdown subsystems */
    // SDL_Quit();

    printf("quiting ...\n");
    
    
    return 0;
}
