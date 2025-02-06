#include "CButton.hpp"

namespace ui{

CButton::CButton(SDL_Renderer* _r, SDL_Rect rect, SDL_Color c, const char* _tittle, SDL_Texture* texture, std::function<void()> callback)
: tittle(_tittle), buttonTexture(texture), EventHandler(callback), CComponent(_r, rect, nullptr, c) {}

void CButton::render(){
    if(buttonTexture != nullptr){
        printf("Do Something");
    }
    else{
        if(state == State::Normal){
            SDL_SetRenderDrawColor(this->r, this->color.r, this->color.g, this->color.b, this->color.a);
        }
        else if(state == State::Hovered){
            SDL_SetRenderDrawColor(this->r, 171,171,171,171);    
        }

        SDL_RenderFillRect(this->r, &rectComponent);

    }
}

void CButton::EventListener(SDL_Event& e){
    if(e.type == SDL_MOUSEMOTION){
        if(isClicked(e.button.x, e.button.y)){
            state = State::Hovered;
            printf("Hovered");
        }
    }

    else if(e.type == SDL_MOUSEBUTTONDOWN){
        int mouseX = e.button.x;
        int mouseY = e.button.y;
        
        if (isClicked(mouseX, mouseY)) {
            printf("Touch");
            if(EventHandler){ 
                printf("Run");
                EventHandler();
            }
        }
    }
    else state = State::Normal;
}

bool CButton::isClicked(int& x, int& y) {
    return (x >= rectComponent.x && x <= rectComponent.x + rectComponent.w &&
        y >= rectComponent.y && y <= rectComponent.y + rectComponent.h);
}

}