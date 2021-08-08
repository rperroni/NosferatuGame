#include "GraphicOptions.h"

GraphicOptions::GraphicOptions() {
    this -> graphicText = sf::Text();
    background.changeBackground("bloodBackGround2.png");
    graphicFont.loadFromFile("OptionsFont.ttf");
    graphicText.setFont(graphicFont);
    graphicText.setCharacterSize(30);
    graphicText.setFillColor(sf::Color::White);

    graphicText.setOutlineColor(sf::Color::Black);
    graphicText.setOutlineThickness(5);

    loadTerrainTextures();
    loadBeingTextures();
    loadElementTextures();
}

void GraphicOptions::loadBeingTextures() {
    this->beingTextures[0].loadFromFile("Human.png");
    this->beingTextures[1].loadFromFile("Hunter.png");
    this->beingTextures[2].loadFromFile("Vanesa.png");
    this->beingTextures[3].loadFromFile("Zombie.png");
    this->beingTextures[4].loadFromFile("Vampire.png");
    this->beingTextures[5].loadFromFile("Vampirella.png");
    this->beingTextures[6].loadFromFile("Nosferatu.png");
}

void GraphicOptions::loadElementTextures() {
    this->elementTextures[0].loadFromFile("Cross.png");
    this->elementTextures[1].loadFromFile("Stake.png");
    this->elementTextures[2].loadFromFile("Holywater.png");
    this->elementTextures[3].loadFromFile("Bullet.png");
    this->elementTextures[4].loadFromFile("Shotgun.png");
}

void GraphicOptions::loadTerrainTextures() {
    this->terrainTexture[0].loadFromFile("Lake.png");
    this->terrainTexture[1].loadFromFile("Volcano.png");
    this->terrainTexture[2].loadFromFile("Road.png");
    this->terrainTexture[3].loadFromFile("Cliff.png");
    this->terrainTexture[4].loadFromFile("Mountain.png");
    this->terrainTexture[5].loadFromFile("TheVoid.png");
}

void GraphicOptions::editCustomText(int row, int column, const string& text) {
    this -> graphicText.setString(text);
    this -> graphicText.setPosition(column * 1.0, row * 1.0);
}

void GraphicOptions::showMap(sf::RenderWindow &window, Map* map) {
    background.draw(window);
    showBoard(window,map);
    this -> showMapReferences(window);

    awaitingInteraction(window);
}

void GraphicOptions::showMapReferences(sf::RenderWindow &window) {
    this -> showTerrainReferences(window, 600, 50);

    this -> showBeingTextures(window, 835, 48);
    this -> showBeingTexts(window, HYPHENATED_BEING_NAMES, 880, 60);

    this -> showElementTextures(window, 1060, 62);
    this -> showElementTexts(window, HYPHENATED_ELEMENT_NAMES, 1090, 50);

}

void GraphicOptions::showTerrainReferences(sf::RenderWindow &window, int xPosition, int yPosition) {

    for (int i = 0; i < MAX_TERRAIN_NAMES; ++i) {
        this -> graphicSprite.setTexture(this -> terrainTexture[i]);
        this -> graphicSprite.setPosition(xPosition, yPosition + i * 70);
        cout << HYPHENATED_TERRAIN_NAMES[i] << endl;
        graphicText.setString(HYPHENATED_TERRAIN_NAMES[i]);
        graphicText.setPosition(xPosition + 70, yPosition + 10 + i * 70);
//        this -> editCustomText(xPosition, yPosition + 70 + i * 70, HYPHENATED_TERRAIN_NAMES[i]);

        window.draw(graphicSprite);
        window.draw(graphicText);
    }
//    window.display();
}

void GraphicOptions::showBeingTextures(sf::RenderWindow &window, int xPosition, int yPosition) {
    for (int i = 0; i < MAX_BEING_NAMES; ++i) {
        sf::Texture asd;
        asd = this->beingTextures[i];
        this -> graphicSprite.setTexture(asd);
        this -> graphicSprite.setPosition(xPosition, yPosition + i * 60);
        window.draw(graphicSprite);
    }
//    window.display();
}

