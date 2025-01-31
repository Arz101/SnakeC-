#include "food.hpp"

Food::Food(const int& CELL_SIZE, const int& CELL_COUNT){
    this->x = rand() % CELL_COUNT;
    this->y = rand() % CELL_COUNT;
    foodRect = {x*CELL_SIZE,y*CELL_SIZE, CELL_SIZE, CELL_SIZE};
}

void Food::render(SDL_Renderer* render){
    SDL_SetRenderDrawColor(render, 255,0,0,0);
    SDL_RenderFillRect(render, &foodRect);
}

