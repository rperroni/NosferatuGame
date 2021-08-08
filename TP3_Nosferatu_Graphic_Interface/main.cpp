#include "Game.h"
#include "Printer.h"
#include "GraphicMenu.h"

int main(){
    sf::RenderWindow window (sf::VideoMode(1300,700),"Nosferatu: El Regreso",sf::Style::Titlebar|sf::Style::Close);
    GraphicMenu menu;
    window.setPosition(sf::Vector2i(1050, 30)); //En el caso de posicionarse mal, comentar esta linea
    menu.startGame(window);
    window.close();
    return 0;
}
