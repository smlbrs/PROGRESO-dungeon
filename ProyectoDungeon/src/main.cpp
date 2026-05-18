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

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {

                window.close();
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

        window.display();
    }

    return 0;
}