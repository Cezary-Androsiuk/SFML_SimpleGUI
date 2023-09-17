#include "../include/TabControl.hpp"




/*      INITIALIZE      */
void sgui::TabControl::initData(){
    this->colorTab = __TCD_COLOR_TAB;
    this->colorTabHover = __TCD_COLOR_TAB_HOVER;
    this->colorTabChecked = __TCD_COLOR_TAB_CHECKED;
    this->colorBackground = __TCD_COLOR_BACKGROUND;
    this->tabButtonSize = __TCD_TAB_SIZE;

    this->enable = true;
    this->visible = true;
}


void sgui::TabControl::buildTextures(){

}





/*      CONSTRUCTORS      */
sgui::TabControl::TabControl() : TabControl(sf::FloatRect(__TCD_POSITION, __TCD_SIZE), __TCD_TAB_NAME) {}
sgui::TabControl::TabControl(sf::FloatRect bounds, std::string tabName){
    this->pos = bounds.getPosition();
    this->size = bounds.getSize();
    this->initData();
    this->addTab(tabName);
    this->currentTab = tabName;
    this->buildTextures();
}
sgui::TabControl::~TabControl(){
    for(auto& [key, gb] : this->tabs)
        delete gb;
}





/*      PRIVATE      */
void sgui::TabControl::createTab(std::string tabName){
    // this->tabNames.push_back(tabName);
    sgui::GroupBox* gb = new sgui::GroupBox(sf::FloatRect(this->pos, this->size));
    gb->setColorBackground(this->colorBackground);
    this->tabs.insert(std::pair<std::string, sgui::GroupBox*>(
        tabName, gb
    ));

}
void sgui::TabControl::centerText(sf::Text& text, const sf::FloatRect& shape){
    // text.setPosition(sf::Vector2f(
    //     shape.left + (shape.width - text.getGlobalBounds().left)/2,
    //     shape.top + (shape.height - text.getCharacterSize())/2
    // ));
    // sf::Vector2f error(text.getGlobalBounds().getPosition() - text.getPosition());
    // text.setPosition(text.getPosition() - error);
}


void sgui::TabControl::updateShapes(){
    // // set background size
    // this->background.setSize(this->size);

    // // set buttons size
    // for(auto& [key, tabButton] : this->tabButtons){
    //     // // if not virtual tab
    //     // if(key == __TCD_VT_NAME)
    //     //     continue;
        
    //     tabButton.setSize(this->tabButtonSize);
    // }
    // this->tabTextCharSize = static_cast<sf::Uint32>(this->tabButtonSize.y * __TCD_TEXT_SIZE_PCT);

    // // // set buttons text
    // // for(auto& [key, value] : this->tabTexts){
    // //     // if not virtual tab
    // //     if(key == __TCD_VT_NAME)
    // //         continue;
        
    // //     this->centerText(value, this->tabButtons.at(key).getGlobalBounds());
    // //     value.setCharacterSize(this->tabTextCharSize);
    // // }

}


void sgui::TabControl::updateColors(){
    for(auto& [key, gb] : this->tabs){
        gb->setColorBackground(this->colorBackground);
    }
}


void sgui::TabControl::updatePosition(){
    // // set background position
    // sf::Vector2f objectsOffset(this->pos - this->background.getPosition());
    // this->background.setPosition(this->pos);

    // // set buttons position
    // int i=0;
    // float x = this->pos.x, y = this->pos.y;
    // float bWidth = this->tabButtonSize.x, bHeight = this->tabButtonSize.y;
    // for(auto& [key, tabButton] : this->tabButtons){
    //     // // if not virtual tab
    //     // if(key == __TCD_VT_NAME)
    //     //     continue;
        
    //     tabButton.setPosition(x + i*bWidth, y - bHeight);
    // }

    // for(auto& [key, vector] : this->tabsObjects){
    //     for(auto& object : vector){
    //         object->setPosition(object->getPosition() + objectsOffset);
    //     }
    // }

    
}





/*      PUBLIC      */
void sgui::TabControl::event(const sf::Event& event){
    if(!this->enable) return;
    if(!this->visible) return;
    
    this->tabs.at(this->currentTab)->event(event);
}


void sgui::TabControl::update(){
    if(!this->enable) return;
    if(!this->visible) return;
    
    this->updateShapes();
    this->updateColors();
    this->updatePosition();

    this->tabs.at(this->currentTab)->update();
}


