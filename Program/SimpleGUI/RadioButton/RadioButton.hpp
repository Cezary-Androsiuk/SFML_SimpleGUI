#ifndef RADIOBUTTON_HPP
#define RADIOBUTTON_HPP

#include <vector>

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui{
    class RadioButton{
        // RADIOBUTTON DEFAULT
        #define __RBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __RBD_RADIUS 15.f
        #define __RBD_COLOR_BORDER sf::Color(10, 90, 210)
        #define __RBD_COLOR_BACKGROUND sf::Color(0, 0, 0, 0)
        #define __RBD_COLOR_HOVER sf::Color(10, 90, 210, 80)
        #define __RBD_COLOR_CHECKED sf::Color(10, 90, 210)

        #define __RBD_DISABLE_ALPHA_PCT 100.f/255.f
        #define __RBD_BORDER_RATIO 0.20f
        #define __RBD_BORDER_CHECKED_RATIO 0.50f
        
        struct Bounds{
            sf::Vector2f pos;
            float radius;
        } bounds;
        sf::CircleShape border;
        sf::CircleShape background;
            sf::CircleShape shapeChecked;

        sf::Color colorBorder;
        sf::Color colorBackground;
            sf::Color colorHover;
            sf::Color colorChecked;

        std::vector<sgui::RadioButton *const> group;

        bool check_on, checkControl;
        bool state;
        bool hover;

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        RadioButton();
        RadioButton(sf::Vector2f pos);
        RadioButton(sf::Vector2f pos, float radius);
        ~RadioButton();

    private:
        void updateTextureState();

    protected:
        void setGroup(const std::vector<sgui::RadioButton *const> group);

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        // getter / setter
        const bool& getChecked_on() const;
        static void createGroup(std::vector<sgui::RadioButton *const> group); // to create group that will contain up to one selected RadioButton
        
        // controls
        const bool& getCheckState() const;
        const sf::Vector2f& getPosition() const;
        const float& getRadius() const;
        const sf::Color& getColorBorder() const;
        const sf::Color& getColorBackground() const;
        const sf::Color& getColorHover() const;
        const sf::Color& getColorChecked() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setCheckState(const bool& state);
        void setPosition(const sf::Vector2f& pos);
        void setRadius(const float& radius);
        void setColorBorder(const sf::Color& color);
        void setColorBackground(const sf::Color& color);
        void setColorHover(const sf::Color& color);
        void setColorChecked(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}


#endif