#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/Graphics.hpp>

#include "SimpleGUI.hpp"

#define WIN_SIZE_WIDTH 1280
#define WIN_SIZE_HEIGHT 720
#define FPS 120

#define STANDARD_FONT_PATH "./res/fonts/OpenSans-Regular.ttf"

class Program
{
private:
    
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::Font font;

    std::vector<sgui::Switch*> switches;
    std::vector<sgui::Button*> buttons;
    std::vector<sgui::CheckBox*> checkBoxes;
    std::vector<sgui::ImageBox*> imageBoxes;
    std::vector<sgui::RadioButton*> radioButtons1;
    std::vector<sgui::RadioButton*> radioButtons2;
    std::vector<sgui::GroupBox*> groupBoxes;
    std::vector<sgui::TabControl*> tabControlls;
    std::vector<sgui::Label*> labels;

    void initParams();
    void initFonts();
    void initWindow();
    void initObjects();
public:
    Program();
    ~Program();
private:

    void events();
public:
    void update();
    void render();

    bool running() const;
};

#endif