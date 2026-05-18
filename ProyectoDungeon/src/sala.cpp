#include <iostream>
#include "../include/sala.h"

Sala::Sala() {

    std::cout << "Constructor sala\n";

    char temp[10][10] = {

        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','T','.','.','.','E','#'},
        {'#','.','.','T','#','.','.','.','.','#'},
        {'#','.','.','.','#','J','.','.','.','#'},
        {'#','.','.','.','#','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','O','.','#'},
        {'#','.','.','K','.','.','.','.','.','#'},
        {'#','.','.','.','.','.','.','.','Z','#'},
        {'#','V','.','.','.','X','.','.','D','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    for(int i = 0; i < 10; i++) {

        for(int j = 0; j < 10; j++) {

            mapa[i][j] = temp[i][j];
        }
    }

    std::cout << "Sala creada\n";
}

void Sala::dibujar() {

    for(int i = 0; i < 10; i++) {

        for(int j = 0; j < 10; j++) {

            std::cout << mapa[i][j];
        }

        std::cout << std::endl;
    }
}

char Sala::getCelda(int fila, int columna) {
    
    return mapa[fila][columna];
}
void Sala::setCelda(int fila, int columna, char valor) {
        
    mapa[fila][columna] = valor;
}