#include "Switch3.hpp"


void obj::Switch3::initTextures()
{
    if(!this->sliderTexture.loadFromFile(SLIDER_TEXTURE_PATH))
        exit(1);
    if(!this->circleTexture.loadFromFile(CIRCLE_TEXTURE_PATH))
        exit(1);
    if(!this->switchTexture.loadFromFile(SWITCH_TEXTURE_PATH))
        exit(1);
}



void obj::Switch3::initData()
{
    this->mouseLeftKeyPressed = false;
    sf::Vector2u sliderTextureSize = this->sliderTexture.getSize();
    sf::Vector2u circleTextureSize = this->circleTexture.getSize();
    sf::Vector2u switchTextureSize = this->switchTexture.getSize();

    

    this->hitBox.setPosition(this->position);
    this->hitBox.setSize(sf::Vector2f(
        switchTextureSize.x, 
        switchTextureSize.y/3
    ));
    this->switchSprite.setTexture(this->switchTexture);
    this->switchSprite.setPosition(this->position);
    this->switchSprite.setTextureRect(sf::IntRect(
        0,
        (switchTextureSize.y/3) * this->currentState,
        switchTextureSize.x,
        switchTextureSize.y/3
    ));


    // this->hitBox.setPosition(this->position);
    // this->hitBox.setSize(sf::Vector2f(
    //     sliderTextureSize.x + circleTextureSize.x, // slider width and half of circle on the each side
    //     circleTextureSize.y
    // ));

    // this->hitBox.setFillColor(sf::Color(120, 30, 30, 10));


    // this->circle.setTexture(this->circleTexture);
    // this->circle.setOrigin(sf::Vector2f(circleTextureSize.x/2, circleTextureSize.y/2 + sliderTextureSize.y/2));
    // this->circle.setPosition(this->position);

    // this->slider.setTexture(this->sliderTexture);
    // this->slider.setPosition(this->position);
    // // this->slider.setTextureRect(sf::IntRect(0, sliderTextureSize.y/3 * this->currentState, sliderTextureSize.x, sliderTextureSize.y/3));
    
}




obj::Switch3::Switch3(sf::Vector2f position, obj::Switch3::SwitchState state)
{
    this->position = position;
    this->currentState = state;
    this->initTextures();
    this->initData();
}



obj::Switch3::~Switch3()
{

}






obj::Switch3::SwitchState obj::Switch3::determineHitBoxPart(float mousePos) const
{
    float x = this->hitBox.getPosition().x;
    float width = this->hitBox.getSize().x;

    float mouseXPosRelativeToSwitch = mousePos - x;
    sf::Vector2f middlePartArea(width/3, (width/3)*2); // (Left border, Right border)

    if(mouseXPosRelativeToSwitch < middlePartArea.x)
        return Switch3::SwitchState::On;
    else if(mouseXPosRelativeToSwitch > middlePartArea.y)
        return Switch3::SwitchState::Off;
    else
        return Switch3::SwitchState::None;
}


float obj::Switch3::determineMoveCircle(float mousePos) const
{
    float leftMaxMove = this->hitBox.getPosition().x; + this->circle.getGlobalBounds().width/2;
    float rightMaxMove = this->hitBox.getPosition().x + this->hitBox.getSize().x - this->circle.getGlobalBounds().width/2;
    if(mousePos < leftMaxMove)
        return leftMaxMove;
    else if(mousePos > rightMaxMove)
        return rightMaxMove;
    else 
        return (leftMaxMove + rightMaxMove) / 2;
}



void obj::Switch3::update(const sf::Event* event)
{
    
    if(event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left)
    {    
        if(this->hitBox.getGlobalBounds().contains(sf::Vector2f(event->mouseButton.x, event->mouseButton.y)))
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

    this->switchSprite.setTextureRect(sf::IntRect(
        0, 
        this->switchTexture.getSize().y/3 * this->currentState, 
        this->switchTexture.getSize().x, 
        this->switchTexture.getSize().y/3
    ));
    // if(this->currentState == Switch3::SwitchState::On)
    //     this->circle.setColor(sf::Color(0,255,0,100));
    // else if(this->currentState == Switch3::SwitchState::None)
    //     this->circle.setColor(sf::Color(0,0,0,100));
    // else if(this->currentState == Switch3::SwitchState::Off)
    //     this->circle.setColor(sf::Color(255,0,0,100));
}



void obj::Switch3::render(sf::RenderTarget* window) const
{
    // window->draw(this->slider);
    // // window->draw(this->hitBox.left);
    // // window->draw(this->hitBox.middle);
    // // window->draw(this->hitBox.right);
    // window->draw(this->circle);
    window->draw(this->switchSprite);
}





void obj::Switch3::setSwitch3State(obj::Switch3::SwitchState state)
{
    this->currentState = state;
}



obj::Switch3::SwitchState obj::Switch3::getSwitch3State() const
{
    return this->currentState;
}