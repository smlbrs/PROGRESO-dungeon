#include <SFML/Graphics.hpp>

char mapa[10][10] = {

    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

int main() {

    sf::RenderWindow window(
        sf::VideoMode(500, 500),
        "Dungeon Game"
    );

    sf::RectangleShape bloque(
        sf::Vector2f(50.f, 50.f)
    );

    sf::RectangleShape jugador(
        sf::Vector2f(40.f, 40.f)
    );

    jugador.setFillColor(
        sf::Color::Red  
    );

    int jugadorX = 1;
    int jugadorY = 1;

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::KeyPressed) {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if(mapa[jugadorY - 1][jugadorX]) {

            jugadorY--;
        }
    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if(mapa[jugadorY + 1][jugadorX]) {

        jugadorY++;
    }
}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if(mapa[jugadorY][jugadorX - 1]) {

        jugadorX--;
    }
}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if(mapa[jugadorY][jugadorX + 1]) {

        jugadorX++;
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

                if(mapa[i][j] == '#') {

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

        jugador.setPosition(
            jugadorX * 50.f + 5.f,
            jugadorY * 50.f + 5.f
        );

        window.draw(jugador);

        window.display();
    }

    return 0;
}