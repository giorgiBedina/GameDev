#include "RenderWindow.cpp"
#include <iostream>

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_init  HAS FAILED . SDL_ERROR: " << SDL_GetError() << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init  HAS FAILED . ERROR: " << SDL_GetError() << std::endl; 

    RenderWindow game("game v1.0", 800, 600, false);

    SDL_Event event;

    while(game.running())
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                game.quit();
        }
    }

    game.cleanUp();
    SDL_Quit();

    return 0;
}