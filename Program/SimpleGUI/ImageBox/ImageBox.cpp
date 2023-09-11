#include "ImageBox.hpp"





/*      INITIALIZE      */
void sgui::ImageBox::initData(){
    this->freeze = false;
    this->visible = true;
    
    this->imageTexture.loadFromFile(this->imagePath);
    this->imageTextureTrim.width = this->imageTexture.getSize().x;
    this->imageTextureTrim.height = this->imageTexture.getSize().y;
    
    
    this->colorImage = __IBD_COLOR_IMAGE;
    this->colorBackground = __IBD_COLOR_BACKGROUND;
}


void sgui::ImageBox::buildTextures(){
    this->updateTextureState();
}





/*      CONSTRUCTORS      */
sgui::ImageBox::ImageBox() : ImageBox(__IBD_IMAGE, sf::FloatRect(__IBD_POSITION, __IBD_SIZE)) {}
sgui::ImageBox::ImageBox(const sf::String& imagePath) : ImageBox(imagePath, sf::FloatRect(__IBD_POSITION, __IBD_SIZE)) {}
sgui::ImageBox::ImageBox(const sf::String& imagePath, sf::FloatRect bounds) {
    this->imagePath = imagePath;
    this->bounds = bounds;
    this->initData();
    this->buildTextures();
}
sgui::ImageBox::~ImageBox(){
    
}





/*      PRIVATE      */
void sgui::ImageBox::updateTextureState(){
    if(this->freeze) return;

    float x = this->bounds.left, y = this->bounds.top;
    sf::Vector2u psize = this->imageTexture.getSize();
    float xscale = this->bounds.width / psize.x, yscale = this->bounds.height / psize.y;
    
    this->image.setPosition(x, y);
    this->image.setTexture(this->imageTexture);
    this->image.setTextureRect(this->imageTextureTrim);
    this->image.setColor(this->colorImage);
    this->image.setScale(xscale, yscale);
    
    this->background.setPosition(x, y);
    this->background.setSize(sf::Vector2f(this->image.getGlobalBounds().width, this->image.getGlobalBounds().height));
    this->background.setFillColor(this->colorBackground);
    this->freeze = true; // if there are not any changes in setters then do not update data
}





/*      PUBLIC      */
void sgui::ImageBox::event(const sf::Event& event){
    /* NONE */
}


void sgui::ImageBox::update(){
    this->updateTextureState();
}


void sgui::ImageBox::render(sf::RenderTarget* window) const{
    if(!this->visible) return;

    window->draw(this->background);
    window->draw(this->image);
}





/*          CONTROLS          */
/*      GETTERS      */
const sf::String& sgui::ImageBox::getImagePath() const{
    return this->imagePath;
}
const sf::IntRect& sgui::ImageBox::getImageTextureTrim() const{
    return this->imageTextureTrim;
}
const sf::FloatRect& sgui::ImageBox::getBounds() const{
    return this->bounds;
}
const sf::Color& sgui::ImageBox::getColorImage() const{
    return this->colorImage;
}
const sf::Color& sgui::ImageBox::getColorBackground() const{
    return this->colorBackground;
}
const bool& sgui::ImageBox::getVisible() const{
    return this->visible;
}





/*      SETTERS      */
void sgui::ImageBox::setImagePath(const sf::String& imagePath){
    this->imagePath = imagePath;
    this->imageTexture.loadFromFile(this->imagePath);
    this->freeze = false;
    this->updateTextureState();
}
void sgui::ImageBox::setImageTextureTrim(const sf::IntRect& imageTextureTrim){
    this->imageTextureTrim = imageTextureTrim;
    this->freeze = false;
    this->updateTextureState();
}
void sgui::ImageBox::setBounds(const sf::FloatRect& bounds){
    this->bounds = bounds;
    this->freeze = false;
    this->updateTextureState();
}
void sgui::ImageBox::setColorImage(const sf::Color& color){
    this->colorImage = color;
    this->freeze = false;
    this->updateTextureState();
}
void sgui::ImageBox::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
    this->freeze = false;
    this->updateTextureState();
}
void sgui::ImageBox::setVisible(const bool& visible){
    this->visible = visible;
    this->freeze = false;
    this->updateTextureState();
}