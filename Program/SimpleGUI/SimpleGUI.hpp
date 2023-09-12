#ifndef SIMPLEGUI_HPP
#define SIMPLEGUI_HPP

namespace sgui{
    // SimpleGraphicalUserInterface
    class SGUI{
    public:
        virtual void event(const sf::Event& event) = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderTarget* window) const = 0;
    };
}

#include "Switch/Switch.hpp"
#include "Button/Button.hpp"
#include "CheckBox/CheckBox.hpp"
#include "ImageBox/ImageBox.hpp"
#include "RadioButton/RadioButton.hpp"

#endif