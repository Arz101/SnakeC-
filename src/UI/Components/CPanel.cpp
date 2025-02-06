#include "CPanel.hpp"

namespace ui{

CPanel::CPanel(SDL_Rect rect, SDL_Renderer* render, SDL_Color color)
: CComponent(render, rect, nullptr, color){

}

void CPanel::addComponent(CButton* component){
    buttons.push_back(component);
}

void CPanel::addComponent(CPanel* component){
    panels.push_back(component);
}

void CPanel::render() {
    SDL_SetRenderDrawColor(this->r, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(this->r, &rectComponent);

    if(buttons.size() > 0){
        for(auto& it : buttons){
            it->render();
        }
    }
    if(panels.size() > 0){
        for(auto& it : panels){
            it->render();
        }
    }
}

void CPanel::EventListener(SDL_Event& e){
    for(auto& it : buttons){
        it->EventListener(e);
    }
}

}

