#ifndef RADIOBUTTON_HPP
#define RADIOBUTTON_HPP

#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "../SguiObject/SguiObject.hpp"

// SimpleGUI
namespace sgui{
    class RadioButton : public SguiObject{
        // RADIOBUTTON DEFAULT
        #define __RBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __RBD_RADIUS 15.f
        #define __RBD_COLOR_BORDER sf::Color(10, 90, 210)
        #define __RBD_COLOR_BACKGROUND sf::Color(255, 255, 255, 0)
        #define __RBD_COLOR_HOVER sf::Color(10, 90, 210, 80)
        #define __RBD_COLOR_CHECKED sf::Color(10, 90, 210)

        #define __RBD_DISABLE_ALPHA_PCT 100.f/255.f
        #define __RBD_BORDER_RATIO 0.20f
        #define __RBD_BORDER_CHECKED_RATIO 0.50f
        
        sf::FloatRect bounds;
        sf::CircleShape border;
        sf::CircleShape background;
            sf::CircleShape shapeChecked;

        sf::Color colorBorder;
        sf::Color colorBackground;
            sf::Color colorHover;
            sf::Color colorChecked;

        std::vector<sgui::RadioButton *> group;

        bool check_on, checkControl;
        bool state;
        bool hover;

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        RadioButton();
        RadioButton(sf::FloatRect bounds);
        ~RadioButton();

    private:
        void updateTextureState();
        bool contains(float x, float y) const;
        bool contains(sf::Vector2f point) const;
        void diselectGroup() const; // const because does not change THIS object

    protected:
        void setGroup(const std::vector<sgui::RadioButton *>& group);

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;

        // getter / setter
        const bool& getChecked_on() const;
        
        // controls
        const bool& getState() const;
        const sf::FloatRect& getBounds() const;
        const sf::Color& getColorBorder() const;
        const sf::Color& getColorBackground() const;
        const sf::Color& getColorHover() const;
        const sf::Color& getColorChecked() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setState(const bool& state);
        void setBounds(const sf::FloatRect& bounds);
        void setColorBorder(const sf::Color& color);
        void setColorBackground(const sf::Color& color);
        void setColorHover(const sf::Color& color);
        void setColorChecked(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);

        // static
        static void changeGroup(const std::vector<sgui::RadioButton *>& group); // to create group that will contain up to one selected RadioButton
    };
}


#endif