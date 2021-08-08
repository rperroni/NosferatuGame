#include <SFML/Graphics/RenderWindow.hpp>
#include "Printer.h"

Printer::Printer() {
    setTextures();
    this -> setFont();

}

void Printer::showTitle() {

    std::cout << gotoxy.pos(3,11) << "\033[31m  ███▄    █  ▒█████    ██████   █████▒▓█████  ██▀███   ▄▄▄     ▄▄▄█████▓ █    ██    \033[0m" << std::endl;
    std::cout << gotoxy.pos(4,11) << "\033[31m  ██ ▀█   █ ▒██▒  ██▒▒██    ▒ ▓██   ▒ ▓█   ▀ ▓██ ▒ ██▒▒████▄   ▓  ██▒ ▓▒ ██  ▓██▒   \033[0m" << std::endl;
    std::cout << gotoxy.pos(5,11) << "\033[31m ▓██  ▀█ ██▒▒██░  ██▒░ ▓██▄   ▒████ ░ ▒███   ▓██ ░▄█ ▒▒██  ▀█▄ ▒ ▓██░ ▒░▓██  ▒██░   \033[0m" << std::endl;
    std::cout << gotoxy.pos(6,11) << "\033[31m ▓██▒  ▐▌██▒▒██   ██░  ▒   ██▒░▓█▒  ░ ▒▓█  ▄ ▒██▀▀█▄  ░██▄▄▄▄██░ ▓██▓ ░ ▓▓█  ░██░   \033[0m" << std::endl;
    std::cout << gotoxy.pos(7,11) << "\033[31m ▒██░   ▓██░░ ████▓▒░▒██████▒▒░▒█░    ░▒████▒░██▓ ▒██▒ ▓█   ▓██▒ ▒██▒ ░ ▒▒█████▓    \033[0m" << std::endl;
    std::cout << gotoxy.pos(8,11) << "\033[31m ░ ▒░   ▒ ▒ ░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░ ▒ ░    ░░ ▒░ ░░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ▒ ░░   ░▒▓▒ ▒ ▒    \033[0m" << std::endl;
    std::cout << gotoxy.pos(9,11) << "\033[31m    ░   ░ ░ ░ ░ ░ ▒  ░  ░  ░   ░ ░       ░     ░░   ░   ░   ▒    ░       ░░░ ░ ░    \033[0m" << std::endl;
    std::cout << gotoxy.pos(10,11) << "\033[31m          ░     ░ ░        ░             ░  ░   ░           ░  ░           ░        \033[0m" << std::endl;

}

