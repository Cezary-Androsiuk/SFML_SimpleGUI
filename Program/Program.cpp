#include "Program.hpp"

void Program::initParams()
{

}

void Program::initFonts()
{
    this->font.loadFromFile(STANDARD_FONT_PATH);
}

void Program::initWindow()
{
    this->videoMode = sf::VideoMode(WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window = new sf::RenderWindow(this->videoMode, "Environment for switch element", sf::Style::None, settings);
    
    this->window->setPosition(sf::Vector2i(
        (/*videoMode.width*/ 1920 - this->window->getSize().x)/2,
        (/*videoMode.height*/ 1080 - this->window->getSize().y)/2)
    );
    this->window->setFramerateLimit(FPS);
    printf("window: %ux%u\n",this->window->getSize().x, this->window->getSize().y);
}

void Program::initObjects()
{
    for(int i=0; i<10; i++)
        this->switches.push_back(new sgui::Switch(sf::FloatRect(100, 60 + i*25, 174/4, 88/4), false, sf::Color(10, 110, 240), sf::Color(180, 180, 180), sf::Color(255, 255, 255)));

    for(int i=0; i<10; i++)
        this->buttons.push_back(new sgui::Button(sf::FloatRect(200, 60 + i*38, 260/2, 70/2), sf::Text("Touch ME!", this->font, 1+i*2), sf::Color::White,
        sf::Color(10, 110, 240), sf::Color(30, 130, 255), sf::Color(10, 90, 210)));

}

Program::Program()
{
    this->initParams();
    this->initWindow();
    this->initFonts();
    this->initObjects();
}

Program::~Program()
{
    for(const auto& s : this->switches)
        delete s;
    for(const auto& b : this->buttons)
        delete b;
    delete this->window;
}

void Program::events()
{
    
}

void Program::update()
{
    while(this->window->pollEvent(this->event)){
        if(this->event.type == sf::Event::Closed){
            this->window->close();
        }
        else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape){
            this->window->close();
        }

        for(const auto& s : this->switches)
            s->event(this->event);
        for(const auto& b : this->buttons)
            b->event(this->event);
    }

    for(const auto& s : this->switches)
        s->update();
    for(const auto& b : this->buttons)
        b->update();


    int si=0;
    for(const auto& s : this->switches){
        if(s->getSwitched_on()){
            printf("switch %d was turned on\n", si);
        }
        if(s->getSwitched_off()){
            printf("switch %d was turned off\n", si);
        }
        si++;
    }
    int bi=0;
    for(const auto& b : this->buttons){
        if(b->getButtonClick()){
            printf("button %d was pressed\n", bi);
            if(bi == 1){
                if(this->switches[1]->getEnable())
                    this->switches[1]->setEnable(false);
                else
                    this->switches[1]->setEnable(true);

            }
            if(bi == 2){
                if(this->switches[2]->getVisible())
                    this->switches[2]->setVisible(false);
                else
                    this->switches[2]->setVisible(true);

            }
            if(bi == 3){
                if(this->buttons[1]->getEnable())
                    this->buttons[1]->setEnable(false);
                else
                    this->buttons[1]->setEnable(true);

            }
            if(bi == 4){
                if(this->buttons[2]->getVisible())
                    this->buttons[2]->setVisible(false);
                else
                    this->buttons[2]->setVisible(true);

            }
        }
        bi++;
    }

}

void Program::render()
{
    this->window->clear(sf::Color(30, 30, 30));

    for(const auto& s : this->switches)
        s->render(this->window);

    for(const auto& b : this->buttons)
        b->render(this->window);
    
    this->window->display();
}


bool Program::running() const
{
    return this->window->isOpen();
}