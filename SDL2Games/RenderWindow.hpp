#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class RenderWindow
{
public:
    RenderWindow(const char* w_tittle, int w_width, int w_heigh, bool fullscreen);
    void cleanUp();
    bool running();
    void quit();
    SDL_Texture* loadTexure(const char* texture_filePath);
private:
    SDL_Window* window;
    SDL_Renderer* renderer; 
    bool gameRunning = true;
};