#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "jugador.h"
#include "sala.h"
#include "inventario.h"

class juego
{

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

    sf::Texture texturaOgro;

    sf::Sprite OgroSprite;

    sf::Texture texturaKey;

    sf::Sprite keySprite;

    sf::Texture texturaDoor;

    sf::Sprite doorSprite;

    sf::Texture texturaBoss;

    sf::Sprite bossSprite;

    sf::Texture texturaPotion;

    sf::Sprite potionSprite;

    sf::Texture texturaTreasure;

    sf::Sprite treasureSprite;

    sf::Texture texturaWall;

    sf::Sprite wallSprite;

    sf::Texture texturaZombie;

    sf::Sprite zombieSprite;

    sf::Texture texturaSkeleton;

    sf::Sprite skeletonSprite;

    sf::Texture texturaMonster;

    sf::Sprite monsterSprite;

    sf::Font fuente1;

    sf::Texture texturaPrincess;

    sf::Sprite princessSprite;

    enum EstadoJuego
    {

        MENU,

        JUGANDO,

        GAMEOVER,

        VICTORIA
    };

    EstadoJuego estado;

    sf::Text textoMenu;

    sf::Text textoGameOver;

    sf::Text textoVictoria;

    sf::Music musica;

    sf::Clock relojEnemigos;

    int vidaJefe;

    sf::Text textoBoss;

    sf::RectangleShape barraBoss;

    sf::RectangleShape fondoBoss;

    sf::Clock attackClock;

public:
    juego();

    void ejecutar();

    void moverEnemigos();

    void moverJefe();

    void atacar();
};

#endif