#include "../include/juego.h"
#include <fstream>

juego::juego()
    : window(
          sf::VideoMode(500, 500),
          "Dungeon Game"),
      bloque(sf::Vector2f(50.f, 50.f))
{

    numeroSala = 1;

    texturaJugador.loadFromFile(
        "assets/player.png");

    jugadorSprite.setTexture(
        texturaJugador);

    jugadorSprite.setScale(
        1.f,
        1.f);

    texturaOgro.loadFromFile(
        "assets/enemy.png");

    OgroSprite.setTexture(
        texturaOgro);

    OgroSprite.setScale(
        1.f,
        1.f);

    texturaBoss.loadFromFile(
        "assets/boss.png");

    bossSprite.setTexture(
        texturaBoss);

    bossSprite.setScale(
        1.f,
        1.f);

    texturaKey.loadFromFile(
        "assets/key.png");

    keySprite.setTexture(
        texturaKey);

    keySprite.setScale(
        1.f,
        1.f);

    texturaDoor.loadFromFile(
        "assets/door.png");

    doorSprite.setTexture(
        texturaDoor);

    doorSprite.setScale(
        1.f,
        1.f);

    texturaPotion.loadFromFile(
        "assets/potion.png");

    potionSprite.setTexture(
        texturaPotion);

    potionSprite.setScale(
        1.f,
        1.f);

    texturaTreasure.loadFromFile(
        "assets/treasure.png");

    treasureSprite.setTexture(
        texturaTreasure);

    treasureSprite.setScale(
        1.f,
        1.f);

    texturaWall.loadFromFile(
        "assets/wall.png");

    wallSprite.setTexture(
        texturaWall);

    wallSprite.setScale(
        1.f,
        1.f);

    texturaZombie.loadFromFile(
        "assets/zombie.png");

    zombieSprite.setTexture(
        texturaZombie);

    zombieSprite.setScale(
        1.f,
        1.f);

    texturaSkeleton.loadFromFile(
        "assets/skeleton.png");

    skeletonSprite.setTexture(
        texturaSkeleton);

    skeletonSprite.setScale(
        1.f,
        1.f);

    texturaMonster.loadFromFile(
        "assets/monster.png");

    monsterSprite.setTexture(
        texturaMonster);

    monsterSprite.setScale(
        1.f,
        1.f);

    fuente.loadFromFile(
        "assets/fonts/arial.ttf");

    textoVidas.setFont(fuente);

    textoVidas.setCharacterSize(24);

    textoVidas.setFillColor(
        sf::Color::White);

    textoVidas.setPosition(
        10.f,
        10.f);

    textoPuntos.setFont(fuente);

    textoPuntos.setCharacterSize(24);

    textoPuntos.setFillColor(
        sf::Color::White);

    textoPuntos.setPosition(
        10.f,
        40.f);
}
void juego::ejecutar()
{

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {

                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {

                if (event.key.code == sf::Keyboard::Escape)
                {

                    window.close();
                }

                int nuevoX = player.getX();
                int nuevoY = player.getY();

                if (event.key.code == sf::Keyboard::W)
                {

                    nuevoY--;
                }

                if (event.key.code == sf::Keyboard::S)
                {

                    nuevoY++;
                }

                if (event.key.code == sf::Keyboard::A)
                {

                    nuevoX--;
                }

                if (event.key.code == sf::Keyboard::D)
                {

                    nuevoX++;
                }

                if (
                    nuevoX >= 0 &&
                    nuevoX < 10 &&
                    nuevoY >= 0 &&
                    nuevoY < 10)
                {

                    char celda =
                        sala.getCelda(
                            nuevoY,
                            nuevoX);

                    if (celda == '#')
                    {

                        continue;
                    }

                    if (celda == 'D')
                    {

                        if (
                            inventario.tieneObjeto(
                                "Llave"))
                        {

                            if (numeroSala == 1)
                            {

                                numeroSala = 2;

                                sala.cargarSala2();

                                player.mover(
                                    1 - player.getX(),
                                    1 - player.getY());

                                continue;
                            }

                            else
                            {

                                std::ofstream archivo(
                                    "record.txt");

                                archivo
                                    << "Puntaje: "
                                    << player.getPuntos();

                                archivo.close();

                                window.close();
                            }
                        }

                        else
                        {

                            continue;
                        }
                    }

                    if (celda == 'K')
                    {

                        inventario.agregarObjeto(
                            "Llave");

                        player.sumarPuntos(50);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            '.');
                    }

                    if (celda == 'V')
                    {

                        player.curar();

                        player.sumarPuntos(20);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            '.');
                    }

                    if (celda == 'T')
                    {

                        player.sumarPuntos(30);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            '.');
                    }

                    if (
                        celda == 'E' ||
                        celda == 'O' ||
                        celda == 'X' ||
                        celda == 'Z')
                    {

                        player.perderVida();

                        if (
                            player.getVidas() <= 0)
                        {

                            window.close();
                        }

                        player.sumarPuntos(40);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            '.');
                    }

                    if (celda == 'J')
                    {

                        player.perderVida();
                        player.perderVida();
                        player.perderVida();

                        if (
                            player.getVidas() <= 0)
                        {

                            window.close();
                        }

                        player.sumarPuntos(100);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            '.');
                    }

                    player.mover(
                        nuevoX - player.getX(),
                        nuevoY - player.getY());
                }
            }
        }

        window.clear();

        for (int i = 0; i < 10; i++)
        {

            for (int j = 0; j < 10; j++)
            {

                bloque.setPosition(
                    j * 50.f,
                    i * 50.f);

                char celda =
                    sala.getCelda(i, j);

                if (celda == '#')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    wallSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(wallSprite);

                    continue;
                }

                else if (celda == 'K')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    keySprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(keySprite);

                    continue;
                }

                else if (celda == 'V')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    potionSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(potionSprite);

                    continue;
                }

                else if (celda == 'T')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    treasureSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(treasureSprite);

                    continue;
                }

                else if (celda == 'D')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    doorSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(doorSprite);

                    continue;
                }

                else if (celda == 'E')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    skeletonSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(skeletonSprite);

                    continue;
                }

                else if (celda == 'O')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    OgroSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(OgroSprite);

                    continue;
                }

                else if (celda == 'X')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    monsterSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(monsterSprite);

                    continue;
                }

                else if (celda == 'Z')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    zombieSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(zombieSprite);

                    continue;
                }

                else if (celda == 'J')
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));

                    window.draw(bloque);

                    bossSprite.setPosition(
                        j * 50.f,
                        i * 50.f);

                    window.draw(bossSprite);

                    continue;
                }

                else
                {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));
                }

                window.draw(bloque);
            }
        }

        jugadorSprite.setPosition(
            player.getX() * 50.f - 7.f,
            player.getY() * 50.f - 7.f);

        window.draw(jugadorSprite);

        textoVidas.setString(
            "Vidas: " + std::to_string(player.getVidas()));
        textoPuntos.setString(
            "Puntos: " + std::to_string(player.getPuntos()));

        window.draw(textoVidas);
        window.draw(textoPuntos);

        window.display();
    }
}