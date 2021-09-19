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
    SDL_Rect texture_src;
    texture_src.x = 0;
    texture_src.y = 0;
    texture_src.w = 32;
    texture_src.h = 32;

    SDL_Rect texture_dst;
    texture_dst.x = 0;
    texture_dst.y = 0;
    texture_dst.w = 32;
    texture_dst.h = 32;

    SDL_RenderCopy(renderer, w_texture, &texture_src, &texture_dst);
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