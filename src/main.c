#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <libtcc.h>

int main(int argc, char** argv) {
    printf("Hello, World!\n");
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_EVERYTHING);

    TCCState *s;

    s = tcc_new();

    return 0;
}