void GraphicOptions::showBeingTexts(sf::RenderWindow &window, const std::string* names, int xPosition, int yPosition) {
    for (int i = 0; i < MAX_BEING_NAMES; ++i) {
        cout << names[i] << endl;
        this -> graphicText.setString(names[i]);
        this -> graphicText.setPosition( xPosition , yPosition+ i * 60);
        window.draw(graphicText);
    }
}

void GraphicOptions::showElementTextures(sf::RenderWindow &window, int xPosition, int yPosition) {

    for (int i = 0; i < MAX_ELEMENT_NAMES; ++i) {
        this -> graphicSprite.setTexture(this->elementTextures[i]);
        this -> graphicSprite.setPosition(xPosition, yPosition + 10 + i * 60);
        window.draw(graphicSprite);
    }
}

void GraphicOptions::showElementTexts(sf::RenderWindow &window, const std::string* names, int xPosition, int yPosition) {

    for (int i = 0; i < MAX_ELEMENT_NAMES; ++i) {
        graphicText.setPosition(xPosition,yPosition + 12 + i * 60);
        graphicText.setString(names[i]);
        cout << names[i] << endl;
        window.draw(graphicText);
    }
}

void GraphicOptions::setFont(std::string fontName) {
    this -> graphicFont.loadFromFile(fontName);
}


void GraphicOptions::moveObject(sf::RenderWindow &window, Map *map) {
    window.clear();

    background.draw(window);

    showBoard(window, map);

    graphicText.setString("Ingrese las coordenadas del objeto a mover");
    graphicText.setPosition(600,300);
    window.draw(graphicText);


    graphicText.setString("Fila : ");
    graphicText.setPosition(600,400);
    window.draw(graphicText);

    graphicText.setString("Columna : ");
    graphicText.setPosition(600,500);
    window.draw(graphicText);

    window.display();
    cout << "2222" << endl;

    std::string row = showCoordinateInput(window, map -> getHeight());
    graphicText.setString(row);
    graphicText.setPosition(675, 400);
    window.draw(graphicText);

    window.display();

    std::string column = showCoordinateInput(window, map -> getWidth());
    cout << "3333" << endl;

    graphicText.setString(column);
    graphicText.setPosition(730, 500);
    window.draw(graphicText);

    window.display();
    sleep(1);

    window.clear();

    background.draw(window);

    showBoard(window, map);

    int rowInt = stoi(row) - 1;
    int columnInt = stoi(column) - 1;

    if (map -> getMatrix() ->getMatrix()[rowInt][columnInt] -> getBeing()) {
        cout << "$444" << endl;
        graphicText.setString("Ingrese las coordenadas de destino");
        graphicText.setPosition(600,300);
        window.draw(graphicText);


        graphicText.setString("Fila : ");
        graphicText.setPosition(600,400);
        window.draw(graphicText);

        graphicText.setString("Columna : ");
        graphicText.setPosition(600,500);
        window.draw(graphicText);

        window.display();

        row = showCoordinateInput(window, map -> getHeight());
        graphicText.setString(row);
        graphicText.setPosition(675, 400);
        window.draw(graphicText);

        window.display();

        column = showCoordinateInput(window, map -> getWidth());
        graphicText.setString(column);
        graphicText.setPosition(730, 500);
        window.draw(graphicText);

        window.display();
        sleep(1);

        window.clear();


        background.draw(window);

        window.display();


        if (! (map -> getMatrix() ->getMatrix()[stoi(row) - 1][stoi(column) - 1] -> getBeing()) ) {
            Floyd floyd(map);
            floyd.minimumPath(columnInt, rowInt, stoi(column) - 1, stoi(row) - 1, window);
        }

        else {
            graphicText.setString("La posicion de destino esta ocupada.");
            graphicText.setPosition(800,500);
            graphicText.setFillColor(sf::Color::Red);
            window.draw(graphicText);
            window.display();
            sleep(2);
            graphicText.setFillColor(sf::Color::White);
            moveObject(window, map);
        }
    }

    else {
        graphicText.setString("No hay nadie para mover, reingrese");
        graphicText.setPosition(800,500);
        graphicText.setFillColor(sf::Color::Red);
        window.draw(graphicText);
        window.display();
        sleep(2);
        graphicText.setFillColor(sf::Color::White);
        moveObject(window, map);

    }

    awaitingInteraction(window);
}

