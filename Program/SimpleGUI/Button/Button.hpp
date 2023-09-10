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
        #define BUTTON_DISABLE_COLOR sf::Color(120, 120, 120)
        #define BUTTON_DISABLE_TEXT_COLOR sf::Color(80, 80, 80)
        
        sf::FloatRect globalBounds;
        sf::RectangleShape shape;
        sf::Color color;
        sf::Color colorHover;
        sf::Color colorPress;

        sf::Text text;
        sf::Color textColor;

        mutable bool click, clickControl;
        bool press;
        bool hover;

        bool enable;
        bool visible;

        void buildTextures();

    public:
        Button(sf::FloatRect floatRect, sf::Text text, sf::Color textColor, sf::Color color, sf::Color colorHover, sf::Color colorPrress);
        ~Button();

    private:
        void centerText();
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        const bool& getButtonClick() const;
        const bool& getButtonPress() const;

        const sf::Text& getButtonText() const;
        void setButtonText(const sf::Text& text);

        const bool& getEnable() const;
        void setEnable(const bool& enabled);

        const bool& getVisible() const;
        void setVisible(const bool& visibled);

    };
}




#endif