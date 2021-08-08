#include "Background.h"

Background::Background(){
    if (!backgroundTexture.loadFromFile("bloodBackGround2.png"));
    backgroundSprite.setTexture(backgroundTexture);
//    backgroundTexture.setSmooth(true);
}

void Background::changeBackground(std::string newBackground){
    if (backgroundTexture.loadFromFile(newBackground))
        backgroundSprite.setTexture(backgroundTexture);
}

void Background::draw(sf::RenderWindow &window){
    window.draw(backgroundSprite);
}