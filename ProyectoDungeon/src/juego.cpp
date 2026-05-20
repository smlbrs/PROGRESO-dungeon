#include "../include/juego.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

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

    fuente1.loadFromFile(
        "assets/fonts/times.ttf");
    textoVidas.setFont(fuente1);

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

    estado = MENU;

    textoMenu.setFont(fuente1);

    textoMenu.setCharacterSize(40);

    textoMenu.setFillColor(
        sf::Color::Yellow);

    textoMenu.setString(
        "Dungeon Game\nENTER para jugar");

    textoMenu.setPosition(
        50.f,
        200.f);

    textoGameOver.setFont(fuente1);

    textoGameOver.setCharacterSize(40);

    textoGameOver.setFillColor(
        sf::Color::Red);

    textoGameOver.setString(
        "GAME OVER\nESC para salir");

    textoGameOver.setPosition(
        150.f,
        200.f);

    textoVictoria.setFont(fuente1);

    textoVictoria.setCharacterSize(40);

    textoVictoria.setFillColor(
        sf::Color::Green);

    textoVictoria.setString(
        "RESCATASTE A LA PRINCESA\nESC para salir");

    textoVictoria.setPosition(
        150.f,
        200.f);

    musica.openFromFile(
        "assets/music/music.ogg");

    musica.setLoop(true);
    musica.setVolume(50.f);
    musica.play();

    srand(time(NULL));
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

                if (estado == MENU)
                {

                    if (

                        event.key.code == sf::Keyboard::Enter)
                    {
                        estado = JUGANDO;
                    }
                    continue;
                }

                if (estado == GAMEOVER || estado == VICTORIA)
                {

                    continue;
                }

                int nuevoX = player.getX();
                int nuevoY = player.getY();

                if (event.key.code == sf::Keyboard::W)
                {

                    nuevoY--;

                    jugadorSprite.setTextureRect(
                        sf::IntRect(
                            128,
                            0,
                            64,
                            64));
                }

                if (event.key.code == sf::Keyboard::S)
                {

                    nuevoY++;
                    jugadorSprite.setTextureRect(
                        sf::IntRect(
                            192,
                            0,
                            64,
                            64));
                }

                if (event.key.code == sf::Keyboard::A)
                {

                    nuevoX--;

                    jugadorSprite.setTextureRect(
                        sf::IntRect(
                            64,
                            0,
                            64,
                            64));
                }
                if (event.key.code == sf::Keyboard::D)
                {

                    nuevoX++;
                    jugadorSprite.setTextureRect(
                        sf::IntRect(
                            0,
                            0,
                            64,
                            64));
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

                            else if (numeroSala == 2)
                            {

                                numeroSala = 3;

                                sala.cargarSala3();

                                player.mover(
                                    1 - player.getX(),
                                    1 - player.getY());

                                continue;
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

                            estado = GAMEOVER;
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

                            estado = GAMEOVER;
                        }

                        player.sumarPuntos(100);

                        sala.setCelda(
                            nuevoY,
                            nuevoX,
                            'R');
                    }

                    if (celda == 'R')
                    {
                        std::ofstream archivo(
                            "record.txt");

                        archivo
                            << "Puntaje: "
                            << player.getPuntos();

                        archivo.close();

                        estado = VICTORIA;
                    }

                    player.mover(
                        nuevoX - player.getX(),
                        nuevoY - player.getY());
                }
            }

            if (relojEnemigos.getElapsedTime().asSeconds() >= 1.f)
            {

                moverEnemigos();

                relojEnemigos.restart();
            }
        }
        window.clear();

        if (estado == MENU)
        {

            window.draw(textoMenu);
            window.display();
            continue;
        }

        if (estado == GAMEOVER)
        {

            window.draw(textoGameOver);
            window.display();
            continue;
        }

        if (estado == VICTORIA)
        {

            window.draw(textoVictoria);
            window.display();
            continue;
        }

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

                else if (celda == 'R')
                {

                    bloque.setFillColor(
                        sf::Color::Yellow);
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

void juego::moverEnemigos()
{

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            char celda = sala.getCelda(i, j);

            if (celda == 'E' || celda == 'O' || celda == 'X' || celda == 'Z')
            {

                int direccion = rand() % 4;

                int nuevoX = j;
                int nuevoY = i;

                if (direccion == 0)
                {

                    nuevoY--;
                }

                else if (direccion == 1)
                {

                    nuevoY++;
                }

                else if (direccion == 2)
                {

                    nuevoX--;
                }

                else if (direccion == 3)
                {

                    nuevoX++;
                }

                if (nuevoX >= 0 && nuevoX < 10 && nuevoY >= 0 && nuevoY < 10)
                {

                    if (sala.getCelda(nuevoY, nuevoX) == '.')
                    {

                        sala.setCelda(nuevoY, nuevoX, celda);
                        sala.setCelda(i, j, '.');
                    }
                }
            }
        }
    }
}