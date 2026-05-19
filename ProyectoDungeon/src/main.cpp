#include <SFML/Graphics.hpp>

#include "../include/jugador.h"
#include "../include/sala.h"

int main() {

    Sala sala;
    jugador player;

    sf::RenderWindow window(
        sf::VideoMode(500, 500),
        "Dungeon Game"
    );

    sf::RectangleShape bloque(
        sf::Vector2f(50.f, 50.f)
    );

    sf::RectangleShape jugadorShape(
        sf::Vector2f(40.f, 40.f)
    );

    jugadorShape.setFillColor(
        sf::Color::Red
    );

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {

                window.close();
            }

            if(event.type == sf::Event::KeyPressed) {

                if(event.key.code == sf::Keyboard::Escape) {

                    window.close();
                }

                if(event.key.code == sf::Keyboard::W) {

                    if(
                        sala.getCelda(
                            player.getY() - 1,
                            player.getX()
                        ) != '#'
                    ) {

                        player.mover(0, -1);
                    }
                }

                if(event.key.code == sf::Keyboard::S) {

                    if(
                        sala.getCelda(
                            player.getY() + 1,
                            player.getX()
                        ) != '#'
                    ) {

                        player.mover(0, 1);
                    }
                }

                if(event.key.code == sf::Keyboard::A) {

                    if(
                        sala.getCelda(
                            player.getY(),
                            player.getX() - 1
                        ) != '#'
                    ) {

                        player.mover(-1, 0);
                    }
                }

                if(event.key.code == sf::Keyboard::D) {

                    if(
                        sala.getCelda(
                            player.getY(),
                            player.getX() + 1
                        ) != '#'
                    ) {

                        player.mover(1, 0);
                    }
                }
            }
        }

        window.clear();

        for(int i = 0; i < 10; i++) {

            for(int j = 0; j < 10; j++) {

                bloque.setPosition(
                    j * 50.f,
                    i * 50.f
                );

                if(sala.getCelda(i, j) == '#') {

                    bloque.setFillColor(
                        sf::Color::Blue
                    );
                }
                else {

                    bloque.setFillColor(
                        sf::Color::Black
                    );
                }

                window.draw(bloque);
            }
        }

        jugadorShape.setPosition(
            player.getX() * 50.f + 5.f,
            player.getY() * 50.f + 5.f
        );

        window.draw(jugadorShape);

        window.display();
    }

    return 0;
}