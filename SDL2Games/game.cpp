#include "RenderWindow.cpp"
#include <iostream>

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_init  HAS FAILED . SDL_ERROR: " << SDL_GetError() << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init  HAS FAILED . ERROR: " << SDL_GetError() << std::endl; 

    RenderWindow window("game v1.0", 800, 600, false);

    window.cleanUp();
    SDL_Quit();

    return 0;
}