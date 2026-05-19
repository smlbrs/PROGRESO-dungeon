#include <SFML/Graphics.hpp>

#include "../include/jugador.h"
#include "../include/sala.h"

int main()
{

    Sala sala;
    jugador player;

    sf::Texture texturaJugador;
    if(!texturaJugador.loadFromFile(
    "assets/player.png"
    )) {

    return -1;
    }

    sf::Sprite jugadorSprite;
    jugadorSprite.setTexture(
        texturaJugador
    );

    jugadorSprite.setScale(
        1.f,
        1.f
    );

    sf::RenderWindow window(
        sf::VideoMode(500, 500),
        "Dungeon Game");

    sf::RectangleShape bloque(
        sf::Vector2f(50.f, 50.f));
        
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

                if (event.key.code == sf::Keyboard::W)
                {

                    if (
                        sala.getCelda(
                            player.getY() - 1,
                            player.getX()) != '#')
                    {

                        player.mover(0, -1);
                    }
                }

                if (event.key.code == sf::Keyboard::S)
                {

                    if (
                        sala.getCelda(
                            player.getY() + 1,
                            player.getX()) != '#')
                    {

                        player.mover(0, 1);
                    }
                }

                if (event.key.code == sf::Keyboard::A)
                {

                    if (
                        sala.getCelda(
                            player.getY(),
                            player.getX() - 1) != '#')
                    {

                        player.mover(-1, 0);
                    }
                }

                if (event.key.code == sf::Keyboard::D)
                {

                    if (
                        sala.getCelda(
                            player.getY(),
                            player.getX() + 1) != '#')
                    {

                        player.mover(1, 0);
                    }
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

                char celda = sala.getCelda(i, j);

                if (celda == '#')
                {

                    bloque.setFillColor(
                        sf::Color::Blue);
                }

                else if (celda == 'K')
                {

                    bloque.setFillColor(
                        sf::Color::Yellow);
                }

                else if (celda == 'H')
                {

                    bloque.setFillColor(
                        sf::Color::Green);
                }

                else if (celda == 'D')
                {

                    bloque.setFillColor(
                        sf::Color(139, 69, 19));
                }

                else if (celda == 'E')
                {

                    bloque.setFillColor(
                        sf::Color::Magenta);
                } else {

                    bloque.setFillColor(
                        sf::Color(50, 50, 50));
                }

                window.draw(bloque);
            }
        }

        jugadorSprite.setPosition(
            player.getX() * 50.f - 7.f,
            player.getY() * 50.f - 7.f 
        );

        window.draw(jugadorSprite);

        window.display();
    }

    return 0;
}