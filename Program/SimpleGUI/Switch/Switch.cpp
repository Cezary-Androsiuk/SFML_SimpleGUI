#include "Switch.hpp"

void sgui::Switch::initData(){
    this->enable = true;
    this->visible = true;
    this->switchedControl = true;

    this->background.color_on = __SD_BACKGROUND_COLOR_ON;
    this->background.color_off = __SD_BACKGROUND_COLOR_OFF;
    this->_switch.color = __SD_SWITCH_COLOR;
    this->_switch.shadowColor = __SD_SHADOW_COLOR;
}


void sgui::Switch::buildTextures(){
    this->updateTextureState();
}





sgui::Switch::Switch() : Switch(sf::FloatRect(__SD_POSITION, __SD_SIZE), __SD_STATE){
}
sgui::Switch::Switch(sf::FloatRect bounds) : Switch(bounds, __SD_STATE){
}
sgui::Switch::Switch(sf::FloatRect bounds, bool state){
    this->bounds = bounds;
    this->currentState = state;

    this->initData();
    this->buildTextures();
}


sgui::Switch::~Switch()
{

}





void sgui::Switch::updateTextureState(){
    if(this->background.shape.getGlobalBounds() != this->bounds){
        // COMPUTING
        float x = this->bounds.left, y = this->bounds.top;
        float width = this->bounds.width, height = this->bounds.height;
        float switchHeight = height * __SD_HANDLE_SIZE_RATIO;
        float switchShadowHeight = height * __SD_SHADOW_SIZE_RATIO;
        float diffHeight = (switchShadowHeight - switchHeight)/2;
        float borderSize = (height - switchHeight)/2;

        this->_switch.moveRange.left = sf::Vector2f(
            x + borderSize,
            y + borderSize
        );
        this->_switch.moveRange.right = sf::Vector2f(
            (x + width - switchHeight - borderSize),
            y + borderSize 
        );

        this->_switch.moveRange.shadowLeft = sf::Vector2f(
            x + borderSize - diffHeight,
            y + borderSize - diffHeight
        );
        this->_switch.moveRange.shadowRight = sf::Vector2f(
            (x + width - switchHeight - borderSize) - diffHeight,
            y + borderSize - diffHeight
        );

        // SET SIZE AND POSITION
        this->background.shape.setSize(sf::Vector2f(width, height));
        this->background.shape.setPosition(sf::Vector2f(x, y));

        this->_switch.shape.setSize(sf::Vector2f(switchHeight, switchHeight));
        this->_switch.shape.setFillColor(this->_switch.color);

        this->_switch.shadow.setSize(sf::Vector2f(switchShadowHeight, switchShadowHeight));
        this->_switch.shadow.setFillColor(this->_switch.shadowColor);
    }

    sf::Color tmpBackgroundColor(this->currentState ? this->background.color_on : this->background.color_off);
    sf::Color tmpSwitchColor(this->_switch.color);
    sf::Color tmpShadowColor(this->_switch.shadowColor);

    if(!this->enable){
        tmpBackgroundColor.a = __SD_DISABLE_ALPHA_VALUE;
        tmpSwitchColor.a = __SD_DISABLE_ALPHA_VALUE;
        tmpShadowColor.a = __SD_DISABLE_ALPHA_VALUE;
    }

    this->background.shape.setFillColor(tmpBackgroundColor);
    this->_switch.shape.setFillColor(tmpSwitchColor);
    this->_switch.shadow.setFillColor(tmpShadowColor);

    if(this->currentState){
        this->_switch.shape.setPosition(this->_switch.moveRange.right);
        this->_switch.shadow.setPosition(this->_switch.moveRange.shadowRight);
    }
    else{
        this->_switch.shape.setPosition(this->_switch.moveRange.left);
        this->_switch.shadow.setPosition(this->_switch.moveRange.shadowLeft);
    }
}





void sgui::Switch::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        if(this->background.shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
            if(this->currentState){
                this->currentState = false;
                this->switchedControl = false;
            }
            else{
                this->currentState = true;
                this->switchedControl = false;
            }
            this->updateTextureState();
        }
    }
}


void sgui::Switch::update(){
    if(!this->enable) return;
    if(!this->visible) return;

    if(this->currentState && !this->switchedControl){
        this->switched_on = true;
        this->switchedControl = true;
    }
    else
        this->switched_on = false;

    if(!this->currentState && !this->switchedControl){
        this->switched_off = true;
        this->switchedControl = true;
    }
    else
        this->switched_off = false;
}


void sgui::Switch::render(sf::RenderTarget* window) const
{
    if(!this->visible) return;
    
    window->draw(this->background.shape);
    window->draw(this->_switch.shadow);
    window->draw(this->_switch.shape);
}




/*      GETTERS / SETTERS      */
const bool& sgui::Switch::getSwitched_on() const{
    return this->switched_on;
}
const bool& sgui::Switch::getSwitched_off() const{
    return this->switched_off;
}




/*          CONTROLS          */
/*      GETTERS      */
const bool& sgui::Switch::getSwitchState() const{
    return this->currentState;
}
const sf::FloatRect& sgui::Switch::getBounds() const{
    return this->bounds;
}
const sf::Color& sgui::Switch::getBackgroundColor_on() const{
    return this->background.color_on;
}
const sf::Color& sgui::Switch::getBackgroundColor_off() const{
    return this->background.color_off;
}
const sf::Color& sgui::Switch::getSwitchColor() const{
    return this->_switch.color;
}
const sf::Color& sgui::Switch::getShadowColor() const{
    return this->_switch.shadowColor;
}
const bool& sgui::Switch::getEnable() const{
    return this->enable;
}
const bool& sgui::Switch::getVisible() const{
    return this->visible;
}


/*      SETTERS      */
void sgui::Switch::setSwitchState(bool state){
    this->currentState = state;
    this->updateTextureState();
}
void sgui::Switch::setBounds(const sf::FloatRect& size){
    this->bounds = size;
    this->updateTextureState();
}
void sgui::Switch::setBackgroundColor_on(const sf::Color& color){
    this->background.color_on = color;
    this->updateTextureState();
}
void sgui::Switch::setBackgroundColor_off(const sf::Color& color){
    this->background.color_off = color;
    this->updateTextureState();
}
void sgui::Switch::setSwitchColor(const sf::Color& color){
    this->_switch.color = color;
    this->updateTextureState();
}
void sgui::Switch::setShadowColor(const sf::Color& color){
    this->_switch.shadowColor = color;
    this->updateTextureState();
}
void sgui::Switch::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}
void sgui::Switch::setVisible(const bool& visible){
    this->visible = visible;
    this->updateTextureState();
}












