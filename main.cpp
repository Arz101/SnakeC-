#include <stdio.h>
#include "SDL.h"
#include "snake.hpp"
#include "food.hpp"
#include <stdlib.h>
#include <time.h>
#include "include/ComponentsIncludes/Interface.hpp"

const int CELL_SIZE = 30;
const int CELL_COUNT = 25;

bool init(SDL_Window**, SDL_Renderer**, Interface**);
void close(SDL_Window**, SDL_Renderer**);
void game(Snake*, Food*, SDL_Renderer*, Uint32&, Uint32&);

int main(int argc, char** argv){
    Snake* snake = new Snake(CELL_SIZE);
    Food* food = new Food(CELL_SIZE, CELL_COUNT);
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    Interface* mainInterface = nullptr;
    mainInterface->initGame(game);

    printf("Hello, World!");
    if(!init(&window, &render, &mainInterface)){
        printf("Error: %s", SDL_GetError());
        return -1;
    }
    else{

        bool running = true;
        SDL_Event e;
        
        Uint32 lastTime = SDL_GetTicks(); 

        while(running){
            Uint32 start_time = SDL_GetTicks();
            Uint32 current_time = SDL_GetTicks();

            while(SDL_PollEvent(&e)){
                if(e.type == SDL_QUIT){
                    running = false;
                }
                mainInterface->getEvent(e);
                snake->move(e);
            }
            SDL_SetRenderDrawColor(render, 0,0,0,255);
            SDL_RenderClear(render);
            mainInterface->render();
            
            if(mainInterface->init()){
                printf("init");
            }
            
            SDL_RenderPresent(render);


            Uint32 frame_time = SDL_GetTicks() - start_time;
            if(frame_time < 16){
                SDL_Delay(16 - frame_time);
            }
        }
    }
    
    
    return 0;
}

bool init(SDL_Window** window, SDL_Renderer** render, Interface** mainInterface){
    srand(time(nullptr));

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: %s", SDL_GetError());
        return false;
    }
    else{
        *window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, CELL_SIZE*CELL_COUNT, CELL_SIZE*CELL_COUNT, SDL_WINDOW_SHOWN);

        if(window == nullptr){
            printf("Error: %s", SDL_GetError());
            return false;
        }

        *render = SDL_CreateRenderer(*window, -1 , SDL_RENDERER_ACCELERATED);

        if(*render == nullptr){
            printf("Error: %s", SDL_GetError());
            return false;
        }

        *mainInterface = new Interface(*window,*render);
    }
    return true;
}

void close(SDL_Window** window, SDL_Renderer** render){
    SDL_DestroyRenderer(*render);
    *render = nullptr;
    SDL_DestroyWindow(*window);
    *window = nullptr;
}

void game(Snake* snake, Food* food, SDL_Renderer* render, Uint32& lastTime, Uint32& current_time){
    if(current_time - lastTime >= 200){
        snake->update();
    }
    snake->render(render);
    food->render(render);
}