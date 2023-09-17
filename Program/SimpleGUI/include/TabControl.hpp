#ifndef TABCONTROL_HPP
#define TABCONTROL_HPP

#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "SguiObject.hpp"
#include "GroupBox.hpp"

namespace sgui{
    class TabControl : public SguiObject{
        // TABCONTROL DEFAULT
        #define __TCD_POSITION sf::Vector2f(0.f, 0.f)
        #define __TCD_SIZE sf::Vector2f(640.f, 360.f)
        #define __TCD_TAB_SIZE sf::Vector2f(70.f, 20.f)
        #define __TCD_TAB_NAME std::string("tab")

        #define __TCD_COLOR_TAB sf::Color(10, 90, 210)
        #define __TCD_COLOR_TAB_HOVER sf::Color(10, 90, 210, 80)
        #define __TCD_COLOR_TAB_CHECKED sf::Color(10, 90, 210)
        #define __TCD_COLOR_BACKGROUND sf::Color::Transparent

        #define __TCD_DISABLE_ALPHA_PCT 100.f/255.f
        
        sf::Vector2f pos;
        sf::Vector2f size;
        std::string currentTab;
        // std::vector<std::string> tabNames;
        std::map<std::string, sgui::GroupBox*> tabs;

        sf::Color colorTab;
        sf::Color colorTabHover;
        sf::Color colorTabChecked;
        sf::Color colorBackground;
        sf::Vector2f tabButtonSize;
        
        bool enable;
        bool visible;

        void initData();
        void buildTextures();

    public:
        TabControl();
        TabControl(sf::FloatRect bounds, std::string tabName);
        ~TabControl();

    private:
        void createTab(std::string tabName);
        void centerText(sf::Text& text, const sf::FloatRect& shape);
        void updateShapes();
        void updateColors();
        void updatePosition();

    public:
        void event(const sf::Event& event);
        void update();
        void render(sf::RenderTarget* window) const;
        
        // getters
        const sf::Vector2f& getPosition() const;
        // const sf::Vector2f& getSize() const;
        // const sf::Color& getColorTab() const;
        // const sf::Color& getColorTabHover() const;
        // const sf::Color& getColorTabChecked() const;
        const sf::Color& getColorBackground() const;
        // const sf::Vector2f& getTabButtonSize() const;
        const std::string& getCurrentTab() const;
        // const bool& getTabEnable(std::string tabName) const;
        // const bool& getTabVisible(std::string tabName) const;
        // const bool& getEnable() const;
        // const bool& getVisible() const;

        // // setters
        void setPosition(const sf::Vector2f& pos);
        // void setSize(const sf::Vector2f& size);
        // void setColorTab(const sf::Color& color);
        // void setColorTabHover(const sf::Color& color);
        // void setColorTabChecked(const sf::Color& color);
        void setColorBackground(const sf::Color& color);
        // void setTabButtonSize(const sf::Vector2f& size);
        bool setCurrentTab(const std::string& tabName);
        // void setTabEnable(std::string tabName, const bool& enable);
        // void setTabVisible(std::string tabName, const bool& visible);
        // void setEnable(const bool& enable);
        // void setVisible(const bool& visible);

        // other
        bool addTab(std::string tabName);
        std::vector<std::string> getTabs() const;
        // to remove/modify/getResponse from a single object 
        std::vector<sgui::SguiObject*>& getAllObjects(std::string tabName);
        // to add object call for example: groupBox->addObject(new sgui::Button());
        // objects position is relative to groupBox and they will be deleted while deleting groupBox
        bool addObject(std::string tabName, sgui::SguiObject* object);
    };
}

#endif