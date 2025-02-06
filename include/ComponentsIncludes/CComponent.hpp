#ifndef CCOMPONENT_HPP
#define CCOMPONENT_HPP

#include "SDL.h"
#include "stdio.h"

// Interface 
class CComponent{
protected:
    const SDL_Rect rectComponent;
    const SDL_Texture* textureComponent;
    SDL_Renderer* r = nullptr;
    const SDL_Color color;
    bool visible = false;

public:
    CComponent(SDL_Renderer*, const SDL_Rect&, SDL_Texture*, const SDL_Color);
    virtual ~CComponent() = default;
    virtual void render() = 0;
    virtual void EventListener(SDL_Event& e) = 0;
    void setVisible(bool e){ visible=e; };
};


#endif