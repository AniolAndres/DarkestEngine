// DotGame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize with error: " << SDL_GetError() << std::endl;
	}
    
	return EXIT_SUCCESS;
}