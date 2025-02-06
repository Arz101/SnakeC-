#ifndef CBUTTON_HPP
#define CBUTTON_HPP

#include "SDL.h"
#include <functional>
#include <stdio.h>
#include "CComponent.hpp"

namespace ui{

class CButton : public CComponent{
private:
    enum class State{Normal, Pressed,Hovered};
    State state = State::Normal;
    SDL_Texture* buttonTexture = nullptr;
    const char* tittle;
    std::function<void()> EventHandler;
    bool visible = false;;
public:
    CButton(SDL_Renderer*,SDL_Rect, SDL_Color, const char*, SDL_Texture*, std::function<void()>);
    void render() override;
    bool isClicked(int&,int&);
    void EventListener(SDL_Event& e) override;
};

}
#endif