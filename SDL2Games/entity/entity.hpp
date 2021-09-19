#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(float x_position, float y_position, SDL_Texture* entity_texture);
    float get_x(){return x_position;}
    float get_y(){return y_position;}
    SDL_Texture* get_textyre(){return entity_texture;};
    SDL_Rect get_curFrame(){return currentFrame;};
    
private:
    float x_position, y_position;
    SDL_Rect currentFrame;
    SDL_Texture* entity_texture;
};