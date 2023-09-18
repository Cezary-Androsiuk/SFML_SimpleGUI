#include "../include/Button.hpp"





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
    this->colorText = __BD_TEXT_COLOR;
}


void sgui::Button::buildTextures(){
    this->updateShape();
    this->updateColor();
}





/*      CONSTRUCTORS      */
sgui::Button::Button() : Button(sf::FloatRect(__BD_POSITION, __BD_SIZE)) {}
sgui::Button::Button(sf::FloatRect bounds){
    this->pos = sf::Vector2f(bounds.left, bounds.top);
    this->size = sf::Vector2f(bounds.width, bounds.height);
    this->initData();
    this->buildTextures();
}
sgui::Button::~Button(){

}





/*      PRIVATE      */
void sgui::Button::centerText(){
    sf::FloatRect sfr = this->shape.getGlobalBounds();
    sf::FloatRect tfr = this->text.getGlobalBounds();
    this->text.setPosition(sf::Vector2f(
        sfr.left + (sfr.width - tfr.width)/2,
        sfr.top + (sfr.height - this->text.getCharacterSize())/2
    ));
    tfr = this->text.getGlobalBounds();
    sf::Vector2f error(tfr.left - this->text.getPosition().x, tfr.top - this->text.getPosition().y);
    this->text.setPosition(this->text.getPosition() - error);
}


void sgui::Button::updateShape(){
    // SET SIZE AND POSITION
    this->shape.setSize(size);
    this->shape.setPosition(pos);
    this->centerText();
}


void sgui::Button::updateColor(){
    if(this->enable){
        this->text.setFillColor(this->colorText);

        if(this->press)
            this->shape.setFillColor(this->colorPress);
        else if(this->hover)
            this->shape.setFillColor(this->colorHover);
        else
            this->shape.setFillColor(this->color);
    }
    else{
        // set standard color to avoid keeping disable while button is pressed
        this->shape.setFillColor(sf::Color(
            this->color.r,
            this->color.g,
            this->color.b,
            __BD_DISABLE_ALPHA_VALUE
        ));
        
        this->text.setFillColor(sf::Color(
            this->colorText.r,
            this->colorText.g,
            this->colorText.b,
            __BD_DISABLE_ALPHA_VALUE
        ));
    }
}





/*      PUBLIC      */
void sgui::Button::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseMoved){
        if(sf::FloatRect(this->pos, this->size).contains(event.mouseMove.x, event.mouseMove.y))
            this->hover = true;
        else
            this->hover = false;
    }


    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(sf::FloatRect(this->pos, this->size).contains(event.mouseButton.x, event.mouseButton.y)){
            this->press = true;
        }
    }
    else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        this->press = false;
        this->click = false;
        this->clickControl = false;
    }
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
    this->updateShape();
    this->updateColor();
}


void sgui::Button::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->shape);
    window->draw(this->text);
}





/*      GETTERS      */
const bool& sgui::Button::getClick() const{
    return this->click;
}
const bool& sgui::Button::getPress() const{
    return this->press;
}
const sf::Vector2f& sgui::Button::getPosition() const{
    return this->pos;
}
const sf::Vector2f& sgui::Button::getSize() const{
    return this->size;
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
const sf::Color& sgui::Button::getColorText() const{
    return this->colorText;
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
void sgui::Button::setPosition(const sf::Vector2f& pos){
    this->pos = pos;
    this->updateShape();
}
void sgui::Button::setSize(const sf::Vector2f& size){
    this->size = size;
    this->updateShape();
}
void sgui::Button::setColor(const sf::Color& color){
    this->color = color;
    this->updateColor();
}
void sgui::Button::setColorHover(const sf::Color& color){
    this->colorHover = color;
    this->updateColor();
}
void sgui::Button::setColorPress(const sf::Color& color){
    this->colorPress = color;
    this->updateColor();
}
void sgui::Button::setColorText(const sf::Color& color){
    this->colorText = color;
    this->updateColor();
}
void sgui::Button::setText(const sf::Text& text){
    this->text = text;
    this->centerText();
}
void sgui::Button::setEnable(const bool& enable){
    this->enable = enable;
    this->updateColor();
}
void sgui::Button::setVisible(const bool& visible){
    this->visible = visible;
}