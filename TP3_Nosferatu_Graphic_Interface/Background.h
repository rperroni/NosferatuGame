#ifndef UNTITLED5_BACKGROUND_H
#define UNTITLED5_BACKGROUND_H
#include "SFML/Graphics.hpp"

class Background
{
private:

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

public:
    //CONSTRUCTOR//
    //Inicializa el fondo de comienzo y lo setea
    Background();

    //PRE: Ingresa la ventana en la cual se imprimira la imagen
    //POST: Se muestra la imagen por ventana
    void draw(sf::RenderWindow &window);

    //PRE: Ingresa el nombre de un archivo previamente puesto en la misma carpeta que estan los demas archivos
    //POST: En el caso de existir la imagen, cambia el fondo por el nuevo ingresado.
    void changeBackground(std::string newBackground);

    ~Background() = default;

};
#endif //UNTITLED5_BACKGROUND_H