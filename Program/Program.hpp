#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstdio>
#include <vector>

#include <SFML/Graphics.hpp>

#include "SimpleGUI/SimpleGUI.hpp"

#define WIN_SIZE_WIDTH 1280
#define WIN_SIZE_HEIGHT 720
#define FPS 120

#define STANDARD_FONT_PATH "./src/OpenSans-Regular.ttf"

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