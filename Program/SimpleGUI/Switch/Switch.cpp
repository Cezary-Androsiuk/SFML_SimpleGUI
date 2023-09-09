#include "Switch.hpp"




void sgui::Switch::buildTextures()
{
    sf::Vector2f position(this->background.globalBounds.left, this->background.globalBounds.top);

    float x = this->background.globalBounds.left, y = this->background.globalBounds.top;
    float width = this->background.globalBounds.width, height = this->background.globalBounds.height;

    

    this->background.left.setRadius(height/2);
    this->background.left.setPosition(position);

    this->background.middle.setSize(sf::Vector2f(width, height));
    this->background.middle.setPosition(sf::Vector2f(position.x + height/2, position.y));
    // this->background.middle.setFillColor(sf::Color::Red);

    this->background.right.setRadius(height/2);
    this->background.right.setPosition(sf::Vector2f(position.x + width, position.y));


}


void sgui::Switch::initData()
{
    this->mouseLeftKeyPressed = false;
}





sgui::Switch::Switch(float x, float y, float width, float height, bool state) : Switch(sf::FloatRect(x, y, width, height), state)
{
}

sgui::Switch::Switch(sf::Vector2f position, sf::Vector2f size, bool state) : Switch(sf::FloatRect(position, size), state)
{
}

sgui::Switch::Switch(sf::FloatRect floatRect, bool state)
{
    this->background.globalBounds = floatRect;
    this->currentState = state;
    this->buildTextures();
    this->initData();

}


sgui::Switch::~Switch()
{

}






bool sgui::Switch::determineHitBoxPart(float mousePos) const
{
    return false;
}


float sgui::Switch::determineMoveCircle(float mousePos) const
{
    return 0.f;
}



void sgui::Switch::update(const sf::Event* event)
{
    
    if(event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left)
    {   
        sf::Vector2f mousePos(event->mouseButton.x, event->mouseButton.y);
        if(this->background.globalBounds.contains(mousePos))
            this->mouseLeftKeyPressed = true;

    }
    else if(event->type == sf::Event::MouseButtonReleased && event->mouseButton.button == sf::Mouse::Left && mouseLeftKeyPressed){
        this->currentState = this->determineHitBoxPart(event->mouseButton.x);
        this->mouseLeftKeyPressed = false;
    }

    if(event->type == sf::Event::MouseMoved && this->mouseLeftKeyPressed){
        // float circleXPos = this->determineMoveCircle(event->mouseMove.x);
        this->currentState = this->determineHitBoxPart(event->mouseMove.x);
        // printf("%d | %d\n", mousePos.x, mousePos.y);
    }

    // this->switchSprite.setTextureRect(sf::IntRect(
    //     0, 
    //     this->switchTexture.getSize().y/3 * this->currentState, 
    //     this->switchTexture.getSize().x, 
    //     this->switchTexture.getSize().y/3
    // ));
    // if(this->currentState == Switch::SwitchState::On)
    //     this->circle.setColor(sf::Color(0,255,0,100));
    // else if(this->currentState == Switch::SwitchState::None)
    //     this->circle.setColor(sf::Color(0,0,0,100));
    // else if(this->currentState == Switch::SwitchState::Off)
    //     this->circle.setColor(sf::Color(255,0,0,100));
}



void sgui::Switch::render(sf::RenderTarget* window) const
{
    window->draw(this->background.middle);
    window->draw(this->background.left);
    window->draw(this->background.right);
}





void sgui::Switch::setSwitchState(bool state)
{
    this->currentState = state;
}



const bool& sgui::Switch::getSwitchState() const
{
    return this->currentState;
}