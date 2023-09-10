#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <cmath>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class CheckBox
    {
        // CHECKBOX DEFAULT
        #define __CBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __CBD_SIZE sf::Vector2f(130, 35)
        #define __CBD_STATE false
        #define __CBD_COLOR_BACKGROUND sf::Color(0, 0, 0, 0)
        #define __CBD_COLOR_HOVER sf::Color(30, 130, 255)
        #define __CBD_COLOR_HOVER_CHECKED sf::Color(30, 130, 255)
        #define __CBD_COLOR_CHECKED sf::Color(10, 90, 210)

        #define __CBD_DISABLE_ALPHA_VALUE 100
        #define __CBD_BORDER_RATIO 0.05f
        #define __CBD_BORDER_CHECKED_RATIO 0.85f
        
        sf::FloatRect bounds;
        sf::RectangleShape shape;
        sf::RectangleShape background;
        sf::RectangleShape shape_checked;

        sf::Color colorBackground;
        sf::Color colorHover;
        sf::Color colorHoverChecked;
        sf::Color colorChecked;

        bool check_on, check_off, checkControl;
        bool state;
        bool hover;

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        CheckBox();
        CheckBox(sf::FloatRect bounds);
        CheckBox(sf::FloatRect bounds, bool state);
        ~CheckBox();

    private:
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        // getter / setter
        const bool& getChecked_on() const;
        const bool& getChecked_off() const;
        
        // controls
        const bool& getCheckState() const;
        const sf::FloatRect& getBounds() const;
        const sf::Color& getColorBackground() const;
        const sf::Color& getColorHover() const;
        const sf::Color& getColorHoverChecked() const;
        const sf::Color& getColorChecked() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setCheckState(const bool& size);
        void setBounds(const sf::FloatRect& size);
        void setColorBackground(const sf::Color& color);
        void setColorHover(const sf::Color& color);
        void setColorHoverChecked(const sf::Color& color);
        void setColorChecked(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}




#endif