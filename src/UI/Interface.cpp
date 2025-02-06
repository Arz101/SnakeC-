#include "Interface.hpp"


Interface::Interface(SDL_Window* _window, SDL_Renderer* _r){
    this->window = _window;
    this->r = _r;
    
    int width, height;
    SDL_GetWindowSize(window, &width, &height);

    mainPanel = new ui::CPanel(SDL_Rect{0,0, width, height} ,this->r ,SDL_Color{0,0,0,255});
    mainPanel->setVisible(true);
    initButtons();
}

void Interface::initButtons(){
    ui::CButton* buttonPlay = new ui::CButton(
        r, SDL_Rect{5*30,20*30, 100,50}, 
        SDL_Color{255,255,255,0}, "Play", nullptr,[this](){
            Game;
        });
    buttonPlay->setVisible(true);
    mainPanel->addComponent(buttonPlay);
}

void Interface::render(){
    mainPanel->render();
}

void Interface::initGame(std::function<void(Snake*, Food*, SDL_Renderer*, Uint32&, Uint32&)> callback){
    this->Game=callback;
}

void Interface::getEvent(SDL_Event& e){
    mainPanel->EventListener(e);
}