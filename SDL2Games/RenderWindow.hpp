#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class RenderWindow
{
public:
    RenderWindow(const char* w_tittle, int w_width, int w_heigh, bool fullscreen);
    void cleanUp();
private:
    SDL_Window* window;
    SDL_Renderer* renderer; 
};