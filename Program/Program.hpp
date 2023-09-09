#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/Graphics.hpp>

#include "SimpleGUI/SimpleGUI.hpp"

#define WIN_SIZE_WIDTH 1280
#define WIN_SIZE_HEIGHT 720
#define FPS 120

class Program
{
private:
    
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sgui::Switch* s;

    void initParams();
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