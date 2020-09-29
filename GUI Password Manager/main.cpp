/* The main program manages the graphical interface of the password manager. */
#include <iostream>
#include <SDL.h>
#include <string>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

SDL_Window* Window = NULL;  // window to render to  
SDL_Surface* ScreenSurface = NULL;  // SDL Surface attached to Window 
SDL_Renderer* Renderer = NULL;   // renderer to render texture of resized image 

// A function that is able to print errors after a certain line of code has executed 
void printError() { std::cout << "SDL_Error: " << SDL_GetError() << "\n"; }


bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { printError(); return false; }

	// Create a Window with a custom size 
	Window = SDL_CreateWindow("Object and Background", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (Window == NULL) { printError(); return false; }

	// Create Renderer for Window 
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if (Renderer == NULL) { printError(); return false; }
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);  // default color is white 

	// get surface info about Window so we can save it as PNG later on in the program 
	ScreenSurface = SDL_GetWindowSurface(Window);

	return true;  // if everything worked out 

}

void close() {
	SDL_FreeSurface(ScreenSurface);
	ScreenSurface = NULL;

	SDL_DestroyRenderer(Renderer);
	Renderer = NULL;

	SDL_DestroyWindow(Window);
	Window = NULL;

	SDL_Quit();
}


int main(int argc, char* args[]) {
	/* --- GET USER INPUT --- */
	std::cout << "Enter the width of the screen: " << std::endl;
	std::cin >> SCREEN_WIDTH;
	std::cout << std::endl;  // separate the sections of text 
	std::cout << "Enter the height of the screen: " << std::endl;
	std::cin >> SCREEN_HEIGHT;

	init();  // Initialize our Window 

	SDL_Event current_event;  // the most current event in queue 
	bool running = true;   // should our program continue running?

	while (running) {
		while (SDL_PollEvent(&current_event) != 0) {  // if '0', means there's no event in queue 
			if (current_event.type == SDL_QUIT) {
				running = false;
			}

			if (running == false) { break; }
		}

		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);  // Set render color to use white 

		SDL_RenderClear(Renderer);   // clear the window by drawing the whole window white 

		SDL_RenderPresent(Renderer);   // Update window 
	}

	close();   // Garbage collection before we end program 
	return 0;
}
