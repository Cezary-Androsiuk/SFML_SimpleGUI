#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cstdio>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Switch
    {
        #define SWITCH_SWITCHER_SIZE_RATIO 0.75f

        sf::Vector2f position;
        struct Background{
            sf::FloatRect globalBounds;
            sf::CircleShape left;
            sf::RectangleShape middle;
            sf::CircleShape right;
            sf::Color color_on;
            sf::Color color_off;
        } background;
        sf::CircleShape switcher;
        sf::Color switcherColor;

        struct MoveRange{
            sf::Vector2f left;
            sf::Vector2f right;
        }
        moveRange;

        bool currentState;

        void buildTextures();

    public:
        // Switch(float x, float y, float width, float height, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switcherColor);
        // Switch(sf::Vector2f position, sf::Vector2f size, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switcherColor);
        Switch(sf::FloatRect floatRect, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switcherColor);
        ~Switch();

    private:
        // bool determineHitBoxPart(float mousePos) const;
        // float determineMoveCircle(float mousePos) const;
        void updateState();

    public:
        void update(const sf::Event* event);
        void render(sf::RenderTarget* window) const;

        void setSwitchState(bool state);
        const bool& getSwitchState() const;

    };
}




#endif