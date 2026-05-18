#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Dungeon Game"
    );

    sf::RectangleShape jugador(
        sf::Vector2f(50.f, 50.f)
    );

    jugador.setPosition(100.f, 100.f);

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {

                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            jugador.move(0.f, -0.2f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            jugador.move(0.f, 0.2f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            jugador.move(-0.2f, 0.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            jugador.move(0.2f, 0.f);
        }

        window.clear();

        window.draw(jugador);

        window.display();
    }

    return 0;
}