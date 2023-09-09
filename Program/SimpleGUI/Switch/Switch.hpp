#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cstdio>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Switch
    {
        #define SWITCH_HANDLE_SIZE_RATIO 0.75f
        #define SWITCH_SHADOW_SIZE_RATIO 0.85f

        sf::Vector2f position;
        struct Background{
            sf::FloatRect globalBounds;
            sf::CircleShape left;
            sf::RectangleShape middle;
            sf::CircleShape right;
            sf::Color color_on;
            sf::Color color_off;
        } background;

        struct _Switch{
            sf::CircleShape handle;
            sf::Color color;
            sf::CircleShape shadow;

            struct MoveRange{
                sf::Vector2f left;
                sf::Vector2f right;
                sf::Vector2f shadowLeft;
                sf::Vector2f shadowRight;
            }
            moveRange;
        } _switch;


        bool currentState;
        bool mouseLeftKeyPressed;

        void buildTextures();

    public:
        Switch(sf::FloatRect floatRect, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switcherColor);
        ~Switch();

    private:
        void updateState();

    public:
        void update(const sf::Event* event);
        void render(sf::RenderTarget* window) const;

        void setSwitchState(bool state);
        const bool& getSwitchState() const;

    };
}




#endif