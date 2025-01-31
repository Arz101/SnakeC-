#ifndef FOOD_HPP
#define FOOD_HPP

#include <SDL.h>

class Food{
private:
    int x, y;
    SDL_Rect foodRect;
public:
    Food(const int&, const int&);
    ~Food();

    void render(SDL_Renderer*);
};


#endif