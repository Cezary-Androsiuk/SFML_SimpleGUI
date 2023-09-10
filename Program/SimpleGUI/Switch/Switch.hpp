#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cstdio>
#include <cmath>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Switch
    {
        #define SWITCH_HANDLE_SIZE_RATIO 0.75f
        #define SWITCH_SHADOW_SIZE_RATIO 0.9f
        #define SWITCH_BACKGROUND_DISABLE_COLOR_ON sf::Color(120, 120, 120)
        #define SWITCH_BACKGROUND_DISABLE_COLOR_OFF sf::Color(140, 140, 140)
        #define SWITCH_HANDLE_DISABLE_COLOR sf::Color(190,190,190)

        sf::Vector2f position;
        struct Background{
            sf::FloatRect globalBounds;
            sf::RectangleShape shape;
            sf::Color color_on;
            sf::Color color_off;
        } background;

        struct _Switch{
            sf::RectangleShape shape;
            sf::Color color;
            sf::RectangleShape shadow;

            struct MoveRange{
                sf::Vector2f left;
                sf::Vector2f right;
                sf::Vector2f shadowLeft;
                sf::Vector2f shadowRight;
            } moveRange;
        } _switch;


        bool switched_on, switched_off;
        bool switchedControl;

        bool currentState;
        bool mouseLeftKeyPressed;

        bool enable;
        bool visible;

        void buildTextures();

    public:
        Switch(sf::FloatRect floatRect, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switchColor);
        ~Switch();

    private:
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        void setSwitchState(bool state);
        const bool& getSwitchState() const;

        const bool& getSwitched_on() const;
        const bool& getSwitched_off() const;

        const bool& getEnable() const;
        void setEnable(const bool& enabled);

        const bool& getVisible() const;
        void setVisible(const bool& visibled);

    };
}




#endif