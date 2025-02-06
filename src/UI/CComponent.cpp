#include "CComponent.hpp"

CComponent::CComponent(SDL_Renderer* _render, const SDL_Rect& _rect, SDL_Texture* _texture, const SDL_Color _color) 
: rectComponent(_rect), color(_color) , textureComponent(_texture) {
    this->r = _render;
}
