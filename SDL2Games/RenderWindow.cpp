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

void RenderWindow::renderTexture(Entity& given_entity)
{
    SDL_Rect texture_src;
    texture_src.x = given_entity.get_curFrame().x;
    texture_src.y = given_entity.get_curFrame().y;
    texture_src.w = given_entity.get_curFrame().w;
    texture_src.h = given_entity.get_curFrame().h;

    SDL_Rect texture_dst;
    texture_dst.x = given_entity.get_x();
    texture_dst.y = given_entity.get_y();
    texture_dst.w = given_entity.get_curFrame().w;
    texture_dst.h = given_entity.get_curFrame().h;

    SDL_RenderCopy(renderer, given_entity.get_textyre(), &texture_src, &texture_dst);
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