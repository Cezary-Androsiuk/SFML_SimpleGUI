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
        this->switches.push_back(new sgui::Switch(sf::FloatRect(100, 60 + i*25, 174/4, 88/4), false));

    for(int i=0; i<10; i++){
        sgui::Button* b = new sgui::Button(sf::FloatRect(200, 60 + i*38, 260/2, 70/2));
        b->setText(sf::Text("Touch ME!", this->font, 1+i*2));
        this->buttons.push_back(b);
    }

    for(int i=0; i<10; i++){
        sgui::CheckBox* cb = new sgui::CheckBox(sf::Vector2f(350, 60 + i*33), 30.f);
        this->checkBoxes.push_back(cb);
    }

    for(int i=0; i<1; i++){
        sgui::ImageBox* ib = new sgui::ImageBox("./res/images/default.png", sf::FloatRect(400, 60, 480, 270));
        // ib->setBounds(sf::FloatRect(0, 0, 460, 250));
        ib->setColorBackground(sf::Color::Transparent);
        this->imageBoxes.push_back(ib);
    }

    for(int i=0; i<3; i++){
        sgui::RadioButton* rb = new sgui::RadioButton(sf::Vector2f(900, 60 + i*33), 15.f);
        this->radioButtons1.push_back(rb);
    }
    sgui::RadioButton::createGroup(this->radioButtons1);

    for(int i=0; i<4; i++){
        sgui::RadioButton* rb = new sgui::RadioButton(sf::Vector2f(900, 60 + 4*33 + i*33), 15.f);
        this->radioButtons2.push_back(rb);
    }
    sgui::RadioButton::createGroup(this->radioButtons2);

    this->groupBoxes.push_back(new sgui::GroupBox(sf::FloatRect(100, 500, 200, 50)));
    this->groupBoxes[0]->setColorBackground(sf::Color(40,40,40));
    this->groupBoxes[0]->addObject(new sgui::Button(sf::FloatRect(10,10,52,14)));
    this->groupBoxes[0]->addObject(new sgui::Button(sf::FloatRect(70,10,52,14)));

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
    for(const auto& cb : this->checkBoxes)
        delete cb;
    for(const auto& ib : this->imageBoxes)
        delete ib;
    for(const auto& rb : this->radioButtons1)
        delete rb;
    for(const auto& rb : this->radioButtons2)
        delete rb;
    for(const auto& gb : this->groupBoxes)
        delete gb;

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
        for(const auto& cb : this->checkBoxes)
            cb->event(this->event);
        for(const auto& ib : this->imageBoxes)
            ib->event(this->event);
        for(const auto& rb : this->radioButtons1)
            rb->event(this->event);
        for(const auto& rb : this->radioButtons2)
            rb->event(this->event);
        for(const auto& gb : this->groupBoxes)
            gb->event(this->event);
    }

    for(const auto& s : this->switches)
        s->update();
    for(const auto& b : this->buttons)
        b->update();
    for(const auto& cb : this->checkBoxes)
        cb->update();
    for(const auto& ib : this->imageBoxes)
        ib->update();
    for(const auto& rb : this->radioButtons1)
        rb->update();
    for(const auto& rb : this->radioButtons2)
        rb->update();
    for(const auto& gb : this->groupBoxes)
        gb->update();


    // ####################################################################################### TEST SECTION
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
    if(this->switches[9]->getState()){
        for(const auto& s : this->switches){
            s->setBackgroundColor_on(sf::Color(rand()%255,rand()%255,rand()%255));
        }
    }
    int bi=0;
    for(const auto& b : this->buttons){
        if(b->getClick()){
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
    int cbi=0;
    for(const auto& cb : this->checkBoxes){
        if(cb->getChecked_on()){
            printf("checkbox %d was checked\n", cbi);
        }
        if(cb->getChecked_off()){
            printf("checkbox %d was unchecked\n", cbi);
        }
        cbi++;
    }

    int rbi=0;
    for(const auto& rb : this->radioButtons1){
        if(rb->getChecked_on())
            printf("radiobutton1 %d is selected\n", rbi);
        rbi++;
    }

    rbi=0;
    for(const auto& rb : this->radioButtons2){
        if(rb->getChecked_on())
            printf("radiobutton2 %d is selected\n", rbi);
        rbi++;
    }

    auto gropBoxObjects = this->groupBoxes[0]->getAllObjects();
    if(typeid(*gropBoxObjects[0]) == typeid(sgui::Button)){
        sgui::Button* b1 = dynamic_cast<sgui::Button*>(gropBoxObjects[0]);
        if(b1->getClick())
            printf("B1 was Clicked!\n");
    }
    else fprintf(stderr, "object is not a button!\n");
    if(typeid(*gropBoxObjects[1]) == typeid(sgui::Button)){
        sgui::Button* b2 = dynamic_cast<sgui::Button*>(gropBoxObjects[1]);
        if(b2->getClick())
            printf("B2 was Clicked!\n");
    }
    else fprintf(stderr, "object is not a button!\n");
    // ####################################################################################### TEST SECTION
}

void Program::render()
{
    this->window->clear(sf::Color(30, 30, 30));

    // sf::View v(sf::FloatRect(0,0,480, 270));
    // this->window->setView(v);

    for(const auto& s : this->switches)
        s->render(this->window);
    for(const auto& b : this->buttons)
        b->render(this->window);
    for(const auto& cb : this->checkBoxes)
        cb->render(this->window);
    for(const auto& ib : this->imageBoxes)
        ib->render(this->window);
    for(const auto& rb : this->radioButtons1)
        rb->render(this->window);
    for(const auto& rb : this->radioButtons2)
        rb->render(this->window);
    for(const auto& gb : this->groupBoxes)
        gb->render(this->window);

    this->window->display();
}


bool Program::running() const
{
    return this->window->isOpen();
}