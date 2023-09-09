#include "Switch.hpp"




void sgui::Switch::buildTextures()
{
    // COMPUTING
    this->position = sf::Vector2f(this->background.globalBounds.left, this->background.globalBounds.top);

    float x = this->background.globalBounds.left, y = this->background.globalBounds.top;
    float width = this->background.globalBounds.width, height = this->background.globalBounds.height;
    float switcherHeight = height * SWITCH_SWITCHER_SIZE_RATIO;
    float borderSize = (height - switcherHeight)/2;

    this->moveRange.left = sf::Vector2f{
        this->position.x + borderSize,
        this->position.y + borderSize
    };
    this->moveRange.right = sf::Vector2f(
        (this->position.x + this->background.globalBounds.width - switcherHeight - borderSize),
        this->position.y + borderSize 
    );

    
    // SET SIZE AND POSITION
    this->background.left.setRadius(height/2);
    this->background.left.setPosition(this->position);

    this->background.middle.setSize(sf::Vector2f(width - height, height));
    this->background.middle.setPosition(sf::Vector2f(this->position.x + height/2, this->position.y));

    this->background.right.setRadius(height/2);
    this->background.right.setPosition(sf::Vector2f(this->position.x + width -height, this->position.y));

    this->switcher.setRadius(switcherHeight/2);

    this->updateState();
    this->switcher.setFillColor(this->switcherColor);

}


sgui::Switch::Switch(sf::FloatRect floatRect, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switcherColor)
{
    this->background.color_on = backgroundColor_on;
    this->background.color_off = backgroundColor_off;
    this->switcherColor = switcherColor;
    this->background.globalBounds = floatRect;
    this->currentState = state;
    this->buildTextures();

}


sgui::Switch::~Switch()
{

}




void sgui::Switch::updateState(){
    if(this->currentState){
        this->background.left.setFillColor(this->background.color_on);
        this->background.middle.setFillColor(this->background.color_on);
        this->background.right.setFillColor(this->background.color_on);
        this->switcher.setPosition(this->moveRange.right);
    }
    else{
        this->background.left.setFillColor(this->background.color_off);
        this->background.middle.setFillColor(this->background.color_off);
        this->background.right.setFillColor(this->background.color_off);
        this->switcher.setPosition(this->moveRange.left);
    }
}


void sgui::Switch::update(const sf::Event* event)
{
    if(event->type == sf::Event::MouseButtonReleased && event->mouseButton.button == sf::Mouse::Left){
        if(this->background.left.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y) || 
        this->background.middle.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y) || 
        this->background.right.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
        if(this->currentState)
            this->currentState = false;
        else 
            this->currentState = true;
        this->updateState();
    }
}



void sgui::Switch::render(sf::RenderTarget* window) const
{
    window->draw(this->background.middle);
    window->draw(this->background.left);
    window->draw(this->background.right);
    window->draw(this->switcher);
}





void sgui::Switch::setSwitchState(bool state)
{
    this->currentState = state;
    this->updateState();
}



const bool& sgui::Switch::getSwitchState() const
{
    return this->currentState;
}