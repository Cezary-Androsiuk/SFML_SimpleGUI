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

        sf::Text text;
        sf::FloatRect textSpaceGlobalBounds;

        mutable bool click, clickControl;
        bool press;
        bool hover;

        void buildTextures();

    public:
        Button(sf::FloatRect floatRect, sf::Text text, sf::Color color, sf::Color colorHover, sf::Color colorPrress);
        ~Button();

    private:
        void centerText();
        bool checkMouseHover(sf::Vector2f mousePos) const;

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        const bool& getButtonClick() const;
        const bool& getButtonPress() const;

        const sf::Text& getButtonText() const;
        void setButtonText(const sf::Text& text);

    };
}




#endif