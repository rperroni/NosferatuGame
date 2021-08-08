#include "GraphicMenu.h"

GraphicMenu::GraphicMenu() {
    setMenuText();
    setStartText();
    setInstructionalText();
    setStandbyText();
}

void GraphicMenu::drawMenu(sf::RenderWindow &window){
    gameBackgrounds.draw(window);
    window.draw(instructionalText[1]);
    for(const auto & i : menu)
        window.draw(i);
}

void GraphicMenu::startGame(sf::RenderWindow &window){
    gameBackgrounds.draw(window);
    window.draw(instructionalText[0]);
    window.draw(title);
    window.display();
    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:window.close();break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            drawInitialMenu(window);
                            break;
                        case sf::Keyboard::Up:
                            changeOptionSelector(window, -1);
                            break;
                        case sf::Keyboard::Down:
                            changeOptionSelector(window, 1);
                            break;

                        case sf::Keyboard::BackSpace:
                            allowActions = true;
                            drawInitialMenu(window);
                            break;
                        case sf::Keyboard::Enter:
                            drawStandbyScreen(window);
                            if (gameCycle.playVideo(returnChosenOption() + 1,window))
                                window.close();
                            break;
                        default:break;
                    }
            window.display();
            }
        }
    }
}


void GraphicMenu:: MoveSelector(int move){
    if (move == -1){
        if (selectedItemIndex == 0){
            menu[selectedItemIndex].setString(OPTIONNAMES[selectedItemIndex]);
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex = MAX_NUMBER_OF_ITEMS-1;
            menu[selectedItemIndex].setString(OPTIONNAMES2[selectedItemIndex]);
            menu[selectedItemIndex].setFillColor(sf::Color::Red);}
        else defaultMove(move);}
    else if (move == 1){
        if (selectedItemIndex == MAX_NUMBER_OF_ITEMS-1){
            menu[selectedItemIndex].setString(OPTIONNAMES[selectedItemIndex]);
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex = 0;
            menu[selectedItemIndex].setString(OPTIONNAMES2[selectedItemIndex]);
            menu[selectedItemIndex].setFillColor(sf::Color::Red);}
        else defaultMove(move);}
}

int GraphicMenu::returnChosenOption(){
    return selectedItemIndex;
}

void GraphicMenu::setStartText() {

    font2.loadFromFile("Necropsy.ttf");
    title.setFont(font2);
    title.setString("NOSFERATU");
    title.setPosition(80,60);
    title.setCharacterSize(200);
    title.setOutlineThickness(10);
    title.setFillColor(sf::Color::White);
    title.setOutlineColor(sf::Color::Black);
    instructionalText[0].setFont(font2);
    instructionalText[0].setCharacterSize(40);
    instructionalText[0].setString(INSTRUCTIONALMESSAGES[0]);
    instructionalText[0].setPosition(sf::Vector2f(345,600));
    instructionalText[0].setOutlineColor(sf::Color::Black);
    instructionalText[0].setOutlineThickness(5);
}

void GraphicMenu::setMenuText() {
    if (!font.loadFromFile("MenuFont.ttf")){}



    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setOutlineColor(sf::Color::Black);
        menu[i].setOutlineThickness(5);
        menu[i].setFont(font);
        menu[i].setCharacterSize(40);
        menu[i].setString(OPTIONNAMES[i]);
        menu[i].setPosition(sf::Vector2f(WIDHT-835,200 + i * 50));
    }
    menu[0].setString(OPTIONNAMES2[0]);
    menu[0].setFillColor(sf::Color::Red);
    selectedItemIndex = 0;
}

void GraphicMenu::setInstructionalText() {
    instructionalText[1].setFont(font);
    instructionalText[1].setCharacterSize(35);
    instructionalText[1].setString(INSTRUCTIONALMESSAGES[1]);
    instructionalText[1].setPosition(sf::Vector2f(WIDHT-835,20));
    instructionalText[1].setFillColor(sf::Color::Red);
}

void GraphicMenu::setStandbyText() {

    instructionalText[2].setFont(font);
    instructionalText[2].setCharacterSize(35);
    instructionalText[2].setString(INSTRUCTIONALMESSAGES[2]);
    instructionalText[2].setPosition(sf::Vector2f(WIDHT-835,320));
    instructionalText[2].setFillColor(sf::Color::Red);
    instructionalText[2].setStyle(sf::Text::Italic);
}

void GraphicMenu::defaultMove(int move) {
    menu[selectedItemIndex].setString(OPTIONNAMES[selectedItemIndex]);
    menu[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex += move;
    menu[selectedItemIndex].setString(OPTIONNAMES2[selectedItemIndex]);
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
}

void GraphicMenu::drawStandbyScreen(sf::RenderWindow &window) {
    window.clear();
    gameBackgrounds.changeBackground(FILESNAMES[1]);
    gameBackgrounds.draw(window);
    window.draw(instructionalText[2]);
    window.display();
    allowActions = false;
}

void GraphicMenu::changeOptionSelector(sf::RenderWindow &window, int move) {
    if (allowActions){
    window.clear();
    MoveSelector(move);
    drawMenu(window);
    }
}

void GraphicMenu::drawInitialMenu(sf::RenderWindow &window) {
    if (allowActions){
        window.clear();
        gameBackgrounds.changeBackground(FILESNAMES[0]);
        gameBackgrounds.draw(window);
        drawMenu(window);
        window.draw(instructionalText[1]);
    }
}

GraphicMenu::~GraphicMenu() {

}