void GraphicOptions::addObject(sf::RenderWindow &window, Map *map, Dictionary *dic) {
    window.clear();

    background.draw(window);

    showBoard(window, map);

    string rowInput, columnInput;
    string amount = "1";

    graphicText.setString("Ingrese en que posicion desea agregar el objeto");
    graphicText.setPosition(620, 200);
    window.draw(graphicText);
    graphicText.setString("Fila : ");
    graphicText.setPosition(620, 250);
    window.draw(graphicText);
    graphicText.setString("Columna : ");
    graphicText.setPosition(620, 300);
    window.draw(graphicText);
    window.display();

    rowInput = showCoordinateInput(window,map->getHeight());
    graphicText.setString(rowInput);
    graphicText.setPosition(690, 250);
    window.draw(graphicText);
    window.display();

    columnInput = showCoordinateInput(window,map->getWidth());
    graphicText.setString(columnInput);
    graphicText.setPosition(745, 300);
    window.draw(graphicText);
    window.display();

    sleep(1);
    window.clear();

    background.draw(window);

    graphicText.setString("Ingrese que tipo de objeto desea agregar");
    graphicText.setPosition(500, 50);
    window.draw(graphicText);

    graphicText.setString("[ 1 ]  Seres");
    graphicText.setPosition(500, 90);
    window.draw(graphicText);

    graphicText.setString("[ 2 ]  Elementos");
    graphicText.setPosition(500, 120);
    window.draw(graphicText);

    window.display();

    string inputOption = showCoordinateInput(window,2);
    graphicText.setString(inputOption);
    graphicText.setPosition(500,170);
    window.draw(graphicText);
    window.display();
    sleep(1);
    window.clear();

    background.draw(window);

    graphicText.setString("Ingrese que objeto desea agregar ");
    graphicText.setPosition(700, 120);
    window.draw(graphicText);

    bool objectLoaded;

    if (inputOption == "1"){
        this -> showBeingTextures(window, 50, 50);
        this -> showBeingTexts(window, LISTED_BEING_NAMES, 100, 50);
        window.display();
        inputOption = showCoordinateInput(window,MAX_BEING_NAMES);
        window.display();
        sleep(1);
        objectLoaded = addBeing(map, *dic, stoi(inputOption), stoi(rowInput), stoi(columnInput));
    }
    else if (inputOption == "2") {
        this -> showElementTextures(window, 50, 50);
        this -> showElementTexts(window, LISTED_ELEMENT_NAMES, 100, 50);
        window.display();
        inputOption = showCoordinateInput(window,MAX_ELEMENT_NAMES);
        if (ELEMENT_NAMES[stoi(inputOption)-1] == ELEMENT_NAMES[2] || ELEMENT_NAMES[stoi(inputOption)-1] == ELEMENT_NAMES[3]){
            graphicText.setString("Ingresa cantidad que desea ");
            graphicText.setPosition(700, 170);
            window.draw(graphicText);
            window.display();
            amount = showCoordinateInput(window,99);
        }
        objectLoaded = addElement(map, *dic, stoi(inputOption), stoi(amount), stoi(rowInput), stoi(columnInput));
    }

    else {
        graphicText.setString("Entrada erronea. Vuelva a intentar");
        graphicText.setPosition(500, 150);
        graphicText.setFillColor(sf::Color::Red);
        window.draw(graphicText);

        graphicText.setFillColor(sf::Color::White);
        window.display();
        sleep(1);
        addObject(window, map, dic);
    }

    window.clear();

    background.draw(window);

    if (objectLoaded){
        graphicText.setString("El objeto en la posicion " + rowInput + ", " +columnInput + "\nSe agrego correctamente");
        graphicText.setPosition(750,300);
        window.draw(graphicText);
        showAddMap(window,map,stoi(rowInput)-1,stoi(columnInput)-1);
    }
    else{
        graphicText.setString("Ingreso incorrecto");
        graphicText.setPosition(350,300);
        window.draw(graphicText);
    }
    awaitingInteraction(window);
}