void sgui::TabControl::render(sf::RenderTarget* window) const{
    if(!this->visible) return;
    
    this->tabs.at(this->currentTab)->render(window);
}





/*      GETTERS      */
const sf::Vector2f& sgui::TabControl::getPosition() const{
    return this->pos;
}
// const sf::Vector2f& sgui::TabControl::getSize() const{
//     return this->size;
// }
// const sf::Color& sgui::TabControl::getColorTab() const{
//     return this->colorTab;
// }
// const sf::Color& sgui::TabControl::getColorTabHover() const{
//     return this->colorTabHover;
// }
// const sf::Color& sgui::TabControl::getColorTabChecked() const{
//     return this->colorTabChecked;
// }
const sf::Color& sgui::TabControl::getColorBackground() const{
    return this->colorBackground;
}
// const sf::Vector2f& sgui::TabControl::getTabButtonSize() const{
//     return this->tabButtonSize;
// }
const std::string& sgui::TabControl::getCurrentTab() const{
    return this->currentTab;
}
// const bool& sgui::TabControl::getTabEnable(std::string tabName) const{
//     return this->tabEnable.at(tabName);
// }
// const bool& sgui::TabControl::getTabVisible(std::string tabName) const{
//     return this->tabVisible.at(tabName);
// }
// const bool& sgui::TabControl::getEnable() const{
//     return this->enable;
// }
// const bool& sgui::TabControl::getVisible() const{
//     return this->visible;
// }





/*      SETTERS      */
void sgui::TabControl::setPosition(const sf::Vector2f& pos){
    this->pos = pos;
    this->updatePosition();
}
// void sgui::TabControl::setSize(const sf::Vector2f& size){
//     this->size = size;
//     this->updateShapes();
//     this->updatePosition();
// }
// void sgui::TabControl::setColorTab(const sf::Color& color){
//     this->colorTab = color;
//     this->updateColors();
// }
// void sgui::TabControl::setColorTabHover(const sf::Color& color){
//     this->colorTabHover = color;
//     this->updateColors();
// }
// void sgui::TabControl::setColorTabChecked(const sf::Color& color){
//     this->colorTabChecked = color;
//     this->updateColors();
// }
void sgui::TabControl::setColorBackground(const sf::Color& color){
    this->colorBackground = color;
    
    this->updateColors();
}
// void sgui::TabControl::setTabButtonSize(const sf::Vector2f& size){
//     this->tabButtonSize = size;
//     this->updateShapes();
//     this->updatePosition();
// }
bool sgui::TabControl::setCurrentTab(const std::string& tabName){
    if(this->tabs.find(tabName) != this->tabs.end()){
        this->currentTab = tabName;
        this->updateColors();
        this->updateShapes();
        this->updatePosition();
        return true;
    }
    else{
        return false;
    }
}
// void sgui::TabControl::setTabEnable(std::string tabName, const bool& enable){
//     this->tabEnable.at(tabName) = enable;
//     this->updateColors();
// }
// void sgui::TabControl::setTabVisible(std::string tabName, const bool& visible){
//     this->tabVisible.at(tabName) = visible;
//     this->updateColors();
//     this->updateShapes();
//     this->updatePosition();
// }
// void sgui::TabControl::setEnable(const bool& enable){
//     this->enable = enable;
//     this->updateColors();
// }
// void sgui::TabControl::setVisible(const bool& visible){
//     this->visible = visible;
//     this->updateColors();
// }





/*      OTHER      */
bool sgui::TabControl::addTab(std::string tabName){
    // check if tab already exist
    for(const auto& [key, gb] : this->tabs)
        if(key == tabName)
            return false;
    
    this->createTab(tabName);
    this->updateColors();
    this->updateShapes();
    this->updatePosition();
    return true;
}


std::vector<std::string> sgui::TabControl::getTabs() const{
    std::vector<std::string> keys;
    for(const auto& [key, gb] : this->tabs)
        keys.push_back(key);
    return keys;
}


std::vector<sgui::SguiObject*>& sgui::TabControl::getAllObjects(std::string tabName){
    return this->tabs.at(tabName)->getAllObjects();
}


bool sgui::TabControl::addObject(std::string tabName, sgui::SguiObject* object){
    for(const auto& [key, gb] : this->tabs){
        if(key == tabName){
            gb->addObject(object);
            return true;
        }
    }
    return false;
}