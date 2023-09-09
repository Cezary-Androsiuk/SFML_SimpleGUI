#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cstdio>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui
{
    class Switch
    {
        #define SWITCH_SWITCHER_SIZE_RATIO 0.9f

        struct Background{
            sf::FloatRect globalBounds;
            sf::CircleShape left;
            sf::RectangleShape middle;
            sf::CircleShape right;
        } background;
        sf::CircleShape switcher;

        bool currentState;
        // sf::Vector2f position;

        bool mouseLeftKeyPressed;
        
        void buildTextures();
        void initData();

    public:
        Switch(float x, float y, float width, float height, bool state);
        Switch(sf::Vector2f position, sf::Vector2f size, bool state);
        Switch(sf::FloatRect floatRect, bool state);
        ~Switch();

    private:
        bool determineHitBoxPart(float mousePos) const;
        float determineMoveCircle(float mousePos) const;

    public:
        void update(const sf::Event* event);
        void render(sf::RenderTarget* window) const;

        void setSwitchState(bool state);
        const bool& getSwitchState() const;

    };
}




#endif