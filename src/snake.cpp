#include "snake.hpp"

Snake::Snake(const int& CELL_SIZE){
    this->CELL_SIZE = &CELL_SIZE;
    body.push_back(new SDL_Rect(8*CELL_SIZE, 9*CELL_SIZE, CELL_SIZE, CELL_SIZE));
    body.push_back(new SDL_Rect(7*CELL_SIZE, 9*CELL_SIZE, CELL_SIZE, CELL_SIZE));
    body.push_back(new SDL_Rect(6*CELL_SIZE, 9*CELL_SIZE, CELL_SIZE, CELL_SIZE));

}

void Snake::render(SDL_Renderer* render){
    for(auto it = body.begin(); it != body.end(); ++it){
        SDL_SetRenderDrawColor(render, 0, 255,0,0);
        SDL_RenderFillRect(render, (*it));
    }
}

void Snake::move(SDL_Event& e){
/*
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:
        dir = {0,-1}; 
        break;
    
    default:
        break;
    }
*/
}

void Snake::update(){
    position = {body[0]->x, body[0]->y};
    Vec::Vector2 head = Vec::Vector2Add(position, dir);
    
    delete body[body.size()-1];
    body.pop_back();
    body.push_front(new SDL_Rect(head.x, head.y, *CELL_SIZE, *CELL_SIZE));
}