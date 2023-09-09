#include "Button.hpp"

void sgui::Button::buildTextures()
{
    // COMPUTING
    this->position = sf::Vector2f(this->body.globalBounds.left, this->body.globalBounds.top);

    float x = this->body.globalBounds.left, y = this->body.globalBounds.top;
    float width = this->body.globalBounds.width, height = this->body.globalBounds.height;

    
    // SET SIZE AND POSITION
    this->body.left.setRadius(height/2);
    this->body.left.setPosition(this->position);

    this->body.middle.setSize(sf::Vector2f(width - height, height));
    this->body.middle.setPosition(sf::Vector2f(this->position.x + height/2, this->position.y));

    this->body.right.setRadius(height/2);
    this->body.right.setPosition(sf::Vector2f(this->position.x + width -height, this->position.y));

    this->body.left.setFillColor(this->body.color);
    this->body.middle.setFillColor(this->body.color);
    this->body.right.setFillColor(this->body.color);

    this->textSpaceGlobalBounds = sf::FloatRect(
        this->body.middle.getPosition().x,
        this->body.middle.getPosition().y,
        width - height,
        height
    );
    this->centerText();
}





sgui::Button::Button(sf::FloatRect floatRect, sf::Text text, sf::Color color, sf::Color colorHover, sf::Color colorPrress)
{
    this->text = text;
    this->click = false;
    this->clickControl = false;
    this->press = false;
    this->hover = false;
    this->body.color = color;
    this->body.colorPress = colorPrress;
    this->body.colorHover = colorHover;
    this->body.globalBounds = floatRect;
    this->buildTextures();

}


sgui::Button::~Button()
{

}





void sgui::Button::centerText(){
    this->text.setPosition(sf::Vector2f(
        this->textSpaceGlobalBounds.left + (this->textSpaceGlobalBounds.width - this->text.getGlobalBounds().width)/2,
        this->textSpaceGlobalBounds.top + (this->textSpaceGlobalBounds.height - this->text.getGlobalBounds().height)/2
    ));
}


bool sgui::Button::checkMouseHover(sf::Vector2f mousePos) const{
    // Middle
    if(this->body.middle.getGlobalBounds().contains(mousePos)) 
        return true;

    // Left
    sf::Vector2f leftCenter(
        this->body.left.getPosition().x + this->body.left.getRadius(),
        this->body.left.getPosition().y + this->body.left.getRadius()
    );
    sf::Vector2f leftVector(
        leftCenter.x - mousePos.x,
        leftCenter.y - mousePos.y
    );
    float leftDistance = sqrtf(powf(leftVector.x,2) + powf(leftVector.y,2));
    if(leftDistance <= this->body.left.getRadius()) 
        return true;
        
    
    // Right
    sf::Vector2f rightCenter(
        this->body.right.getPosition().x + this->body.right.getRadius(),
        this->body.right.getPosition().y + this->body.right.getRadius()
    );
    sf::Vector2f rightVector(
        rightCenter.x - mousePos.x,
        rightCenter.y - mousePos.y
    );
    float rightDistance = sqrtf(powf(rightVector.x,2) + powf(rightVector.y,2));
    if(rightDistance <= this->body.right.getRadius()) 
        return true;
        
    return false;
}





void sgui::Button::event(const sf::Event& event){
    if(event.type == sf::Event::MouseMoved){
        if(this->checkMouseHover(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
            this->hover = true;
        else
            this->hover = false;
    }


    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(this->checkMouseHover(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
            this->press = true;
        }
    }
    else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        this->press = false;
        this->click = false;
        this->clickControl = false;
    }

    
    if(this->press){
        this->body.left.setFillColor(this->body.colorPress);
        this->body.middle.setFillColor(this->body.colorPress);
        this->body.right.setFillColor(this->body.colorPress);
    }
    else if(this->hover){
        this->body.left.setFillColor(this->body.colorHover);
        this->body.middle.setFillColor(this->body.colorHover);
        this->body.right.setFillColor(this->body.colorHover);
    }
    else{
        this->body.left.setFillColor(this->body.color);
        this->body.middle.setFillColor(this->body.color);
        this->body.right.setFillColor(this->body.color);
    }
}


void sgui::Button::update()
{
    if(this->press && !this->clickControl){
        this->click = true;
        this->clickControl = true;
    }
    else
        this->click = false;
}


void sgui::Button::render(sf::RenderTarget* window) const
{
    window->draw(this->body.middle);
    window->draw(this->body.left);
    window->draw(this->body.right);
    window->draw(this->text);
}




const bool& sgui::Button::getButtonClick() const{
    return this->click;
}

const bool& sgui::Button::getButtonPress() const{
    return this->press;
}

const sf::Text& sgui::Button::getButtonText() const{
    return this->text;
}

void sgui::Button::setButtonText(const sf::Text& text){
    this->text = text;
    this->centerText();
}