bool GraphicOptions::addBeing(Map *&map, Dictionary &dict, int userInput, int row, int column) {
    bool cargaCorrecta;
    switch(userInput) {
        case optionHUMAN:
            cargaCorrecta = objectAdder.beingAdd<Human>(map,dict,1,49, row, column);
            break;
        case optionVAMPIREHUNTER:
            cargaCorrecta = objectAdder.beingAdd<Hunter>(map,dict,50,99, row, column);
            break;
        case optionVANESA:
            cargaCorrecta = objectAdder.beingAdd<Vanesa>(map,dict,0,0, row, column);
            break;
        case optionZOMBIE:
            cargaCorrecta = objectAdder.beingAdd<Zombie>(map,dict,100,199, row, column);
            break;
        case optionVAMPIRE:
            cargaCorrecta = objectAdder.beingAdd<Vampire>(map,dict,202,299, row, column);
            break;
        case optionNOSFERATU:
            cargaCorrecta = objectAdder.beingAdd<Nosferatu>(map,dict,200,200, row, column);
            break;
        case optionVAMPIRELLA:
            cargaCorrecta = objectAdder.beingAdd<Vampirella>(map,dict,201,201, row, column);
            break;
    }
    return cargaCorrecta;
}

bool GraphicOptions::addElement(Map *&map, Dictionary &dict, int userInput, int amount, int row, int column) {
    bool cargaCorrecta;
    switch(userInput) {
        case optionHOLYWATER:
            cargaCorrecta = objectAdder.elementAdd<HolyWater>(map,dict,300,319,amount,row,column);
            break;
        case optionSTAKE:
            cargaCorrecta = objectAdder.elementAdd<Stake>(map,dict,380,999,amount,row,column);
            break;
        case optionCROSS:
            cargaCorrecta = objectAdder.elementAdd<Cross>(map,dict,320,339,amount,row,column);
            break;
        case optionSHOTGUN:
            cargaCorrecta = objectAdder.elementAdd<Shotgun>(map,dict,340,359,amount,row,column);
            break;
        case optionBULLET:
            cargaCorrecta = objectAdder.elementAdd<Bullet>(map, dict, 360, 379, amount,row,column);
            break;
    }
    return cargaCorrecta;
}

void GraphicOptions::awaitingInteraction(sf::RenderWindow &window) {
    graphicText.setString("Ingrese BACKSPACE para volver al menu.");
    graphicText.setPosition(800, 660);
    window.draw(graphicText);
    window.display();
}

