#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <stdio.h>
#include <SDL.h>
#include <deque>
#include "vector2.hpp"

class Snake{
private:
    Vec::Vector2 position;
    std::deque<SDL_Rect*> body;
    Vec::Vector2 dir = {1,0};
    const int* CELL_SIZE;
public:
    Snake(const int&);
    ~Snake();

    void move(SDL_Event&);
    void render(SDL_Renderer*);
    void update();
};


#endif