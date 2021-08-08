#include "QuadrantSearch.h"


void QuadrantSearch::loadMatrix(Map* graph) {
    this -> height = graph -> getHeight();
    this -> width = graph -> getWidth();
    this -> matrix = graph -> getMatrix() -> getMatrix();
}

bool QuadrantSearch::searchForObject(std::string wantedObject) {
    bool finishSearch = false;
    int counterRows = rowLimits[START];
    while(!finishSearch && counterRows < rowLimits[END]){
        int counterColumns = columnLimits[START];

        while (!finishSearch && counterColumns < columnLimits[END]){

            if (matrix[counterRows][counterColumns] -> getBeing() || matrix[counterRows][counterColumns] -> getElement())
                finishSearch = isFound(wantedObject, counterRows, counterColumns);

            counterColumns++;
        }

        counterRows++;
    }

    return finishSearch;
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

    if (name == HUMAN_CAPITALIZED) {
        if (this -> matrix[row][column] -> getBeing() -> getObjectName() == HUMAN_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == VANESA_CAPITALIZED ||
            this -> matrix[row][column] -> getBeing() -> getObjectName() == HUNTER_CAPITALIZED)
            encontrado = true;
    }

    else if (name == VAMPIREUPPER) {
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

