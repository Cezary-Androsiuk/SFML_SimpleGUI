#include "Program.hpp"

void Program::initParams()
{

}

void Program::initWindow()
{
    this->videoMode = sf::VideoMode(WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
    this->window = new sf::RenderWindow(this->videoMode, "Environment for switch element", sf::Style::None);
    this->window->setPosition(sf::Vector2i(
        (/*videoMode.width*/ 1920 - this->window->getSize().x)/2,
        (/*videoMode.height*/ 1080 - this->window->getSize().y)/2)
    );
    this->window->setFramerateLimit(FPS);
    printf("window: %ux%u\n",this->window->getSize().x, this->window->getSize().y);
}

void Program::initObjects()
{
    this->s = new sgui::Switch(10, 60, 400, 100, false);
}

Program::Program()
{
    this->initParams();
    this->initWindow();
    this->initObjects();
}

Program::~Program()
{
    delete this->s;
    delete this->window;
}

void Program::events()
{
    
}

void Program::update()
{
    while(this->window->pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed){
            this->window->close();
        }
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape){
            this->window->close();
        }

        this->s->update(&this->event);
    }
}

void Program::render()
{
    this->window->clear(sf::Color(30, 30, 30));

    this->s->render(this->window);
    
    this->window->display();
}


bool Program::running() const
{
    return this->window->isOpen();
}