#include "Button.hpp"

void sgui::Button::buildTextures()
{
    // COMPUTING
    float x = this->globalBounds.left, y = this->globalBounds.top;
    float width = this->globalBounds.width, height = this->globalBounds.height;
    
    // SET SIZE AND POSITION
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(sf::Vector2f(x, y));

    this->shape.setFillColor(this->color);
    this->text.setFillColor(this->textColor);

    this->centerText();
}





sgui::Button::Button(sf::FloatRect floatRect, sf::Text text, sf::Color textColor, sf::Color color, sf::Color colorHover, sf::Color colorPrress)
{
    this->enable = true;
    this->visible = true;
    this->text = text;
    this->textColor = textColor;
    this->click = false;
    this->clickControl = false;
    this->press = false;
    this->hover = false;
    this->color = color;
    this->colorPress = colorPrress;
    this->colorHover = colorHover;
    this->globalBounds = floatRect;
    this->buildTextures();

}


sgui::Button::~Button()
{

}





void sgui::Button::centerText(){
    this->text.setPosition(sf::Vector2f(
        this->shape.getGlobalBounds().left + (this->shape.getGlobalBounds().width - this->text.getGlobalBounds().width)/2,
        this->shape.getGlobalBounds().top + (this->shape.getGlobalBounds().height - this->text.getGlobalBounds().height)/2
    ));
}


void sgui::Button::updateTextureState(){
    if(this->press){
        this->shape.setFillColor(this->colorPress);
    }
    else if(this->hover){
        this->shape.setFillColor(this->colorHover);
    }
    else{
        this->shape.setFillColor(this->color);
    }
    this->text.setFillColor(this->textColor);
    
    if(!this->enable){
        sf::Color tmpColor = this->shape.getFillColor();
        tmpColor.a = BUTTON_DISABLE_TRANSPARENT_VALUE;
        this->shape.setFillColor(tmpColor);
        tmpColor = this->text.getFillColor();
        tmpColor.a = BUTTON_DISABLE_TRANSPARENT_VALUE;
        this->text.setFillColor(tmpColor);
    }
}





void sgui::Button::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseMoved){
        if(this->shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
            this->hover = true;
        else
            this->hover = false;
    }


    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(this->shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
            this->press = true;
        }
    }
    else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        this->press = false;
        this->click = false;
        this->clickControl = false;
    }

    this->updateTextureState();
}


void sgui::Button::update(){
    if(!this->enable) return;
    if(!this->visible) return;

    if(this->press && !this->clickControl){
        this->click = true;
        this->clickControl = true;
    }
    else
        this->click = false;
}


void sgui::Button::render(sf::RenderTarget* window) const
{
    if(!this->visible) return;

    window->draw(this->shape);
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

const bool& sgui::Button::getEnable() const{
    return this->enable;
}
void sgui::Button::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}


const bool& sgui::Button::getVisible() const{
    return this->visible;
}
void sgui::Button::setVisible(const bool& visible){
    this->visible = visible;
}