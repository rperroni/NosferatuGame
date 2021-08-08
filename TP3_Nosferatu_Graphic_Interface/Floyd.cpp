#include <unistd.h>
#include "Floyd.h"
#include "CostMatrices.h"

Floyd::Floyd(Map* map){

    this -> graph = map -> getMatrix() -> getMatrix();

    this -> height = map -> getMatrix() -> getHeight();
    this -> width = map -> getMatrix() -> getWidth();

    this -> vertexAmount = this -> height * this -> width;
    this -> vertices = new Vertex*[vertexAmount];

    createCostMatrixArray(map);

    this -> pathMatrices = nullptr;

    initVertices();
    createMatrixArray();
}

void Floyd::createCostMatrixArray(Map * map) {
    this -> costs = new CostMatrices(map);

    this -> costMatrices = costs -> getCostMatrices();

}

int ** Floyd::createPathMatrix(){

    int ** pathMatrix = new int*[vertexAmount];
    for(int i = 0; i < vertexAmount; i++){
        pathMatrix[i] = new int[vertexAmount];
    }

    for(int i = 0; i < vertexAmount; i++){
        for(int j = 0; j < vertexAmount; j++) {
            pathMatrix[i][j] = j;
        }
    }

    return pathMatrix;
}


void Floyd::createMatrixArray() {
    this -> pathMatrices = new int ** [MAX_COSTS];
    int ** actualPathMatrix;

    for (int i = 0; i < MAX_COSTS; i++) {
        actualPathMatrix = this -> createPathMatrix();
        this -> pathMatrices[i] = actualPathMatrix;
        this -> calculateMatrices(i);
    }
}

void Floyd::calculateMatrices(int typeCost) {

    int ** costMatrix = this -> costMatrices[typeCost];
    int ** pathMatrix = this -> pathMatrices[typeCost];

    int cost;

    for (int intermediateVertex = 0; intermediateVertex < vertexAmount; intermediateVertex++) {

        for (int origin = 0; origin < vertexAmount; origin++) {

            for (int destination = 0; destination < vertexAmount; destination++) {

                cost = costMatrix[origin][intermediateVertex] + costMatrix[intermediateVertex][destination];

                if (cost < costMatrix[origin][destination]) {
                    costMatrix[origin][destination] = cost;
                    pathMatrix[origin][destination] = pathMatrix[origin][intermediateVertex];
                }
            }
        }
    }
}


