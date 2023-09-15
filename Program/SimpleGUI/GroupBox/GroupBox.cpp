#include "GroupBox.hpp"




/*      INITIALIZE      */
void sgui::GroupBox::initData(){
    this->enable = true;
    this->visible = true;

    this->colorBackground = __GBD_COLOR_BACKGROUND;
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
}





/*      PRIVATE      */
void sgui::GroupBox::updateTextureState(){
    if(this->bounds == this->background.getGlobalBounds()){
        // for(auto& i : this->objects)
        //     i.

        this->background.setPosition(this->bounds.left, this->bounds.top);
        this->background.setSize(sf::Vector2f(this->bounds.width, this->bounds.height));
    }
    this->background.setFillColor(this->colorBackground);
}





/*      PUBLIC      */
void sgui::GroupBox::event(const sf::Event& event){
    for(auto& i : this->objects)
        i->event(event);
}


void sgui::GroupBox::update(){
    for(auto& i : this->objects)
        i->update();
}


void sgui::GroupBox::render(sf::RenderTarget* window) const{
    for(const auto& i : this->objects)
        i->render(window);
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
void sgui::GroupBox::addObject(sgui::SguiObject* object){
    this->objects.push_back(object);
}