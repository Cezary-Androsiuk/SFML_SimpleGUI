#include "../include/CheckBox.hpp"




/*      INITIALIZE      */
void sgui::CheckBox::initData(){
    this->enable = true;
    this->visible = true;
    this->hover = false;
    this->check_on = false;
    this->check_off = false;
    this->checkControl = true; // if false spams "checked_off"

    this->colorBorder = __CBD_COLOR_BORDER;
    this->colorBackground = __CBD_COLOR_BACKGROUND;
    this->colorHover = __CBD_COLOR_HOVER;
    this->colorHoverChecked = __CBD_COLOR_HOVER_CHECKED;
    this->colorChecked = __CBD_COLOR_CHECKED;
}


void sgui::CheckBox::buildTextures(){
    this->border.setFillColor(sf::Color::Transparent);
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::CheckBox::CheckBox() : CheckBox(__CBD_POSITION, __CBD_SIZE, __CBD_STATE){}
sgui::CheckBox::CheckBox(sf::Vector2f pos, float size) : CheckBox(pos, size, __CBD_STATE){}
sgui::CheckBox::CheckBox(sf::Vector2f pos, float size, bool state){
    this->pos = pos;
    this->size = size;
    this->state = state;
    this->initData();
    this->buildTextures();
}
sgui::CheckBox::~CheckBox(){
    
}





/*      PRIVATE      */
void sgui::CheckBox::updateTextureState(){
    if(this->background.getPosition() != this->pos || this->background.getSize().x != this->size){
        float x = this->pos.x, y = this->pos.y;
        float borderSize = this->size * __CBD_BORDER_RATIO;
        float checkedSize = this->size * __CBD_BORDER_CHECKED_RATIO;
        float checkedSizeOffset = this->size - checkedSize;

        this->background.setSize(sf::Vector2f(this->size, this->size));
        this->background.setPosition(x, y);

        this->border.setSize(sf::Vector2f(this->size - borderSize, this->size - borderSize));
        this->border.setPosition(x + borderSize/2, y + borderSize/2);
        this->border.setOutlineThickness(borderSize/2);

        this->shapeChecked.setSize(sf::Vector2f(checkedSize, checkedSize));
        this->shapeChecked.setPosition(x + checkedSizeOffset/2, y + checkedSizeOffset/2);
    }

    sf::Color tmpColorBorder = this->colorBorder;
    sf::Color tmpColorBackground = this->colorBackground;
    sf::Color tmpColorCheck;

    if(this->hover){
        if(this->state)
            tmpColorCheck = this->colorHoverChecked;
        else
            tmpColorCheck = this->colorHover;
    }
    else{
        if(this->state)
            tmpColorCheck = this->colorChecked;
        else
            tmpColorCheck = sf::Color::Transparent;
    }

    if(!this->enable){
        tmpColorBorder.a = tmpColorBorder.a * __CBD_DISABLE_ALPHA_PCT;
        tmpColorBackground.a = tmpColorBackground.a * __CBD_DISABLE_ALPHA_PCT;
        tmpColorCheck.a = tmpColorCheck.a * __CBD_DISABLE_ALPHA_PCT;
    }

    this->border.setOutlineColor(tmpColorBorder);
    this->background.setFillColor(tmpColorBackground);
    this->shapeChecked.setFillColor(tmpColorCheck);
}





/*      PUBLIC      */
void sgui::CheckBox::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseMoved){
        if(sf::FloatRect(this->pos, sf::Vector2f(this->size, this->size)).contains(event.mouseMove.x, event.mouseMove.y))
            this->hover = true;
        else
            this->hover = false;
    }

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        if(sf::FloatRect(this->pos, sf::Vector2f(this->size, this->size)).contains(event.mouseButton.x, event.mouseButton.y)){
            if(this->state){
                this->state = false;
                this->checkControl = false;
            }
            else{
                this->state = true;
                this->checkControl = false;
            }
        }
    }

    this->updateTextureState();
}


void sgui::CheckBox::update(){
    if(!this->enable) return;
    if(!this->visible) return;

    if(this->state && !this->checkControl){
        this->check_on = true;
        this->checkControl = true;
    }
    else
        this->check_on = false;

    if(!this->state && !this->checkControl){
        this->check_off = true;
        this->checkControl = true;
    }
    else
        this->check_off = false;
}


void sgui::CheckBox::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->background);
    window->draw(this->border);
    window->draw(this->shapeChecked);
}





/*      GETTERS      */
const bool& sgui::CheckBox::getChecked_on() const{
    return this->check_on;
}
const bool& sgui::CheckBox::getChecked_off() const{
    return this->check_off;
}
const sf::Vector2f& sgui::CheckBox::getPosition() const{
    return this->pos;
}
const float& sgui::CheckBox::getSize() const{
    return this->size;
}
const bool& sgui::CheckBox::getState() const{
    return this->state;
}
const sf::Color& sgui::CheckBox::getColorBorder() const{
    return this->colorBorder;
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
void sgui::CheckBox::setPosition(const sf::Vector2f& pos){
    this->pos = pos;
}
void sgui::CheckBox::setSize(const float& size){
    this->size = size;
}
void sgui::CheckBox::setState(const bool& state){
    this->state = state;
    this->updateTextureState();
}
void sgui::CheckBox::setColorBorder(const sf::Color& color){
    this->colorBorder = color;
    this->updateTextureState();
}
void sgui::CheckBox::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
    this->updateTextureState();
}
void sgui::CheckBox::setColorHover(const sf::Color& color){
    this->colorHover = color;
    this->updateTextureState();
}
void sgui::CheckBox::setColorHoverChecked(const sf::Color& color){
    this->colorHoverChecked = color;
    this->updateTextureState();
}
void sgui::CheckBox::setColorChecked(const sf::Color& color){
    this->colorChecked = color;
    this->updateTextureState();
}
void sgui::CheckBox::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}
void sgui::CheckBox::setVisible(const bool& visible){
    this->visible = visible;
    this->updateTextureState();
}