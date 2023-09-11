#ifndef IMAGEBOX_HPP
#define IMAGEBOX_HPP

#include <SFML/Graphics.hpp>

// SimpleGUI
namespace sgui{
    class ImageBox{
        // IMAGEBOX DEFAULT
        #define __IBD_POSITION sf::Vector2f(0.f, 0.f)
        #define __IBD_IMAGE sf::String("./src/default.png")
        #define __IBD_COLOR_IMAGE sf::Color(255, 255, 255)
        #define __IBD_COLOR_BACKGROUND sf::Color(0, 0, 0)
        
        sf::String imagePath;
        sf::Texture imageTexture;
        sf::IntRect imageTextureTrim;

        sf::Vector2f pos;
        sf::Sprite image;
        sf::RectangleShape background;

        sf::Color colorImage;
        sf::Color colorBackground;

        bool freeze;
        bool visible;

        void initData();
        void buildTextures();

    public:
        ImageBox();
        ImageBox(const sf::String& imagePath);
        ImageBox(const sf::String& imagePath, sf::Vector2f pos);
        ~ImageBox();

    private:
        void updateTextureState();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;
        
        // controls
        const sf::String& getImagePath() const;
        const sf::IntRect& getImageTextureTrim() const;
        const sf::Vector2f& getPosition() const;
        const sf::Color& getColorImage() const;
        const sf::Color& getColorBackground() const;
        const bool& getVisible() const;


        void setImagePath(const sf::String& imagePath);
        void setImageTextureTrim(const sf::IntRect& imageTextureTrim);
        void setPosition(const sf::Vector2f& bounds);
        void setColorImage(const sf::Color& color);
        void setColorBackground(const sf::Color& color);
        void setVisible(const bool& visible);
    };
}


#endif