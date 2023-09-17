#include "../include/RadioButton.hpp"





/*      INITIALIZE      */
void sgui::RadioButton::initData(){
    this->state = false;
    this->check_on = false;
    this->checkControl = false;
    this->hover = false;
    this->enable = true;
    this->visible = true;

    this->colorBorder = __RBD_COLOR_BORDER;
    this->colorBackground = __RBD_COLOR_BACKGROUND;
    this->colorHover = __RBD_COLOR_HOVER;
    this->colorChecked = __RBD_COLOR_CHECKED;
}


void sgui::RadioButton::buildTextures(){
    this->border.setFillColor(sf::Color::Transparent);
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::RadioButton::RadioButton() : RadioButton(__RBD_POSITION, __RBD_RADIUS) {}
sgui::RadioButton::RadioButton(sf::Vector2f pos, float radius) {
    this->pos = pos;
    this->radius = radius;
    this->initData();
    this->buildTextures();
}
sgui::RadioButton::~RadioButton(){
    
}





/*      PRIVATE      */
void sgui::RadioButton::updateTextureState(){
    if(this->background.getPosition() != this->pos || this->background.getRadius() != this-> radius){
        float x = this->pos.x, y = this->pos.y;
        float radius = this->radius;
        this->background.setPosition(x, y);
        this->background.setRadius(radius);

        float borderSize = radius * __RBD_BORDER_RATIO;
        float borderCheckedSize = radius * __RBD_BORDER_CHECKED_RATIO;

        this->border.setRadius(radius - borderSize);
        this->border.setOutlineThickness(borderSize);
        this->border.setPosition(x + borderSize, y + borderSize);

        this->shapeChecked.setRadius(borderCheckedSize);
        this->shapeChecked.setPosition(x + radius/2, y + radius/2);
    }

    this->background.setFillColor(this->colorBackground);
    this->border.setOutlineColor(this->colorBorder);

    if(this->state)
        this->shapeChecked.setFillColor(this->colorChecked);
    else{
        if(this->hover)
            this->shapeChecked.setFillColor(this->colorHover);
        else 
            this->shapeChecked.setFillColor(sf::Color::Transparent);
    }
}


bool sgui::RadioButton::contains(float x, float y) const{
    return this->contains(sf::Vector2f(x,y));
}
bool sgui::RadioButton::contains(sf::Vector2f point) const{
    sf::Vector2f center(
        this->pos.x + this->radius,
        this->pos.y + this->radius
    );
    sf::Vector2f vector(
        center.x - point.x,
        center.y - point.y
    );
    float distance = sqrtf(powf(vector.x,2) + powf(vector.y,2));
    if(distance <= this->radius) 
        return true;
        
    return false;
}

void sgui::RadioButton::diselectGroup() const{
    for(auto& rb : this->group)
        rb->setState(false);
}





/*      PROTECTED      */
void sgui::RadioButton::setGroup(const std::vector<sgui::RadioButton *>& group){
    this->group = group;
}





/*      PUBLIC      */
void sgui::RadioButton::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        if(this->contains(event.mouseButton.x, event.mouseButton.y)){
            if(!this->state){
                this->state = true;
                this->checkControl = false;
                this->diselectGroup();
            }
        }
    }
    this->updateTextureState();
}


void sgui::RadioButton::update(){
    if(!this->enable) return;
    if(!this->visible) return;

    if(this->state && !this->checkControl){
        this->check_on = true;
        this->checkControl = true;
    }
    else
        this->check_on = false;
}


void sgui::RadioButton::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->background);
    window->draw(this->border);
    window->draw(this->shapeChecked);
}





/*      GETTERS      */
const bool& sgui::RadioButton::getChecked_on() const{
    return this->check_on;
}
const sf::Vector2f& sgui::RadioButton::getPosition() const{
    return this->pos;
}
const float& sgui::RadioButton::getRadius() const{
    return this->radius;
}
const bool& sgui::RadioButton::getState() const{
    return this->state;
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
void sgui::RadioButton::setPosition(const sf::Vector2f& pos){
    this->pos = pos;
}
void sgui::RadioButton::setRadius(const float& radius){
    this->radius = radius;
}
void sgui::RadioButton::setState(const bool& state){
    this->state = state;
    if(state == true)
        this->diselectGroup();
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





/*      STATIC      */
void sgui::RadioButton::createGroup(const std::vector<sgui::RadioButton *>& group){
    for(auto& gi : group){
        std::vector<sgui::RadioButton *> singleGroup;
        for(auto& gj : group){
            if(gi != gj)
                singleGroup.push_back(gj);
        }
        gi->setGroup(singleGroup);
    }
}