void GraphicOptions::removeObject(sf::RenderWindow &window, Map *map, Dictionary *dic) {
    window.clear();

    background.draw(window);

    showBoard(window, map);
    showMapReferences(window);

    graphicText.setString("Ingrese las coordenadas a eliminar");
    graphicText.setPosition(600,520);
    window.draw(graphicText);


    graphicText.setString("Fila : ");
    graphicText.setPosition(600,570);
    window.draw(graphicText);

    graphicText.setString("Columna : ");
    graphicText.setPosition(600,620);
    window.draw(graphicText);

    window.display();

    std::string row = showCoordinateInput(window, map -> getHeight());
    graphicText.setString(row);
    graphicText.setPosition(680, 570);
    window.draw(graphicText);

    window.display();

    std::string column = showCoordinateInput(window, map -> getWidth());
    graphicText.setString(column);
    graphicText.setPosition(745, 620);
    window.draw(graphicText);

    window.display();
    sleep(1);
    window.clear();

    background.draw(window);

    int rowMap = stoi(row) - 1;
    int columnMap = stoi(column) - 1;

    Object* removingObject;

    if (map -> getMatrix() -> getData(rowMap, columnMap) -> getBeing()) {
        removingObject = map -> getMatrix() -> getData(rowMap, columnMap) -> getBeing();
        graphicText.setString("Ser eliminado");
        graphicText.setPosition(600, 50);
        window.draw(graphicText);

        showObject(window, removingObject);
        dic -> remove(removingObject -> getId());
        map -> getMatrix() -> getData(rowMap, columnMap) -> setBeing(nullptr);

        showRemoveMap(window, map, rowMap, columnMap);

    }

    else if (map->getMatrix()->getData(rowMap, columnMap)->getElement()) {
        removingObject = map -> getMatrix() -> getData(rowMap, columnMap) -> getElement();

        graphicText.setString("Elemento eliminado");
        graphicText.setPosition(600, 50);
        window.draw(graphicText);

        showObject(window, removingObject);
        dic -> remove(removingObject -> getId());
        map -> getMatrix() -> getData(rowMap, columnMap) -> setElement(nullptr);

        showRemoveMap(window, map, rowMap, columnMap);

    }

    else {
        showBoard(window, map);
        graphicText.setString("Posicion vacia");
        graphicText.setPosition(600,500);
        window.draw(graphicText);
        cout <<"Posicion vacia" << endl;
    }
  //  window.display();

    awaitingInteraction(window);

}
string GraphicOptions::validateEntry(sf::RenderWindow &window) {
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


string GraphicOptions::showCoordinateInput(sf::RenderWindow &window, int max) {
    string userInput;

    bool finish = false;

    while(!finish) {

        userInput = validateEntry(window);

        if (0 < stoi(userInput) && stoi(userInput) <= max) {
            finish = true;
        }

        else {
            graphicText.setString("Ingreso incorrecto, reingrese");
            graphicText.setPosition(900, 640);
            window.draw(graphicText);
            window.display();
        }
    }
    return userInput;
}

void GraphicOptions::showBoard(sf::RenderWindow &window, Map *map) {

    graphicFont.loadFromFile("BetaDance.ttf");
    this -> graphicText.setFont(this -> graphicFont);
    this -> graphicText.setCharacterSize(30);
    this -> graphicText.setFillColor(sf::Color::White);

    sf::Sprite terrainSprite;
    sf::Texture terrainsTexture;

    sf::Sprite beingSprite;
    sf::Texture beingTexture;

    sf::Texture elementTexture;
    sf::Sprite elementSprite;

    for (int i = 0; i < map->getHeight() ; ++i) {
        graphicText.setString(to_string(i+1));

        graphicText.setPosition(75 + i * 61, 15);
        window.draw(graphicText);

        graphicText.setPosition(25, 67 + i * 61);
        window.draw(graphicText);

        for (int j = 0; j < map->getWidth() ; ++j) {

            terrainsTexture = map->getMatrix()->getData(i,j) -> getCell() -> getTexture();
            terrainSprite.setTexture(terrainsTexture);

            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);


            if ( map -> getMatrix() -> getData(i,j) -> getBeing()) {
                beingTexture = map -> getMatrix() ->getData(i, j)->getBeing()->getTexture();

                beingSprite.setTexture(beingTexture);

                beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                window.draw(beingSprite);
            }


            if (map->getMatrix() -> getData(i,j) -> getElement() ) {
                elementTexture = map->getMatrix()->getData(i, j)->getElement()->getTexture();

                elementSprite.setTexture(elementTexture);

                elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                window.draw(elementSprite);
            }
        }
    }
}

void GraphicOptions::showObject(sf::RenderWindow &window, Object *object) {
    sf::Texture texture;

    texture = object->getTexture();

    graphicSprite.setTexture(texture);
    graphicSprite.setPosition(600, 100);
    window.draw(graphicSprite);

    graphicText.setString("Nombre: "+ object->getObjectName());
    graphicText.setPosition(650, 100);
    window.draw(graphicText);

    graphicText.setString("ID: " + to_string(object->getId()));
    graphicText.setPosition(650, 135);
    window.draw(graphicText);
}

