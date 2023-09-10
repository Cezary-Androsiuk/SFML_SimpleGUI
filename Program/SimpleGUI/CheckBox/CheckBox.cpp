#include "CheckBox.hpp"


void sgui::CheckBox::initData(){
    
}
void sgui::CheckBox::buildTextures(){
    
}

sgui::CheckBox::CheckBox() : CheckBox(sf::FloatRect(__CBD_POSITION, __CBD_SIZE), __CBD_STATE){
}
sgui::CheckBox::CheckBox(sf::FloatRect bounds) : CheckBox(bounds, __CBD_STATE){
}
sgui::CheckBox::CheckBox(sf::FloatRect bounds, bool state){
    this->bounds = bounds;
    this->state = state;
    this->initData();
    this->buildTextures();
}


sgui::CheckBox::~CheckBox(){
    
}




void sgui::CheckBox::updateTextureState(){
    
}

void sgui::CheckBox::event(const sf::Event& event){
    
}
void sgui::CheckBox::update(){
    
}
void sgui::CheckBox::render(sf::RenderTarget* window) const{
    
}




/*      GETTERS / SETTERS      */
const bool& sgui::CheckBox::getChecked_on() const{
    return this->check_on;
}
const bool& sgui::CheckBox::getChecked_off() const{
    return this->check_off;
}




/*          CONTROLS          */
/*      GETTERS      */
const bool& sgui::CheckBox::getCheckState() const{
    return this->state;
}
const sf::FloatRect& sgui::CheckBox::getBounds() const{
    return this->bounds;
}
const sf::Color& sgui::CheckBox::getColorBackground() const{
    return this->colorBackground;
}
const sf::Color& sgui::CheckBox::getColorHover() const{
    return this->colorHover;
}
const sf::Color& sgui::CheckBox::getColorHoverChecked() const{
    return this->colorHoverChecked;
}
const sf::Color& sgui::CheckBox::getColorChecked() const{
    return this->colorChecked;
}
const bool& sgui::CheckBox::getEnable() const{
    return this->enable;
}
const bool& sgui::CheckBox::getVisible() const{
    return this->visible;
}


/*      SETTERS      */
void sgui::CheckBox::setCheckState(const bool& state){
    this->state = state;
}
void sgui::CheckBox::setBounds(const sf::FloatRect& size){
    this->bounds = size;
}
void sgui::CheckBox::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
}
void sgui::CheckBox::setColorHover(const sf::Color& color){
    this->colorHover = color;
}
void sgui::CheckBox::setColorHoverChecked(const sf::Color& color){
    this->colorHoverChecked = color;
}
void sgui::CheckBox::setColorChecked(const sf::Color& color){
    this->colorChecked = color;
}
void sgui::CheckBox::setEnable(const bool& enable){
    this->enable = enable;
}
void sgui::CheckBox::setVisible(const bool& visible){
    this->visible = visible;
}