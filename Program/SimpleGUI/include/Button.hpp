#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "SguiObject.hpp"

// SimpleGUI
namespace sgui{
    class Button : public SguiObject{
        // BUTTON DEFAULT
        #define __BD_POSITION sf::Vector2f(0.f, 0.f)
        #define __BD_SIZE sf::Vector2f(130, 35)
        #define __BD_COLOR sf::Color(10, 110, 240)
        #define __BD_COLOR_HOVER sf::Color(30, 130, 255)
        #define __BD_COLOR_PRESS sf::Color(10, 90, 210)
        #define __BD_TEXT sf::Text()
        #define __BD_TEXT_COLOR sf::Color::Black

        #define __BD_DISABLE_ALPHA_VALUE 100
        
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::RectangleShape shape;
        sf::Color color;
        sf::Color colorHover;
        sf::Color colorPress;

        sf::Text text;
        sf::Color textColor;

        bool click, clickControl;
        bool press;
        bool hover;

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        Button();
        Button(sf::FloatRect bounds);
        ~Button();

    private:
        void centerText();
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        // getter / setter
        const bool& getClick() const;
        const bool& getPress() const;
        
        // controls
        const sf::Vector2f& getPosition() const;
        const sf::Vector2f& getSize() const;
        const sf::Color& getColor() const;
        const sf::Color& getColorHover() const;
        const sf::Color& getColorPress() const;
        const sf::Color& getTextColor() const;
        const sf::Text& getText() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setPosition(const sf::Vector2f& pos);
        void setSize(const sf::Vector2f& size);
        void setColor(const sf::Color& color);
        void setColorHover(const sf::Color& color);
        void setColorPress(const sf::Color& color);
        void setTextColor(const sf::Color& color);
        void setText(const sf::Text& text);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}




#endif