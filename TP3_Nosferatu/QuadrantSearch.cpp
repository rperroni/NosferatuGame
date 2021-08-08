#include "QuadrantSearch.h"


void QuadrantSearch::loadMatrix(Map* graph) {
    this -> height = graph -> getHeight();
    this -> width = graph -> getWidth();
    this -> matrix = graph -> getMatrix() -> getMatrix();
}



void QuadrantSearch::chooseQuadrant(Map *gameMap) {
}

void QuadrantSearch::searchForObject(std::string wantedObject) {

    int coordY = 20;
    int counter = 6;
    Object* object;
    printer.mainWindow();
    bool founded = false;
    std::cout << gotoxy.pos(coordY - 1 + counter,42);

    for(int i = rowLimits[START]; i < rowLimits[END]; i++){

        for(int j = columnLimits[START]; j < columnLimits[END]; j++){

            std::cout << matrix[i][j] -> getCell() -> getType() << "\033[1m" << "\033[38;5;232m";

            if (matrix[i][j] -> getBeing() || matrix[i][j] -> getElement()){

                if (matrix[i][j] -> getBeing())
                    object = matrix[i][j]->getBeing();

                else
                    object = matrix[i][j]->getElement();

                if(isFound(wantedObject, i, j)) {
                    cout << "\033[6m" << object->getCharName() << " ";
                    founded = true;
                }
                else
                    cout << "\033[1m" << object -> getCharName() << " ";
            }
            else
                cout << "  ";

            cout << "\033[0m" << "\033[40m  \033[0m";
            cout << "\033[0m";
        }
        coordY++;
        cout << "" << endl;
        std::cout << gotoxy.pos(coordY + counter,42);
        counter++;

    }

    if (founded) {
        std::cout << gotoxy.pos(41,42) << "\033[40m" << TXT_BOLD << TXT_WHITE_7 << "Se encontro: " << TXT_BOLD << TXT_GREEN_118 << wantedObject << END_COLOR;
    }

    else
        std::cout << gotoxy.pos(41,42) << "\033[40m" << TXT_BOLD << TXT_WHITE_7 << "No se encontro: " << TXT_BOLD << TXT_RED_196 << wantedObject << END_COLOR;


}


void QuadrantSearch::assignLimits(std::string quadrantName) {
    if (quadrantName == "NO"){
        rowLimits[START] = 0;
        rowLimits[END] = this -> height/2;
        columnLimits[START] = 0;
        columnLimits[END] = this -> width/2;
    }
    else if (quadrantName == "NE"){
        rowLimits[START] = 0;
        rowLimits[END] = this -> height/2;
        columnLimits[START] = this -> width/2;
        columnLimits[END] = this -> width;

    }
    else if (quadrantName == "SO"){
        rowLimits[START] = this -> height/2;
        rowLimits[END] = this -> height;
        columnLimits[START] = 0;
        columnLimits[END] = this -> width/2;
    }
    else if (quadrantName == "SE"){
        rowLimits[START] = this -> height/2;
        rowLimits[END] = this -> height;
        columnLimits[START] = this -> width/2;
        columnLimits[END] = this -> width;
    }
    cout << rowLimits[START] << rowLimits [END] << endl;
    cout << columnLimits[START] << columnLimits [END] << endl;
}

bool QuadrantSearch::isFound(std::string name, int row, int column) {
    bool encontrado = false;
    if (name == HUMAN_CAPITALIZED && matrix[row][column] -> getBeing()) {
        if (this -> matrix[row][column] -> getBeing() -> getObjectName() == HUMAN_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == VANESA_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == HUNTER_CAPITALIZED)
            encontrado = true;
    }

    else if (name == VAMPIREUPPER && matrix[row][column] -> getBeing()) {
        if (this -> matrix[row][column] -> getBeing() -> getObjectName() == VAMPIRE_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == VAMPIRELLA_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == NOSFERATU_CAPITALIZED)
            encontrado = true;
    }

    else {
        if (this -> matrix[row][column] -> getBeing()) {
            if (this -> matrix[row][column] -> getBeing() -> getObjectName() == name)
                encontrado = true;
        }

        else if (this -> matrix[row][column] -> getElement()) {
            if (this -> matrix[row][column] -> getElement() -> getObjectName() == name)
                encontrado = true;
        }
    }

    return encontrado;
}

QuadrantSearch::~QuadrantSearch() {

}

