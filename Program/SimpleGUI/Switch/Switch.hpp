#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cmath>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Switch
    {
        // SWITCH DEFAULT
        #define __SD_POSITION sf::Vector2f(0.f, 0.f)
        #define __SD_SIZE sf::Vector2f(43, 22)
        #define __SD_STATE false
        #define __SD_BACKGROUND_COLOR_ON sf::Color(10, 90, 210)
        #define __SD_BACKGROUND_COLOR_OFF sf::Color(180, 180, 180)
        #define __SD_SWITCH_COLOR sf::Color(255, 255, 255)
        #define __SD_SHADOW_COLOR sf::Color(100, 100, 100, 40)

        #define __SD_DISABLE_ALPHA_VALUE 100
        #define __SD_HANDLE_SIZE_RATIO 0.75f
        #define __SD_SHADOW_SIZE_RATIO 0.9f

        sf::FloatRect bounds;
        struct Background{
            sf::RectangleShape shape;
            sf::Color color_on;
            sf::Color color_off;
        } background;

        struct _Switch{
            sf::RectangleShape shape;
            sf::Color color;
            sf::RectangleShape shadow;
            sf::Color shadowColor;

            struct MoveRange{
                sf::Vector2f left;
                sf::Vector2f right;
                sf::Vector2f shadowLeft;
                sf::Vector2f shadowRight;
            } moveRange;
        } _switch;


        bool switched_on, switched_off;
        bool switchedControl;
        bool state;

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        Switch();
        Switch(sf::FloatRect bounds);
        Switch(sf::FloatRect bounds, bool state);
        ~Switch();

    private:
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;


        // getter / setter
        const bool& getSwitched_on() const;
        const bool& getSwitched_off() const;

        // controls
        const bool& getSwitchState() const;
        const sf::FloatRect& getBounds() const;
        const sf::Color& getBackgroundColor_on() const;
        const sf::Color& getBackgroundColor_off() const;
        const sf::Color& getSwitchColor() const;
        const sf::Color& getShadowColor() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setSwitchState(bool state);
        void setBounds(const sf::FloatRect& size);
        void setBackgroundColor_on(const sf::Color& color);
        void setBackgroundColor_off(const sf::Color& color);
        void setSwitchColor(const sf::Color& color);
        void setShadowColor(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}




#endif