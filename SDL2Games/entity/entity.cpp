#include "entity.hpp"

Entity::Entity(float x_position, float y_position, SDL_Texture* entity_texture)
    :x_position(x_position), y_position(y_position), entity_texture(entity_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}