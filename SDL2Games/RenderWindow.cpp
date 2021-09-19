#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* w_tittle, int w_width, int w_heigh, bool fullscreen)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(w_tittle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width,  w_heigh,  fullscreen);
    if(window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

bool RenderWindow::running()
{
    return gameRunning;
}

void RenderWindow::quit()
{
    gameRunning= false;
}