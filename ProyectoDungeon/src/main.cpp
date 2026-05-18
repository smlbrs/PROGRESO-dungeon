#include "../include/juego.h"
#include <iostream>

int main() {

    int opcion;
    std::cout << "==== DUNGEON ====\n";
    std::cout << "1. Jugar\n";
    std::cout << "2. Salir\n";
    std::cout << "Selecciona una opcion: ";

    std::cin >> opcion;

    if(opcion == 1) {

        juego partida;
        partida.ejecutar();
    }
    else {

        std::cout << "chau...\n";
    }

    return 0;
}