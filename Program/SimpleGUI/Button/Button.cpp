#include "Button.hpp"





/*      INITIALIZE      */
void sgui::Button::initData(){
    this->enable = true;
    this->visible = true;
    this->hover = false;
    this->press = false;
    this->click = false;
    this->clickControl = false;

    this->color = __BD_COLOR;
    this->colorHover = __BD_COLOR_HOVER;
    this->colorPress = __BD_COLOR_PRESS;
    this->text = __BD_TEXT;
    this->textColor = __BD_TEXT_COLOR;
}


void sgui::Button::buildTextures(){
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::Button::Button() : Button(sf::FloatRect(__BD_POSITION, __BD_SIZE)) {}
sgui::Button::Button(sf::FloatRect bounds){
    this->bounds = bounds;
    this->initData();
    this->buildTextures();
}
sgui::Button::~Button(){

}





/*      PRIVATE      */
void sgui::Button::centerText(){
    this->text.setPosition(sf::Vector2f(
        this->shape.getGlobalBounds().left + (this->shape.getGlobalBounds().width - this->text.getGlobalBounds().width)/2,
        this->shape.getGlobalBounds().top + (this->shape.getGlobalBounds().height - this->text.getGlobalBounds().height)/2
    ));
}


void sgui::Button::updateTextureState(){
    if(this->shape.getGlobalBounds() != this->bounds){
        // COMPUTING
        float x = this->bounds.left, y = this->bounds.top;
        float width = this->bounds.width, height = this->bounds.height;
        
        // SET SIZE AND POSITION
        this->shape.setSize(sf::Vector2f(width, height));
        this->shape.setPosition(sf::Vector2f(x, y));

        this->shape.setFillColor(this->color);
        this->text.setFillColor(this->textColor);

        this->centerText();
    }

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
        tmpColor.a = __BD_DISABLE_ALPHA_VALUE;
        this->shape.setFillColor(tmpColor);
        tmpColor = this->text.getFillColor();
        tmpColor.a = __BD_DISABLE_ALPHA_VALUE;
        this->text.setFillColor(tmpColor);
    }
}





/*      PUBLIC      */
void sgui::Button::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseMoved){
        if(this->bounds.contains(event.mouseMove.x, event.mouseMove.y))
            this->hover = true;
        else
            this->hover = false;
    }


    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(this->bounds.contains(event.mouseButton.x, event.mouseButton.y)){
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





/*      GETTERS / SETTERS      */
const bool& sgui::Button::getClick() const{
    return this->click;
}
const bool& sgui::Button::getPress() const{
    return this->press;
}





/*          CONTROLS          */
/*      GETTERS      */
const sf::FloatRect& sgui::Button::getBounds() const{
    return this->bounds;
}
const sf::Color& sgui::Button::getColor() const{
    return this->color;
}
const sf::Color& sgui::Button::getColorHover() const{
    return this->colorHover;
}
const sf::Color& sgui::Button::getColorPress() const{
    return this->colorPress;
}
const sf::Color& sgui::Button::getTextColor() const{
    return this->textColor;
}
const sf::Text& sgui::Button::getText() const{
    return this->text;
}
const bool& sgui::Button::getEnable() const{
    return this->enable;
}
const bool& sgui::Button::getVisible() const{
    return this->visible;
}





/*      SETTERS      */
void sgui::Button::setBounds(const sf::FloatRect& size){
    this->bounds = size;
    this->updateTextureState();
}
void sgui::Button::setColor(const sf::Color& color){
    this->color = color;
    this->updateTextureState();
}
void sgui::Button::setColorHover(const sf::Color& color){
    this->colorHover = color;
    this->updateTextureState();
}
void sgui::Button::setColorPress(const sf::Color& color){
    this->colorPress = color;
    this->updateTextureState();
}
void sgui::Button::setTextColor(const sf::Color& color){
    this->textColor = color;
    this->updateTextureState();
}
void sgui::Button::setText(const sf::Text& text){
    this->text = text;
    this->centerText();
}
void sgui::Button::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}
void sgui::Button::setVisible(const bool& visible){
    this->visible = visible;
    this->updateTextureState();
}