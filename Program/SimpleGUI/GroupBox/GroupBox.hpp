#ifndef GROUPBOX_HPP
#define GROUPBOX_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "../SimpleGUI.hpp"

namespace sgui{
    class GroupBox : public SGUI{
        // GROUPBOX DEFAULT
        #define __GBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __GBD_SIZE sf::Vector2f(1280.f, 720.f)
        #define __GBD_COLOR_BACKGROUND sf::Color(255, 255, 255, 0)

        #define __GBD_DISABLE_ALPHA_PCT 100.f/255.f
        
        sf::FloatRect bounds;
        sf::RectangleShape background;

        sf::Color colorBackground;
        
        //* Elements in GroupBox
        std::vector<sgui::SGUI> objects;
        //*/

        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        GroupBox();
        GroupBox(sf::FloatRect bounds);
        ~GroupBox();

    private:
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;
        
        // controls
        const sf::FloatRect& getBounds() const;
        const sf::Color& getColorBackground() const;
        const bool& getEnable() const;
        const bool& getVisible() const;


        void setBounds(const sf::FloatRect& bounds);
        void setColorBackground(const sf::Color& color);
        void setEnable(const bool& enable);
        void setVisible(const bool& visible);
    };
}

#endif