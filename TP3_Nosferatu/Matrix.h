#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>

template <typename Type>

class Matrix {

private:

    int height, width;
    Type** matrix;

public:

    // PRE: Ingresa las medidas del mapa
    // POST: Crea la matriz con dichas medidas
    Matrix(int height, int width);

    // PRE: --
    // POST: Muestra la matriz por consola
    void showMatrix();

    // PRE: --
    // POST: Devuelve el ancho de la matriz
    int getWidth();

    // PRE: --
    // POST: Devuelve el alto de la matriz
    int getHeight();

    // PRE: Ingresa la posicion
    // POST: Devuelve el dato de dicha posicion que esta en la matriz
    Type getData(int row, int column);

    // PRE: --
    // POST: Devuelve el doble puntero de la matriz
    Type** getMatrix();

    //DESTRUCTOR
    ~Matrix();

};

template <typename Type>
Matrix<Type>::Matrix(int height, int width){

    this -> height = height;
    this -> width = width;

    matrix = new Type*[height];

    for(int row = 0; row < height; row++){
        matrix[row] = new Type[width];
    }
}

template <typename Type>
Matrix<Type>::~Matrix(){

    for(int row = 0; row < this -> height; row++){
        delete [] matrix[row];
    }

    delete [] matrix;
}

template <typename Type>
void Matrix<Type>::showMatrix() {

    for (int row = 0; row < this -> height; row++) {
        for (int column = 0; column < this -> width; column++) {
            std::cout << matrix[row][column] -> getCell() -> getType() << " ";
        }
        std::cout << std::endl;
    }
    for (int row = 0; row < this -> height; row++) {
        for (int column = 0; column < this -> width; column++) {
            if(matrix[row][column] -> getBeing() != nullptr)
                std::cout << matrix[row][column]->getBeing()->getObjectName() << " ";
            else std::cout <<"("<< row <<","<< column<<")";

        }
        std::cout << std::endl;
    }
    std::cout << "---*-------------*---------" << std::endl;
    for (int row = 0; row < this -> height; row++) {
        for (int column = 0; column < this -> width; column++) {
            if(matrix[row][column] -> getElement() != nullptr)
                std::cout << matrix[row][column]->getElement()->getObjectName() << " ";
            else std::cout <<"("<< row <<","<< column<<")";
        }
        std::cout << std::endl;
    }

}

template <typename Type>
int Matrix<Type>::getWidth(){
    return this -> width;
}

template <typename Type>
int Matrix<Type>::getHeight(){
    return this -> height;
}

template <typename Type>
Type Matrix<Type>::getData(int row, int column){
    return matrix[row][column];
}

template <typename Type>
Type** Matrix<Type>::getMatrix() {
    return this -> matrix;
}

#endif //GRAFOS_MATRIX_H
