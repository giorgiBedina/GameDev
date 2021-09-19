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


bool RenderWindow::running()
{
    return gameRunning;
}

SDL_Texture* RenderWindow::loadTexture(const char* texture_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, texture_filePath);

    if(texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::renderTexture(SDL_Texture* w_texture)
{
    SDL_RenderCopy(renderer, w_texture, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::quit()
{
    gameRunning= false;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}