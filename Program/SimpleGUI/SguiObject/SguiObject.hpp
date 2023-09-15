#ifndef SGUIOBJECT_HPP
#define SGUIOBJECT_HPP

#include <SFML/Graphics.hpp>

namespace sgui{
    class SguiObject{
    public:
        virtual void event(const sf::Event& event) = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderTarget* window) const = 0;

        virtual const sf::FloatRect& getBounds() const = 0;
        virtual void setBounds(const sf::FloatRect& bounds) = 0;
    };
}


#endif