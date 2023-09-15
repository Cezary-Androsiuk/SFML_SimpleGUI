#include "GroupBox.hpp"




/*      INITIALIZE      */
void sgui::GroupBox::initData(){
    this->enable = true;
    this->visible = true;

    // this->colorBackground = __GBD_COLOR_BACKGROUND;
}


void sgui::GroupBox::buildTextures(){
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::GroupBox::GroupBox() : GroupBox(sf::FloatRect(__GBD_POSITION, __GBD_POSITION)){}
sgui::GroupBox::GroupBox(sf::FloatRect bounds){
    this->bounds = bounds;
    this->initData();
    this->buildTextures();
}
sgui::GroupBox::~GroupBox(){
    for(const auto& o : this->objects)
        delete o;
}





/*      PRIVATE      */
void sgui::GroupBox::updateTextureState(){
    if(this->bounds != this->background.getGlobalBounds()){
        float xdiff = this->bounds.left - this->background.getGlobalBounds().left;
        float ydiff = this->bounds.top - this->background.getGlobalBounds().top;
        for(auto& o : this->objects){
            sf::FloatRect objectBounds(o->getBounds());
            o->setBounds(sf::FloatRect(objectBounds.left + xdiff, objectBounds.top + ydiff, objectBounds.width, objectBounds.height));
        }

        this->background.setPosition(this->bounds.left, this->bounds.top);
        this->background.setSize(sf::Vector2f(this->bounds.width, this->bounds.height));
    }
    this->background.setFillColor(this->colorBackground);
}





/*      PUBLIC      */
void sgui::GroupBox::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;

    for(auto& o : this->objects)
        o->event(event);
}


void sgui::GroupBox::update(){
    if(!this->enable) return;
    if(!this->visible) return;

    this->updateTextureState();
    for(auto& o : this->objects)
        o->update();
}


void sgui::GroupBox::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->background);
    for(const auto& o : this->objects)
        o->render(window);
}





/*          CONTROLS          */
/*      GETTERS      */
const sf::FloatRect& sgui::GroupBox::getBounds() const{
    return this->bounds;
}
const sf::Color& sgui::GroupBox::getColorBackground() const{
    return this->colorBackground;
}
const bool& sgui::GroupBox::getEnable() const{
    return this->enable;
}
const bool& sgui::GroupBox::getVisible() const{
    return this->visible;
}





/*      SETTERS      */
void sgui::GroupBox::setBounds(const sf::FloatRect& bounds){
    this->bounds = bounds;
    this->updateTextureState();
}
void sgui::GroupBox::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
    this->updateTextureState();
}
void sgui::GroupBox::setEnable(const bool& enable){
    this->enable = enable;
    this->updateTextureState();
}
void sgui::GroupBox::setVisible(const bool& visible){
    this->visible = visible;
    this->updateTextureState();
}





/*      OTHER      */
std::vector<sgui::SguiObject*>& sgui::GroupBox::getAllObjects(){
    return this->objects;
}
void sgui::GroupBox::addObject(sgui::SguiObject* object){
    sf::FloatRect objectBounds = object->getBounds();
    object->setBounds(sf::FloatRect(objectBounds.left + this->bounds.left, objectBounds.top + this->bounds.top, 
    objectBounds.width, objectBounds.height));
    this->objects.push_back(object);
}