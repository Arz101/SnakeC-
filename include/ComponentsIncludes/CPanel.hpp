#ifndef CPANEL_HPP
#define CPANEL_HPP

#include "SDL.h"
#include <vector>
#include <variant>
#include <memory>
#include "CButton.hpp"
#include "CComponent.hpp"

namespace ui{

class CPanel : public CComponent {
private:
    std::vector<CButton*> buttons;
    std::vector<CPanel*> panels;
public:
    CPanel(SDL_Rect,SDL_Renderer*, SDL_Color);
    void render() override;
    void EventListener(SDL_Event& e) override;
    void addComponent(CButton* component);
    void addComponent(CPanel* component);
};

}

#endif