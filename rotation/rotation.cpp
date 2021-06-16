#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WIDTH 1280
#define HEIGHT 720

SDL_Window *mainWindow = NULL;
SDL_Surface *mainScreen = NULL;

//
// Returns SDL error message before exiting the program.
//
void printError() {
  SDL_GetError();
  exit(1);
}

//
// Creates the Window and accompanying Surface that we will be
// manipulating.
//
void init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printError();
  }

  mainWindow = SDL_CreateWindow("Practice", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                                SDL_WINDOW_SHOWN);
  mainScreen = SDL_GetWindowSurface(mainWindow);

  return;
}

//
// Free all dynamically allocated memory used by SDL 2.
//
void close() {
  SDL_FreeSurface(mainScreen);
  SDL_DestroyWindow(mainWindow);
  mainScreen = NULL;
  mainWindow = NULL;

  SDL_Quit();
  return;
}

int main(void) {
  init();

  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  close();
  return 0;
}
