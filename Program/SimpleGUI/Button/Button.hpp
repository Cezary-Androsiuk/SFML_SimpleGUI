#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <cstdio>
#include <cmath>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Button
    {
        sf::Vector2f position;
        
        struct Body{
            sf::FloatRect globalBounds;
            sf::CircleShape left;
            sf::RectangleShape middle;
            sf::CircleShape right;
            sf::Color color;
            sf::Color colorHover;
            sf::Color colorPress;
        } body;

        
        mutable bool click, clickControl;
        bool press;
        bool hover;

        void buildTextures();

    public:
        Button(sf::FloatRect floatRect, sf::Color color, sf::Color colorHover, sf::Color colorPrress);
        ~Button();

    private:
        bool checkMouseHover(sf::Vector2f mousePos) const;

    public:
        void update(const sf::Event* event);
        void render(sf::RenderTarget* window) const;

        const bool& getButtonClick() const;
        const bool& getButtonPress() const;

    };
}




#endif