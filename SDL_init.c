#include <stdio.h>
#include <SDL.h>

int main() {
    printf("Initializing SDL \n");

    /* Initializing the defaults */
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO == -1)) {
      printf("could not initialize SDL %s \n", SDL_GetError());
      return -1;
    }

    printf("SDL initialized \n");

    /* shutdown subsystems */
    SDL_Quit();

    printf("quiting ...\n");
    
    
    return 0;
}