void Printer::showMainMenu() {

    std::cout << gotoxy.pos(16,24) << "\033[47;30;1m       SELECCIONE UNA OPCION (Ingrese un numero)       \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,30) << "\033[47;30;1m[1]  AGREGAR UN NUEVO OBJETO AL MAPA.      \033[0m" << std::endl;
    std::cout << gotoxy.pos(22,30) << "\033[47;30;1m[2]    ELIMINAR UN OBJETO DEL MAPA.        \033[0m" << std::endl;
    std::cout << gotoxy.pos(25,30) << "\033[47;30;1m[3]         MOSTRAR EL MAPA.               \033[0m" << std::endl;
    std::cout << gotoxy.pos(28,30) << "\033[47;30;1m[4]  BUSCAR POR CUADRANTE EN EL MAPA.      \033[0m" << std::endl;
    std::cout << gotoxy.pos(31,30) << "\033[47;30;1m[5]  BUSCAR POR ID DETALLES DE OBJETO.     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,30) << "\033[47;30;1m[6]        COMENZAR SIMULACION.            \033[0m" << std::endl;
    std::cout << gotoxy.pos(37,30) << "\033[47;30;1m[0]               SALIR.                   \033[0m" << std::endl;

}

void Printer::showIntro() {

    cout << gotoxy.pos(21,23) << "\033[47;30;1mNosferatu renació de las cenizas luego de varios  \033[0m" << endl;
    cout << gotoxy.pos(22,23) << "\033[47;30;1maños de letargo, sorprendiendo a los vampirólogos \033[0m" << endl;
    cout << gotoxy.pos(23,23) << "\033[47;30;1mque habían desechado la posibilidad de su regreso.\033[0m" << endl;
    cout << gotoxy.pos(24,23) << "\033[47;30;1mEsta vez vuelve más poderoso: Creó una alianza con\033[0m" << endl;
    cout << gotoxy.pos(25,23) << "\033[47;30;1mVampirella y un ejército de zombis con la finalidad\033[0m" << endl;
    cout << gotoxy.pos(26,23) << "\033[47;30;1mde dominar el mundo. \033[0m" << endl;

}

void Printer::showMap(Map *map) {

}

void Printer::showNotAbleToMove(int originX, int originY, sf::RenderWindow &window) {
    sf::Text errorText;

    this -> setFont();

    errorText.setFont(this -> font);
    errorText.setFillColor(sf::Color::Red);
    errorText.setOutlineColor(sf::Color::Yellow);
    errorText.setCharacterSize(20);
    errorText.setPosition(50, 550);

    std::string originXs = to_string(originX);
    std::string originYs = to_string(originY);

    errorText.setString("No hay objeto en las coordenadas:\nCoordenada X: " + originXs + ".\nCoordenada Y: " + originYs + ".");

    window.draw(errorText);

    window.display();
}

void Printer::showMap(Vertex*** graph, sf::RenderWindow &window) {
    window.clear();

    sf::Sprite terrainSprite;
    sf::Texture terrainTexture;

    for (int i = 0; i < 8; ++i) {

        for (int j = 0; j < 8; ++j) {

            terrainTexture = graph[i][j]->getCell()->getTexture();

            terrainSprite.setTexture(terrainTexture);

            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);

        }
    }
}


void Printer::showMap(Matrix<Vertex*>* matrix, sf::RenderWindow &window) {
    window.clear();
    //CONSOLA
    /*
    mainWindow();
     */
    int coordY = 20;
    std::cout << gotoxy.pos(coordY - 1 ,31);

    sf::Sprite terrainSprite;
    sf::Texture terrainTexturrre;
    /*
    text.setCharacterSize(15);
    text.setString("-LAKE");
    terrainTexturrre = matrix -> getData(1, 1) -> getCell() -> getTexture();
    terrainSprite.setTexture(terrainTexturrre);
    terrainSprite.setPosition(600 + 0 * 70, 50 + 0 * 70);
    text.setPosition(670 + 0 * 70, 70 + 0 * 70);
    window.draw(text);
    window.draw(terrainSprite);

    text.setString("-VOLCANO");
    terrainSprite.setTexture(matrix -> getMatrix()[6][0] -> getCell() -> getTexture());
    terrainSprite.setPosition(600 + 0 * 70, 50 + 1 * 70);
    text.setPosition(670 + 0 * 70, 70 + 1 * 70);
    window.draw(terrainSprite);
    window.draw(text);

    text.setString("-ROAD");
    terrainSprite.setTexture(matrix -> getMatrix()[3][1] -> getCell() -> getTexture());
    terrainSprite.setPosition(600 + 0 * 70, 50 + 2 * 70);
    text.setPosition(670 + 0 * 70, 70 + 2 * 70);
    window.draw(text);
    window.draw(terrainSprite);

    text.setString("-CLIFF");
    terrainSprite.setTexture(matrix -> getMatrix()[2][0] -> getCell() -> getTexture());
    terrainSprite.setPosition(600 + 0 * 70, 50 + 3 * 70);
    text.setPosition(670 + 0 * 70, 70 + 3 * 70);
    window.draw(text);
    window.draw(terrainSprite);

    text.setString("-MOUNTAIN");
    terrainSprite.setTexture(matrix -> getMatrix()[6][0] -> getCell() -> getTexture());
    terrainSprite.setPosition(600 + 0 * 70, 50 + 4 * 70);
    text.setPosition(670 + 0 * 70, 70 + 4 * 70);
    window.draw(text);
    window.draw(terrainSprite);

    text.setString("-THE VOID");
    terrainSprite.setTexture(matrix -> getMatrix()[7][4] -> getCell() -> getTexture());
    terrainSprite.setPosition(600 + 0 * 70, 50 + 5 * 70);
    text.setPosition(670 + 0 * 70, 70 + 5 * 70);
    window.draw(text);
    window.draw(terrainSprite);

    text.setString("Game map");
    text.setPosition(690 + 0.5 * 70,  + 7 * 70);
    window.draw(text);
*/

    sf::Text objectText;
    objectText.setFont(font);
    objectText.setCharacterSize(20);

    sf::Texture zombieTexture;
    zombieTexture.loadFromFile("Zombie2.png");

    sf::Sprite zombie;
    zombie.setTexture(zombieTexture);


    sf::Texture holyWaterTexture;
    sf::Sprite sprite2;

    holyWaterTexture.loadFromFile("HO.png");
    sprite2.setTexture(holyWaterTexture);

    sf::Texture terrainTexture;
    sf::Sprite beingSprite;
    sf::Texture beingTexture;
    sf::Texture elementTexture;
    sf::Sprite elementSprite;

    for (int i = 0; i < matrix->getHeight() ; ++i) {

        for (int j = 0; j < matrix->getWidth() ; ++j) {

            terrainTexture = matrix -> getData(i,j) -> getCell() -> getTexture();

            terrainSprite.setTexture(terrainTexture);

            std::cout << matrix -> getData(i,j) -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";
            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);


            if ( matrix -> getData(i,j) -> getBeing()) {
                cout << matrix->getData(i, j)->getBeing()->getCharName() << " ";

                beingTexture = matrix->getData(i, j)->getBeing()->getTexture();

                beingSprite.setTexture(beingTexture);

                beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                window.draw(beingSprite);
            }


            if (matrix -> getData(i,j) -> getElement() ) { // PONER ELSE IF PARA VER POR CONSOLA.
                cout << matrix->getData(i, j)->getElement()->getCharName() << " ";

                elementTexture = matrix->getData(i, j)->getElement()->getTexture();

                elementSprite.setTexture(elementTexture);

                elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                window.draw(elementSprite);
            }

            else {
                cout << "  ";
            }

            cout << END_COLOR << "\033[40m  \033[0m";
            cout << END_COLOR;
        }
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i,31);
    }

    this -> showTerrainReferences();
    this -> showBeingReferences();
}

void Printer::showMap(Matrix<Vertex*>* matrix) {

    mainWindow();
    int coordY = 20;

    std::cout << gotoxy.pos(coordY - 1 ,31);

    for (int i = 0; i < matrix->getHeight() ; ++i) {

        for (int j = 0; j < matrix->getWidth() ; ++j) {

            std::cout << matrix -> getData(i,j) -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";

            if ( matrix -> getData(i,j) -> getBeing()) {
                cout << matrix->getData(i, j)->getBeing()->getCharName() << " ";
            }

            else if (matrix -> getData(i,j) -> getElement() ) {
                cout << matrix->getData(i, j)->getElement()->getCharName() << " ";
            }


            else {
                cout << "  ";
            }

            cout << END_COLOR << "\033[40m  \033[0m";
            cout << END_COLOR;
        }
        cout << "" << endl;
        coordY++;
        std::cout << gotoxy.pos(coordY + i,31);
    }

    this -> showTerrainReferences();
    this -> showBeingReferences();
}

void Printer::showSavedGame() {

}

void Printer::showActionMenu() {

    cout << gotoxy.pos(21,38) << " [1]   Defenderse " << endl;
    cout << gotoxy.pos(21,40) << " [2]     Atacar   " << endl;
    cout << gotoxy.pos(21,42) << " [3]     Moverse  " << endl;
    cout << gotoxy.pos(21,44) << " [4]   Pasar Turno " << endl;

}

void Printer::showPreparationMenu() {

}

void Printer::showIdMenu() {

    std::cout << gotoxy.pos(34, 4) << "\033[47;30;1m INGRESE ID \033[0m" << std::endl;
}

void Printer::showGameArea() {

    std::cout << gotoxy.pos(12,1) << "█" << std::endl;
    std::cout << gotoxy.pos(12,100) << "█" << std::endl;

    for(int i = 2; i <= 99; i++){
        std::cout << gotoxy.pos(12, i) << "█" << std::endl;
    }
    for(int i = 13; i <= 45; i++){

        std::cout << gotoxy.pos(i, 1) << "█" << std::endl;
        std::cout << gotoxy.pos(i, 100) << "█" << std::endl;

    }
    for(int i = 2; i <= 99; i++){
        std::cout << gotoxy.pos(45, i) << "█" << std::endl;
    }

    std::cout << gotoxy.pos(45,1) << "█" << std::endl;
    std::cout << gotoxy.pos(45,100) << "█" << std::endl;


    for(int i = 2; i <= 99; i++){
        for(int j = 13; j <= 44; j++){
            std::cout << gotoxy.pos(j, i) << "\033[40m \033[0m" << std::endl;
        }
    }

}

void Printer::showObjectsMenu() {

    std::cout << gotoxy.pos(15,33) << "\033[47;30;1m     SELECCIONE EL TIPO DE OBJETO     \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,10) << "\033[47;30;1m[1]    HUMANO      \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,42) << "\033[47;30;1m[2]    CAZADOR     \033[0m" << std::endl;
    std::cout << gotoxy.pos(19,75) << "\033[47;30;1m[3]    VANESA      \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,10) << "\033[47;30;1m[4]    ZOMBIE      \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,42) << "\033[47;30;1m[5]    VAMPIRO     \033[0m" << std::endl;
    std::cout << gotoxy.pos(24,75) << "\033[47;30;1m[6]   NOSFERATU    \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,10) << "\033[47;30;1m[7]   VAMPIRELLA   \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,42) << "\033[47;30;1m[8]      AGUA      \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,75) << "\033[47;30;1m[9]     ESTACA     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,10) << "\033[47;30;1m[10]    CRUCES     \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,42) << "\033[47;30;1m[11]   ESCOPETA    \033[0m" << std::endl;
    std::cout << gotoxy.pos(34,75) << "\033[47;30;1m[12]     BALA      \033[0m" << std::endl;

}

void Printer::showQuadrantsMenu() {

    std::cout << gotoxy.pos(20,36) << "\033[47;30;1m    SELECCIONE EL CUADRANTE    \033[0m" << std::endl;
    std::cout << gotoxy.pos(23,45) << "\033[47;30;1m[1]    NO    \033[0m" << std::endl;
    std::cout << gotoxy.pos(26,45) << "\033[47;30;1m[2]    NE    \033[0m" << std::endl;
    std::cout << gotoxy.pos(29,45) << "\033[47;30;1m[3]    SO    \033[0m" << std::endl;
    std::cout << gotoxy.pos(32,45) << "\033[47;30;1m[4]    SE    \033[0m" << std::endl;

}

void Printer::showSimulationMenu() {

    cout << gotoxy.pos(21,38) << " [1] Buscar por ID " << endl;
    cout << gotoxy.pos(21,40) << " [2] Mostrar tablero " << endl;
    cout << gotoxy.pos(21,42) << " [3] Mostrar integrantes " << endl;
    cout << gotoxy.pos(21,44) << " [4] Seleccionar bando " << endl;
    cout << gotoxy.pos(21,46) << " [5] Salir " << endl;

}

void Printer::showInputSpot() {
    std::cout << gotoxy.pos(35, 4) << "\033[47;30;1m----> \033[0m" << "  ";

}

void Printer::mainWindow() {
    system(CLEAR);
    showTitle();
    showGameArea();
}

void Printer::voidReferences() {
}

void Printer::showTerrainReferences() {
    cout << gotoxy.pos(21,74) << "\033[40m» LAGO       " << "\033[48;5;51m  " << END_COLOR;
    cout << gotoxy.pos(23,74) << "\033[40m» VOLCAN     " << "\033[48;5;160m  "<<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(25,74) << "\033[40m» PRECIPICIO " << "\033[48;5;31m  "<<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(27,74) << "\033[40m» MONTAÑA    " << "\033[48;5;94m  "<<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(29,74) << "\033[40m» CAMINO     " << "\033[48;5;247m  "<<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(31,74) << "\033[40m» VACIO      " << "\033[48;5;5m  "<<END_COLOR<< END_COLOR;;
}

void Printer::showBeingReferences() {
    cout << gotoxy.pos(15,11) << "\033[40m» VANESA      W "  << END_COLOR;
    cout << gotoxy.pos(17,11) << "\033[40m» HUMANO      h "  << END_COLOR;
    cout << gotoxy.pos(19,11) << "\033[40m» CAZADOR     C " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(21,11) << "\033[40m» ZOMBI       z " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(23,11) << "\033[40m» NOSFERATU   N " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(25,11) << "\033[40m» VAMPIRELLA  V " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(27,11) << "\033[40m» VAMPIRO     v " << END_COLOR;
    cout << gotoxy.pos(29,11) << "\033[40m» AGUA        A " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(31,11) << "\033[40m» CRUZ        C " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(33,11) << "\033[40m» ESTACA      e " <<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(35,11) << "\033[40m» ESCOPETA    E "<<END_COLOR<< END_COLOR;;
    cout << gotoxy.pos(37,11) << "\033[40m» BALA        b "  <<END_COLOR<< END_COLOR;;

}

void Printer::optionClear(){

    std::cout << gotoxy.pos(40,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(41,5) << "\033[40m                                                  \033[0m";
    std::cout << gotoxy.pos(42,5) << "\033[40m                                                 \033[0m";
    std::cout << gotoxy.pos(43,5) << "\033[40m                                                  \033[0m";

}

void Printer::showFoundMessage(std::string quadrant, std::string wantedName){
    std::cout << gotoxy.pos(41,30) << "\033[47;30;1m El objeto: " << wantedName <<", se encuentra en el cuadrante: " << quadrant << END_COLOR << std::endl;



}

void Printer::showNotFoundMessage(std::string quadrant, std::string wantedName){
    std::cout << gotoxy.pos(41,30) << "El objeto: " << wantedName <<", no se encuentra en el cuadrante: " << quadrant << END_COLOR << std::endl;
}

//sf::Sprite Printer::getTerrainSprite(string charTerrain) {
//    sf::Sprite sprite;
//    return sf::Sprite();
//}

void Printer::setTextures() {
/*
    this->terrainTexture[0].loadFromFile("lake.png");
    this->terrainTexture[1].loadFromFile("volcano2.png");
    this->terrainTexture[2].loadFromFile("road.png");
    this->terrainTexture[3].loadFromFile("cliff.png");
    this->terrainTexture[4].loadFromFile("Mountain.png");
    this->terrainTexture[5].loadFromFile("TheVoid.png");

    this->elementTextures[0].loadFromFile("Cross.png");
    this->elementTextures[1].loadFromFile("Stake.png");
    this->elementTextures[2].loadFromFile("Holywater.png");
    this->elementTextures[3].loadFromFile("Bullet.png");
    this->elementTextures[4].loadFromFile("Shotgun.png");
//
    this->beingTextures[0].loadFromFile("Human.png");
    this->beingTextures[1].loadFromFile("Hunter.png");
    this->beingTextures[2].loadFromFile("Vanesa.png");
    this->beingTextures[3].loadFromFile("Zombie.png");
    this->beingTextures[4].loadFromFile("Vampire.png");
    this->beingTextures[5].loadFromFile("Vampirella.png");
    this->beingTextures[6].loadFromFile("Nosferatu.png");
    */
}

void Printer::showAddObject(Matrix<Vertex *> *matrix, sf::RenderWindow &window) {
    window.clear();
    text.setString("INGRESE QUE TIPO DE OBJETO DESEA AGREGAR");
    text.setPosition(400,300);
    window.draw(text);
    text.setString("1- SERES");
    text.setPosition(500,350);
    window.draw(text);
    text.setString("2- ELEMENTOS");
    text.setPosition(500,400);
    window.draw(text);
    bool finish = false;
    while(!finish){
        if (stoi(validateEntry(window))== 1){
            window.clear();
            showBeings(window);
            finish = true;
        }
        else if((stoi(validateEntry(window))) == 2) {
            showElements(window);
            window.clear();
            finish = true;
        }
        else{
            text.setString("Ingreso incorrecto");
            finish = false;
        }
    }

    showMap(matrix,window);

    string coordx,coordy;
    text.setString("BUSQUEDA");
    text.setPosition(600,20);
    text.setCharacterSize(40);
    window.draw(text);
    showCoordinateInput(window,matrix,&coordy,&coordx);

    if (matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getBeing()){
        matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getBeing()->show();
        showObject(window,matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getBeing());
    }
    else if (matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getElement()){
        matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getElement()->show();
        showObject(window,matrix->getData(stoi(coordy)-1,stoi(coordx)-1)->getElement());
    }
    else {
        text.setString("Posicion vacia");
        text.setPosition(600,500);
        window.draw(text);
        cout <<"Posicion vacia" << endl;
    }
    window.display();

}

string Printer::validateEntry(sf::RenderWindow &window) {
    sf::Event event;
    string input = "";
    bool finish = false;
    while (!finish){
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:window.close();break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Num0:
                            input += "0";
                            break;
                        case sf::Keyboard::Num1:
                            input += "1";
                            break;
                        case sf::Keyboard::Num2:
                            input += "2";
                            break;
                        case sf::Keyboard::Num3:
                            input += "3";
                            break;
                        case sf::Keyboard::Num4:
                            input += "4";
                            break;
                        case sf::Keyboard::Num5:
                            input += "5";
                            break;
                        case sf::Keyboard::Num6:
                            input += "6";
                            break;
                        case sf::Keyboard::Num7:
                            input += "7";
                            break;
                        case sf::Keyboard::Num8:
                            input += "8";
                            break;
                        case sf::Keyboard::Num9:
                            input += "9";
                            break;
                        case sf::Keyboard::Enter:
                            finish = true;
                            break;
                        default:
                            break;
                    }
            }
        }
    }
    return input;
}

void Printer::setFont() {
    font.loadFromFile("MenuFont.ttf");
    text.setFont(font);
}

void Printer::showObject(sf::RenderWindow &window, Object *item) {
    sf::Sprite sprite;
    sf::Texture texture;
    texture = item->getTexture();
    sprite.setTexture(texture);
    sprite.setPosition(630,400);
    window.draw(sprite);
    text.setString("Nombre: "+ item->getObjectName());
    text.setPosition(700,400);
    window.draw(text);
    text.setString("ID: " + std::to_string(item->getId()));
    text.setPosition(700,450);
    window.draw(text);
}

void Printer::showCoordinateInput(sf::RenderWindow &window, Matrix<Vertex*>* matrix,string* row, string* col) {
    text.setString("FILA: ");
    text.setPosition(600,100);
    window.draw(text);
    window.display();
    bool finish = false;
    while(!finish){
        *(row) = validateEntry(window);
        if (0 < stoi(*row) && stoi(*row) <= matrix->getHeight()){
            finish = true;
            text.setString(*row);
            text.setPosition(850,100);
            window.draw(text);
            window.display();
        }
        else{
            text.setString("Ingreso incorrecto, reingrese");
            text.setPosition(900, 640);
            window.draw(text);
            window.display();
            cout << "Carga erronea de filas" << endl;
        }
    }
    cout << "Carga correcta de filas" << endl;
    text.setString("COLUMNA : ");
    text.setPosition(600,200);
    window.draw(text);
    window.display();
    finish = false;
    while(!finish){
        cout << "Carga de columnas" << endl;
        *col = validateEntry(window);

        if (0 < stoi(*col) && stoi(*col) <= matrix->getHeight()) {
            finish = true;
            text.setString(*col);
            text.setPosition(850,200);
            window.draw(text);
            window.display();
        }
        else{
            text.setString("Ingreso incorrecto, reingrese");
            text.setPosition(900, 500);
            window.draw(text);
            window.display();
            cout << "Carga erronea de columnas" << endl;
        }
    }
}

void Printer::showBeings(sf::RenderWindow &window) {
//    sf::Sprite sprite;
//    for (int i = 0; i < 7 ; ++i) {
//        sprite.setTexture(beingTextures[i]);
//        sprite.setPosition(50,50 + i * 60);
//        text.setString(BEING_NAMES[i]);
//        text.setPosition(100,50 + i *60);
//        window.draw(sprite);
//        window.draw(text);
//    }
}

void Printer::showElements(sf::RenderWindow &window) {
//    sf::Sprite sprite;
//    for (int i = 0; i < 5 ; ++i) {
//        sprite.setTexture(elementTextures[i]);
//        sprite.setPosition(50,50 + i * 60);
//        text.setString(ELEMENT_NAMES[i]);
//        text.setPosition(100,50 + i *60);
//        window.draw(sprite);
//        window.draw(text);
//    }
}

