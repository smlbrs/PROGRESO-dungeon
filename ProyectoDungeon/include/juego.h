#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>

#include "jugador.h"
#include "sala.h"
#include "inventario.h"

class juego {

private:

    Sala sala;

    jugador player;

    Inventario inventario;

    int numeroSala;

    sf::RenderWindow window;

    sf::Texture texturaJugador;

    sf::Sprite jugadorSprite;

    sf::RectangleShape bloque;

    sf::Font fuente;

    sf::Text textoPuntos;

    sf::Text textoVidas;
public:

    juego();

    void ejecutar();
};

#endif