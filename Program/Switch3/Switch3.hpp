#ifndef SWITCH3_HPP
#define SWITCH3_HPP

#include <cstdio>

#include <SFML/Graphics.hpp>


// Window Object
namespace obj
{
    #define SLIDER_TEXTURE_PATH "src/slider.png"
    #define CIRCLE_TEXTURE_PATH "src/circle.png"
    #define SWITCH_TEXTURE_PATH "src/Switch.png"

    class Switch3
    {
    public:
        enum SwitchState
        {
            On,  // left position
            None, // mid position
            Off // right position
        };

    private:
        bool mouseLeftKeyPressed;
        
        sf::RectangleShape hitBox;
        sf::Texture sliderTexture;
        sf::Texture circleTexture;
        sf::Texture switchTexture;
        sf::Sprite slider;
        sf::Sprite circle;
        sf::Sprite switchSprite;

        Switch3::SwitchState currentState;
        sf::Vector2f position;

        void initTextures();
        void initData();

    public:
        Switch3(sf::Vector2f position, Switch3::SwitchState state);
        ~Switch3();

    private:
        Switch3::SwitchState determineHitBoxPart(float mousePos) const;
        float determineMoveCircle(float mousePos) const;

    public:
        void update(const sf::Event* event);
        void render(sf::RenderTarget* window) const;

        void setSwitch3State(Switch3::SwitchState state);
        Switch3::SwitchState getSwitch3State() const;

    };
}




#endif