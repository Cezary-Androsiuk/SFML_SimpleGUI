#include "CheckBox.hpp"


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

sgui::CheckBox::CheckBox() : CheckBox(__CBD_POSITION, __CBD_SIZE, __CBD_STATE){
}
sgui::CheckBox::CheckBox(sf::Vector2f position) : CheckBox(position, __CBD_SIZE, __CBD_STATE){
}
sgui::CheckBox::CheckBox(sf::Vector2f position, float size) : CheckBox(position, size, __CBD_STATE){
}
sgui::CheckBox::CheckBox(sf::Vector2f position, float size, bool state){
    this->bounds = sf::FloatRect(position, sf::Vector2f(size, size));
    this->state = state;
    this->initData();
    this->buildTextures();
}


sgui::CheckBox::~CheckBox(){
    
}




void sgui::CheckBox::updateTextureState(){
    if(this->border.getGlobalBounds() != this->bounds){
        float x = this->bounds.left, y = this->bounds.top;
        float width = this->bounds.width, height = this->bounds.height;
        float borderSize = ((width + height)/2 * __CBD_BORDER_RATIO)/2;
        float checkedWidth = width * __CBD_BORDER_CHECKED_RATIO, checkedHeight = height * __CBD_BORDER_CHECKED_RATIO;
        float checkedWidthOffset = width - checkedWidth, checkedHeightOffset = height - checkedHeight;

        this->background.setSize(sf::Vector2f(width, height));
        this->background.setPosition(x, y);

        this->border.setSize(sf::Vector2f(width - borderSize*2, height - borderSize*2));
        this->border.setPosition(x + borderSize, y + borderSize);
        this->border.setOutlineThickness(borderSize);

        this->shapeChecked.setSize(sf::Vector2f(checkedWidth, checkedHeight));
        this->shapeChecked.setPosition(x + checkedWidthOffset/2, y + checkedHeightOffset/2);
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

void sgui::CheckBox::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseMoved){
        if(this->bounds.contains(event.mouseMove.x, event.mouseMove.y))
            this->hover = true;
        else
            this->hover = false;
    }

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        if(this->bounds.contains(event.mouseButton.x, event.mouseButton.y)){
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