void GraphicOptions::showRemoveMap(sf::RenderWindow &window, Map *map, int row, int column) {
    graphicFont.loadFromFile("BetaDance.ttf");
    this -> graphicText.setFont(this -> graphicFont);
    this -> graphicText.setCharacterSize(30);
    this -> graphicText.setFillColor(sf::Color::White);

    sf::Sprite terrainSprite;
    sf::Texture terrainsTexture;

    sf::Sprite beingSprite;
    sf::Texture beingTexture;

    sf::Texture elementTexture;
    sf::Sprite elementSprite;

    for (int i = 0; i < map->getHeight() ; ++i) {
        graphicText.setString(to_string(i+1));

        graphicText.setPosition(75 + i * 61, 15);
        window.draw(graphicText);

        graphicText.setPosition(25, 67 + i * 61);
        window.draw(graphicText);

        for (int j = 0; j < map->getWidth() ; ++j) {

            if (i == row && j == column) {
                terrainsTexture = map->getMatrix()->getData(i, j)->getCell()->getRedBorder();
            }

            else {
                terrainsTexture = map->getMatrix()->getData(i, j)->getCell()->getTexture();
            }

            terrainSprite.setTexture(terrainsTexture);

            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);


            if ( map -> getMatrix() -> getData(i,j) -> getBeing()) {
                beingTexture = map -> getMatrix() ->getData(i, j)->getBeing()->getTexture();

                beingSprite.setTexture(beingTexture);

                beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                window.draw(beingSprite);
            }


            if (map->getMatrix() -> getData(i,j) -> getElement() ) {
                elementTexture = map->getMatrix()->getData(i, j)->getElement()->getTexture();

                elementSprite.setTexture(elementTexture);

                elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                window.draw(elementSprite);
            }
        }
    }
}

void GraphicOptions::showAddMap(sf::RenderWindow &window, Map *map, int row, int column) {
    graphicFont.loadFromFile("BetaDance.ttf");
    this -> graphicText.setFont(this -> graphicFont);
    this -> graphicText.setCharacterSize(30);
    this -> graphicText.setFillColor(sf::Color::White);

    sf::Sprite terrainSprite;
    sf::Texture terrainsTexture;

    sf::Sprite beingSprite;
    sf::Texture beingTexture;

    sf::Texture elementTexture;
    sf::Sprite elementSprite;

    for (int i = 0; i < map->getHeight() ; ++i) {
        graphicText.setString(to_string(i+1));

        graphicText.setPosition(75 + i * 61, 15);
        window.draw(graphicText);

        graphicText.setPosition(25, 67 + i * 61);
        window.draw(graphicText);

        for (int j = 0; j < map->getWidth() ; ++j) {

            if (i == row && j == column) {
                terrainsTexture = map->getMatrix()->getData(i, j)->getCell() -> getGreenBorder();
            }

            else {
                terrainsTexture = map->getMatrix()->getData(i, j)->getCell()->getTexture();
            }

            terrainSprite.setTexture(terrainsTexture);

            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);


            if ( map -> getMatrix() -> getData(i,j) -> getBeing()) {
                beingTexture = map -> getMatrix() ->getData(i, j)->getBeing()->getTexture();

                beingSprite.setTexture(beingTexture);

                beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                window.draw(beingSprite);
            }


            if (map->getMatrix() -> getData(i,j) -> getElement() ) {
                elementTexture = map->getMatrix()->getData(i, j)->getElement()->getTexture();

                elementSprite.setTexture(elementTexture);

                elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                window.draw(elementSprite);
            }
        }
    }
}

