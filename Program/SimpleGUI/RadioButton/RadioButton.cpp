#include "RadioButton.hpp"





/*      INITIALIZE      */
void sgui::RadioButton::initData(){
    this->check_on = false;
    this->checkControl = false;
    this->hover = false;
    this->enable = true;
    this->visible = true;

    colorBorder = __RBD_COLOR_BORDER;
    colorBackground = __RBD_COLOR_BACKGROUND;
    colorHover = __RBD_COLOR_HOVER;
    colorChecked = __RBD_COLOR_CHECKED;
}


void sgui::RadioButton::buildTextures(){
    this->border.setFillColor(sf::Color::Transparent);
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::RadioButton::RadioButton() : RadioButton(__RBD_POSITION, __RBD_RADIUS) {}
sgui::RadioButton::RadioButton(sf::Vector2f pos) : RadioButton(pos, __RBD_RADIUS) {}
sgui::RadioButton::RadioButton(sf::Vector2f pos, float radius) {
    this->bounds.pos = pos;
    this->bounds.radius = radius;
    this->state = state;
    this->initData();
    this->buildTextures();
}
sgui::RadioButton::~RadioButton(){
    
}





/*      PRIVATE      */
void sgui::RadioButton::updateTextureState(){
    if(this->background.getPosition() != this->bounds.pos || this->background.getRadius() != this->bounds.radius){
        
    }
}
void sgui::RadioButton::setGroup(const std::vector<sgui::RadioButton *const> group){
    this->group = group;
}





/*      PUBLIC      */
void sgui::RadioButton::event(const sf::Event& event){
    
}


void sgui::RadioButton::update(){
    // if RadioButton was pressed (or changed by method) then set all RadioButtons from group to state=false;
}


void sgui::RadioButton::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->background);
    window->draw(this->border);
    window->draw(this->shapeChecked);
}





/*      GETTERS / SETTERS      */
const bool& sgui::RadioButton::getChecked_on() const{
    return this->check_on;
}
void sgui::RadioButton::createGroup(std::vector<sgui::RadioButton *const> group){
    for(auto& gi : group){
        std::vector<sgui::RadioButton *const> singleGroup;
        for(auto& gj : group){
            if(gi != gj)
                singleGroup.push_back(gj);
        }
        gi->setGroup(singleGroup);
    }
}





/*          CONTROLS          */
/*      GETTERS      */
const bool& sgui::RadioButton::getCheckState() const{
    return this->state;
}
const sf::Vector2f& sgui::RadioButton::getPosition() const{
    return this->bounds.pos;
}
const float& sgui::RadioButton::getRadius() const{
    return this->bounds.radius;
}
const sf::Color& sgui::RadioButton::getColorBorder() const{
    return this->colorBorder;
}
const sf::Color& sgui::RadioButton::getColorBackground() const{
    return this->colorBackground;
}
const sf::Color& sgui::RadioButton::getColorHover() const{
    return this->colorHover;
}
const sf::Color& sgui::RadioButton::getColorChecked() const{
    return this->colorChecked;
}
const bool& sgui::RadioButton::getEnable() const{
    return this->enable;
}
const bool& sgui::RadioButton::getVisible() const{
    return this->visible;
}





/*      SETTERS      */
void sgui::RadioButton::setCheckState(const bool& state){
    this->state = state;
    this->updateTextureState();
}
void sgui::RadioButton::setPosition(const sf::Vector2f& pos){
    this->bounds.pos = pos;
    this->updateTextureState();
}
void sgui::RadioButton::setRadius(const float& radius){
    this->bounds.radius = radius;
    this->updateTextureState();
}
void sgui::RadioButton::setColorBorder(const sf::Color& color){
    this->colorBorder = color;
    this->updateTextureState();
}
void sgui::RadioButton::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
    this->updateTextureState();
}
void sgui::RadioButton::setColorHover(const sf::Color& color){
    this->colorHover = color;
    this->updateTextureState();
}
void sgui::RadioButton::setColorChecked(const sf::Color& color){
    this->colorChecked = color;
    this->updateTextureState();
}
void sgui::RadioButton::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}
void sgui::RadioButton::setVisible(const bool& visible){
    this->visible = visible;
    this->updateTextureState();
}