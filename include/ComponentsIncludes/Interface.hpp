#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "SDL.h"
#include "CPanel.hpp"
#include "CButton.hpp"
#include <functional>
#include "snake.hpp"
#include "food.hpp"

class Interface{
private:
    SDL_Window* window;
    SDL_Renderer* r;
    ui::CPanel* mainPanel;
    std::function<void(Snake*, Food*, SDL_Renderer*, Uint32&, Uint32&)> Game;
public:
    Interface(SDL_Window*, SDL_Renderer*);
    void initGame(std::function<void(Snake*, Food*, SDL_Renderer*, Uint32&, Uint32&)>);
    void render();
    void initButtons();
    bool init(){return false;}
    void getEvent(SDL_Event&);
};

#endif