void GraphicOptions::quadrantSearch(sf::RenderWindow &window, Map *map) {
    window.clear();

    background.draw(window);

    bool foundObject = false;

    showQuadrantReferences(window);
    window.display();

    string quadrantInput,objectInput;
    quadrantInput = showCoordinateInput(window,4);

    sleep(1);
    window.clear();

    background.draw(window);


    graphicText.setString("Ingrese que tipo de objeto desea buscar");
    graphicText.setPosition(500, 50);
    window.draw(graphicText);

    graphicText.setString("[ 1 ]  Seres");
    graphicText.setPosition(500, 90);
    window.draw(graphicText);

    graphicText.setString("[ 2 ]  Elementos");
    graphicText.setPosition(500, 120);
    window.draw(graphicText);

    window.display();

    string inputOption = validateEntry(window);
    window.clear();

    background.draw(window);

    assingQuadrantLimits(QUADRANT_NAMES[stoi(quadrantInput)-1],map->getHeight(),map->getWidth());


    graphicText.setString("Ingrese cual objeto desea buscar");
    graphicText.setPosition(500, 50);
    window.draw(graphicText);

    if (inputOption == "1"){
        this -> showBeingTextures(window, 50, 50);
        this -> showBeingTexts(window, LISTED_BEING_NAMES, 100, 50);
        window.display();
        objectInput = showCoordinateInput(window,MAX_BEING_NAMES);
        window.clear();
        background.draw(window);

        objectInput = BEING_NAMES[stoi(objectInput)-1];
        foundObject = showQuadrant(window, map, objectInput);
    }

    else if (inputOption == "2") {
        this -> showElementTextures(window, 50, 50);
        this -> showElementTexts(window, LISTED_ELEMENT_NAMES, 100, 50);
        window.display();
        objectInput = showCoordinateInput(window,MAX_ELEMENT_NAMES);
        window.clear();
        background.draw(window);

        objectInput = ELEMENT_NAMES[stoi(objectInput)-1];
        foundObject = showQuadrant(window, map, objectInput);
    }

    else {
        window.clear();

        graphicText.setString("Entrada erronea. Vuelva a intentar");
        graphicText.setPosition(500, 150);
        graphicText.setFillColor(sf::Color::Red);
        window.draw(graphicText);
        background.draw(window);
        graphicText.setFillColor(sf::Color::White);
        window.display();

        sleep(2);

        quadrantSearch(window, map);
    }

    graphicText.setString("El objeto " + objectInput + " en el cuadrante " + QUADRANT_NAMES[stoi(quadrantInput)-1]);
    graphicText.setPosition(600,300);
    window.draw(graphicText);

    if (foundObject){
        graphicText.setString("SE HA ENCONTRADO!");
        graphicText.setPosition(600,350);
        window.draw(graphicText);

        awaitingInteraction(window);

    }
    else{
        graphicText.setString("NO SE HA ENCONTRADO!");
        graphicText.setPosition(600,350);
        window.draw(graphicText);

        awaitingInteraction(window);
    }

}

void GraphicOptions::idSearch(sf::RenderWindow &window, Map *map, Dictionary *dic) {
    window.clear();
    background.draw(window);

    string objectName;
    bool foundObject = false;
    graphicText.setString("Ingrese el id que desea buscar:");
    graphicText.setPosition(350,200);
    window.draw(graphicText);
    window.display();
    string idInput = validateEntry(window);
    graphicText.setString(idInput);
    graphicText.setPosition(350,250);
    window.draw(graphicText);
    window.display();

    if (0 <= stoi(idInput) && stoi(idInput) <= 999 ){
        sleep(1);
        foundObject = dic->search(stoi(idInput));
    }

    else {
        graphicText.setString("Ingreso incorrecto, reingrese");
        graphicText.setPosition(350,600);
        window.draw(graphicText);
        window.display();
        sleep(1);
        idSearch(window,map,dic);
    }

    window.clear();

    background.draw(window);


    if (foundObject){
        objectName = dic->find(stoi(idInput))->getObjectName();
        graphicText.setString("El objeto de ID " + idInput + " SE HA ENCONTRADO.\n"+ "Es " + objectName);
        graphicText.setPosition(350,300);
        window.draw(graphicText);
    }
    else {
        graphicText.setString("El objeto de ID " + idInput + " NO EXISTE.\n");
        graphicText.setPosition(350,300);
        window.draw(graphicText);
    }
    awaitingInteraction(window);
}

