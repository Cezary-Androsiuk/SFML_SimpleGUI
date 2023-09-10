#include "Switch.hpp"

void sgui::Switch::buildTextures()
{
    // COMPUTING
    this->position = sf::Vector2f(this->background.globalBounds.left, this->background.globalBounds.top);

    float x = this->background.globalBounds.left, y = this->background.globalBounds.top;
    float width = this->background.globalBounds.width, height = this->background.globalBounds.height;
    float switchHeight = height * SWITCH_HANDLE_SIZE_RATIO;
    float switchShadowHeight = height * SWITCH_SHADOW_SIZE_RATIO;
    float diffHeight = (switchShadowHeight - switchHeight)/2;
    float borderSize = (height - switchHeight)/2;

    this->_switch.moveRange.left = sf::Vector2f(
        this->position.x + borderSize,
        this->position.y + borderSize
    );
    this->_switch.moveRange.right = sf::Vector2f(
        (this->position.x + this->background.globalBounds.width - switchHeight - borderSize),
        this->position.y + borderSize 
    );

    this->_switch.moveRange.shadowLeft = sf::Vector2f(
        this->position.x + borderSize - diffHeight,
        this->position.y + borderSize - diffHeight
    );
    this->_switch.moveRange.shadowRight = sf::Vector2f(
        (this->position.x + this->background.globalBounds.width - switchHeight - borderSize) - diffHeight,
        this->position.y + borderSize - diffHeight
    );

    
    // SET SIZE AND POSITION
    this->background.left.setRadius(height/2);
    this->background.left.setPosition(this->position);

    this->background.middle.setSize(sf::Vector2f(width - height, height));
    this->background.middle.setPosition(sf::Vector2f(this->position.x + height/2, this->position.y));

    this->background.right.setRadius(height/2);
    this->background.right.setPosition(sf::Vector2f(this->position.x + width -height, this->position.y));

    this->_switch.handle.setRadius(switchHeight/2);
    this->_switch.handle.setFillColor(this->_switch.color);

    this->_switch.shadow.setRadius(switchShadowHeight/2);
    this->_switch.shadow.setFillColor(sf::Color(100, 100, 100, 40));

    this->updateTextureState();

}





sgui::Switch::Switch(sf::FloatRect floatRect, bool state, sf::Color backgroundColor_on, sf::Color backgroundColor_off, sf::Color switchColor)
{
    this->enable = true;
    this->visible = true;
    this->switchedControl = true;
    this->background.color_on = backgroundColor_on;
    this->background.color_off = backgroundColor_off;
    this->_switch.color = switchColor;
    this->background.globalBounds = floatRect;
    this->currentState = state;
    this->buildTextures();

}


sgui::Switch::~Switch()
{

}





bool sgui::Switch::checkMouseHover(sf::Vector2f mousePos) const{
    // Middle
    if(this->background.middle.getGlobalBounds().contains(mousePos)) 
        return true;

    // Left
    sf::Vector2f leftCenter(
        this->background.left.getPosition().x + this->background.left.getRadius(),
        this->background.left.getPosition().y + this->background.left.getRadius()
    );
    sf::Vector2f leftVector(
        leftCenter.x - mousePos.x,
        leftCenter.y - mousePos.y
    );
    float leftDistance = sqrtf(powf(leftVector.x,2) + powf(leftVector.y,2));
    if(leftDistance <= this->background.left.getRadius()) 
        return true;
        
    
    // Right
    sf::Vector2f rightCenter(
        this->background.right.getPosition().x + this->background.right.getRadius(),
        this->background.right.getPosition().y + this->background.right.getRadius()
    );
    sf::Vector2f rightVector(
        rightCenter.x - mousePos.x,
        rightCenter.y - mousePos.y
    );
    float rightDistance = sqrtf(powf(rightVector.x,2) + powf(rightVector.y,2));
    if(rightDistance <= this->background.right.getRadius()) 
        return true;
        
    return false;
}


void sgui::Switch::updateTextureState(){
    sf::Color tmpColor(this->currentState ? this->background.color_on : this->background.color_off);
    if(!this->enable){
        tmpColor = (this->currentState ? SWITCH_BACKGROUND_DISABLE_COLOR_ON : SWITCH_BACKGROUND_DISABLE_COLOR_OFF);
        this->_switch.handle.setFillColor(SWITCH_HANDLE_DISABLE_COLOR);
    }
    else{
        this->_switch.handle.setFillColor(this->_switch.color);
    }

    this->background.left.setFillColor(tmpColor);
    this->background.middle.setFillColor(tmpColor);
    this->background.right.setFillColor(tmpColor);

    if(this->currentState){
        this->_switch.handle.setPosition(this->_switch.moveRange.right);
        this->_switch.shadow.setPosition(this->_switch.moveRange.shadowRight);
    }
    else{
        this->_switch.handle.setPosition(this->_switch.moveRange.left);
        this->_switch.shadow.setPosition(this->_switch.moveRange.shadowLeft);
    }
}





void sgui::Switch::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        if(this->checkMouseHover(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
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
    
    window->draw(this->background.middle);
    window->draw(this->background.left);
    window->draw(this->background.right);
    window->draw(this->_switch.shadow);
    window->draw(this->_switch.handle);
}




void sgui::Switch::setSwitchState(bool state){
    this->currentState = state;
    this->updateTextureState();
}
const bool& sgui::Switch::getSwitchState() const{
    return this->currentState;
}


const bool& sgui::Switch::getSwitched_on() const{
    return this->switched_on;
}
const bool& sgui::Switch::getSwitched_off() const{
    return this->switched_off;
}


const bool& sgui::Switch::getEnable() const{
    return this->enable;
}
void sgui::Switch::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}


const bool& sgui::Switch::getVisible() const{
    return this->visible;
}
void sgui::Switch::setVisible(const bool& visible){
    this->visible = visible;
}
