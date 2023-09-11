#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class CheckBox
    {
        // CHECKBOX DEFAULT
        #define __CBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __CBD_SIZE 30.f
        #define __CBD_STATE false
        #define __CBD_COLOR_BORDER sf::Color(10, 90, 210)
        #define __CBD_COLOR_BACKGROUND sf::Color(0, 0, 0, 0)
        #define __CBD_COLOR_HOVER sf::Color(10, 90, 210, 80)
        #define __CBD_COLOR_HOVER_CHECKED sf::Color(10, 90, 210, 200)
        #define __CBD_COLOR_CHECKED sf::Color(10, 90, 210)

        #define __CBD_DISABLE_ALPHA_PCT 100.f/255.f
        #define __CBD_BORDER_RATIO 0.20f
        #define __CBD_BORDER_CHECKED_RATIO 0.50f
        
        struct Bounds{
            sf::Vector2f pos;
            float size;
        } bounds;
        sf::RectangleShape border;
        sf::RectangleShape background;
            sf::RectangleShape shapeChecked;

        sf::Color colorBorder;
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
        CheckBox(sf::Vector2f position);
        CheckBox(sf::Vector2f position, float size);
        CheckBox(sf::Vector2f position, float size, bool state);
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
        const sf::Vector2f& getPosition() const;
        const float& getSize() const;
        const sf::Color& getColorBackground() const;
        const sf::Color& getColorHover() const;
        const sf::Color& getColorHoverChecked() const;
        const sf::Color& getColorChecked() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setCheckState(const bool& size);
        void setPosition(const sf::Vector2f& pos);
        void setSize(const float& size);
        void setColorBackground(const sf::Color& color);
        void setColorHover(const sf::Color& color);
        void setColorHoverChecked(const sf::Color& color);
        void setColorChecked(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}




#endif