void GraphicOptions::showQuadrantReferences(sf::RenderWindow &window) {

    graphicText.setString("Ingrese en que cuadrante desea realizar la busqueda");
    graphicText.setPosition(350,200);
    window.draw(graphicText);
    graphicText.setString("[ 1 ]  NO ");
    graphicText.setPosition(350,250);
    window.draw(graphicText);
    graphicText.setString("[ 2 ]  NE ");
    graphicText.setPosition(350,300);
    window.draw(graphicText);
    graphicText.setString("[ 3 ]  SO ");
    graphicText.setPosition(350,350);
    window.draw(graphicText);
    graphicText.setString("[ 4 ]  SE ");
    graphicText.setPosition(350,400);
    window.draw(graphicText);

}

void GraphicOptions::assingQuadrantLimits(string quadrantName, int height, int width) {
    if (quadrantName == "NO"){
        rowLimits[START] = 0;
        rowLimits[END] = height/2;
        columnLimits[START] = 0;
        columnLimits[END] = width/2;
    }
    else if (quadrantName == "NE"){
        rowLimits[START] = 0;
        rowLimits[END] = height/2;
        columnLimits[START] = width/2;
        columnLimits[END] = width;

    }
    else if (quadrantName == "SO"){
        rowLimits[START] = height/2;
        rowLimits[END] = height;
        columnLimits[START] = 0;
        columnLimits[END] =  width/2;
    }
    else if (quadrantName == "SE"){
        rowLimits[START] = height/2;
        rowLimits[END] = height;
        columnLimits[START] = width/2;
        columnLimits[END] = width;
    }
}

bool GraphicOptions::showQuadrant(sf::RenderWindow &window, Map* map, string object) {

    sf::Sprite terrainSprite;
    sf::Texture terrainsTexture;

    sf::Sprite beingSprite;
    sf::Texture beingTexture;

    sf::Texture elementTexture;
    sf::Sprite elementSprite;

    bool objetoEncontrado = false;

    for (int i = rowLimits[0]; i < rowLimits[1] ; ++i) {
//        graphicText.setString(to_string(i+1));
//        graphicText.setPosition(75 + i * 61, 15);
//        window.draw(graphicText);
//        graphicText.setPosition(25, 67 + i * 61);
//        window.draw(graphicText);
        for (int j = columnLimits[0]; j < columnLimits[1] ; ++j) {

            terrainsTexture = map->getMatrix()->getData(i,j) -> getCell() -> getTexture();
            terrainSprite.setTexture(terrainsTexture);

            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);

            if (map -> getMatrix() -> getData(i,j) -> getBeing())
                if ( map -> getMatrix() -> getData(i,j) -> getBeing()->getObjectName() == object) {
                    objetoEncontrado = true;
                    terrainsTexture = map->getMatrix()->getData(i,j)->getCell()->getGreenBorder();
                    terrainSprite.setTexture(terrainsTexture);
                    window.draw(terrainSprite);

                    beingTexture = map -> getMatrix() ->getData(i, j)->getBeing()->getTexture();
                    beingSprite.setTexture(beingTexture);
                    beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                    window.draw(beingSprite);
                }

            else if (map -> getMatrix() -> getData(i,j) -> getElement())
                if (map->getMatrix() -> getData(i,j) -> getElement()->getObjectName() == object ) {
                    objetoEncontrado = true;
                    terrainsTexture = map->getMatrix()->getData(i,j)->getCell()->getGreenBorder();
                    terrainSprite.setTexture(terrainsTexture);
                    window.draw(terrainSprite);

                    elementTexture = map->getMatrix()->getData(i, j)->getElement()->getTexture();
                    elementSprite.setTexture(elementTexture);
                    elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                    window.draw(elementSprite);
            }
        }
    }
    return objetoEncontrado;
}