void Floyd::showPath(int origin, int firstOrigin, sf::RenderWindow &window) {
    window.clear();

    sf::Texture background;
    background.loadFromFile("bloodBackGround2.png");

    sf::Sprite backgroundSprite;

    backgroundSprite.setTexture(background);

    window.draw(backgroundSprite);
//    window.display();

    sf::Sprite terrainSprite;

    sf::Sprite beingSprite;

    sf::Sprite elementSprite;

    sf::Texture terrainTexture;
    sf::Texture beingTexture;
    sf::Texture elementTexture;

//    Printer printer;
//    printer.showMap(this -> graph, window);


    for (int i = 0; i < this -> height; ++i) {
        for (int j = 0; j < this -> width; ++j) {

            terrainTexture = graph[i][j] -> getCell() -> getTexture();
            terrainSprite.setTexture(terrainTexture);
            terrainSprite.setPosition(50 + j * 61, 50 + i * 61);
            window.draw(terrainSprite);

            if (i == vertices[origin] -> getX() && j == vertices[origin] -> getY()) {
                vertices[firstOrigin] -> getBeing() -> showObjectCharacter();
                beingTexture = vertices[firstOrigin] -> getBeing() -> getTexture();
                beingSprite.setTexture(beingTexture);
                beingSprite.setPosition(50 + j * 61, 50 + i * 61);
                window.draw(beingSprite);
            }
            else if (graph[i][j] -> getElement()) {
                graph[i][j]->getElement()->showObjectCharacter();
                elementTexture = graph[i][j]->getElement()->getTexture();
                elementSprite.setTexture(elementTexture);
                elementSprite.setPosition(90 + j * 61, 90 + i * 61);
                window.draw(elementSprite);
            }
            else
                cout << "*" << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;

    window.display();
}


void Floyd::minimumPath(int originX, int originY, int destinationX, int destinationY, sf::RenderWindow &window) {
    int index, originIndex, destinationIndex;

    this -> setIndexes();

    originIndex = graph[originY][originX] -> getIndex();
    destinationIndex = graph[destinationY][destinationX] -> getIndex();

    int auxOrigin = originIndex;

    int typeCost = this -> graph[originY][originX] -> getBeing() -> getCostType();
    int x = 0;
    int y = 0;

    do {

        this -> showPath(originIndex, auxOrigin, window);

        std::cout << vertices[originIndex] -> getY() << " " << vertices[originIndex] -> getX() << std::endl;

        x = vertices[originIndex] -> getY();
        y = vertices[originIndex] -> getX();
        //-------------------------------------------------------------
        // Esto tiene que ser un metodo
        if (graph[y][x] -> getElement()) {
            std::cout << "Has encontrado el item:" << std::endl;
            // Guardo el nombre porque si es un elemento repetido; lo borro y despues no puedo printear su nombre.
            std::string itemName = graph[y][x]->getElement()->getObjectName();
            if( graph[originY][originX] -> getBeing() -> grabElement(graph[y][x] -> getElement()) )
            {
                std::cout << "El ser: " << graph[originY][originX]->getBeing()->getObjectName() << ", agarro el item: " << itemName << std::endl;
                //Hay que eliminar el objeto del tablero despues de agarrarlo
//                delete graph[y][x] -> getElement();
                graph[y][x] -> setElement(nullptr);
            }

            else {
                std::cout << "El ser: " << graph[originY][originX] -> getBeing() -> getObjectName() << ", no puede agarrar el item: " << graph[y][x] -> getElement() -> getObjectName() << std::endl;
            }
        }
        //--------------------------------------------------------------------

        usleep(400000);
        index = this -> pathMatrices[typeCost][originIndex][destinationIndex];
        originIndex = index;

//        if (graph[vertices[originIndex] -> getX()][vertices[originIndex] -> getY()] -> getElement())

    } while (index != destinationIndex);

    this -> showPath(originIndex, auxOrigin, window);

    x = vertices[originIndex] -> getY();
    y = vertices[originIndex] -> getX();

    //-----------------------------------------------------------
    // esto tiene que ser un metodo
    if (graph[y][x] -> getElement()) {
        std::cout << "Has encontrado el item:" << graph[y][x] -> getElement() -> getObjectName() << std::endl;
        std::string itemName = graph[y][x]->getElement()->getObjectName();
        if ( graph[originY][originX] -> getBeing() -> grabElement(graph[y][x] -> getElement()) )
        {
            std::cout << "El ser: " << graph[originY][originX]->getBeing()->getObjectName() << ", agarro el item: " << itemName << std::endl;
//            delete graph[y][x] -> getElement();
            graph[y][x] -> setElement(nullptr);
        }

        else {
            std::cout << "El ser: " << graph[originY][originX] -> getBeing() -> getObjectName() << ", no puede agarrar el item: " << graph[y][x] -> getElement() -> getObjectName() << std::endl;
        }
    }
    //------------------------------------------------------------

//    moveBeing(originIndex, destinationIndex);

    moveBeing(auxOrigin, destinationIndex);
}

void Floyd::moveBeing(int origin, int destination) {
    vertices[destination] -> setBeing(vertices[origin] -> getBeing());
    vertices[origin] -> setBeing(nullptr);
}

void Floyd::setIndexes() {
    int countIndex = 0;

    for(int i = 0; i < this -> height; i++) {
        for(int j = 0; j < this -> width; j++) {
            vertices[countIndex] = graph[i][j];
            graph[i][j] -> setIndex(countIndex++);
            graph[i][j] -> setPosition(i, j);
        }
    }
}

void Floyd::deletePathMatrices() {
    for(int i = 0; i < MAX_COSTS; i++){
        for(int j = 0; j < vertexAmount; j++){
            delete [] pathMatrices[i][j];
        }
        delete [] pathMatrices[i];
    }
    delete [] pathMatrices;
}

void Floyd::initVertices() {
    for(int i = 0; i < vertexAmount; i++)
        vertices[i] = nullptr;
}

void Floyd::showPathMatrix(int typeCost) {
    for (int j = 0; j < vertexAmount; ++j) {
        for (int k = 0; k < vertexAmount; ++k) {
            cout << (char)(this -> pathMatrices[typeCost][j][k] + 65) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Floyd::showCostMatrix(int typeCost) {

    for(int i = 0; i < vertexAmount; i++){
        for (int j = 0; j < vertexAmount; j++) {
            if (costMatrices[typeCost][i][j] == INFINITO)
                std::cout << "∞" << " ";

            else
                std::cout << costMatrices[typeCost][i][j] << " ";

        }
        std::cout << endl;
    }

}

Floyd::~Floyd() {

    deletePathMatrices();
    delete [] vertices;
    delete [] costMatrices;
    delete costs;

}
