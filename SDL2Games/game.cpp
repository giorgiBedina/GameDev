#include "RenderWindow.cpp"
#include "entity/entity.cpp"
#include <iostream>

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_init  HAS FAILED . SDL_ERROR: " << SDL_GetError() << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init  HAS FAILED . ERROR: " << SDL_GetError() << std::endl; 

    RenderWindow game("game v1.0", 800, 600, false);

    SDL_Texture* grassTexture = game.loadTexture("texture/ground_grass_1.png");

    SDL_Event event;

    while(game.running())
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                game.quit();
        }

        game.clear();
        game.renderTexture(grassTexture);
        game.display();
    }

    game.cleanUp();
    SDL_Quit();

    return 0;
}