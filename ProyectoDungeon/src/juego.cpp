#include "../include/juego.h"
#include <iostream>
#include <fstream>

juego::juego() {
}

void juego::ejecutar() {

    inventario.agregarObjeto("Pocion");

    char tecla;

    while(true) {

    for(int i = 0; i < 10; i++) {   

        for(int j = 0; j < 10; j++) {

            if(i == player.getY() && j == player.getX()) {
                std::cout << 'P';
            }
            else {
                std::cout << sala.getCelda(i, j);
            }
        }

        std::cout << std::endl;
    }

    std::cout << "\nVidas: " << player.getVidas() << std::endl;

    std::cout << "Puntos: " << player.getPuntos() << std::endl;

    inventario.mostrar();

        std::cout << "W para mover arriba \n" << std::endl;
                std::cout << "A para mover izquierda \n" << std::endl;
                        std::cout << "S para mover abajo \n" << std::endl;
                                std::cout << "D para mover derecha\n" << std::endl;

        std::cin >> tecla;

        int nuevoX = player.getX();
        int nuevoY = player.getY();

        if(tecla == 'w') nuevoY--;
        if(tecla == 's') nuevoY++;
        if(tecla == 'a') nuevoX--;
        if(tecla == 'd') nuevoX++;

        if(tecla == 'W') nuevoY--;
        if(tecla == 'S') nuevoY++;
        if(tecla == 'A') nuevoX--;
        if(tecla == 'D') nuevoX++;

        if(
        nuevoX >= 0 && nuevoX < 10 &&
        nuevoY >= 0 && nuevoY < 10
) {

    char celda = sala.getCelda(nuevoY, nuevoX);
    if(celda == '#') {
        continue;
    }

    if(celda == 'D') {
        if(inventario.tieneObjeto("Llave")) {
                std::cout << "\nGANASTE\n";

        std::ofstream archivo("record.txt");
        archivo << "Puntaje: " << player.getPuntos();

        archivo.close();

        break;
    }
    else {
            std::cout << "Necesitas una llave\n";
            continue;
        }
    }

    if(celda == 'K') {
        inventario.agregarObjeto("Llave");
         player.sumarPuntos(50);
        sala.setCelda(nuevoY, nuevoX, '.');
    }

    if(celda == 'V') {
        player.curar();
        player.sumarPuntos(20);

        sala.setCelda(nuevoY, nuevoX, '.');

        std::cout<<"\nTe curaste\n";
    }

    if(celda == 'E') {
        
        player.perderVida();

        std::cout<<"\n te atacaron \n";

        if(player.getVidas() <= 0) {
            std::cout<<"perdiste burro";
    break;
    }
}
    if(celda == 'J') {

    player.perderVida();
    player.perderVida();
    player.perderVida();

    std::cout << "\nEl jefe te golpeo\n";

    if(player.getVidas() <= 0) {

        std::cout << "\nMORISTE JAJA\n";

        break;
    }
    player.sumarPuntos(100);
    sala.setCelda(nuevoY, nuevoX, '.');
}
    
    player.mover(
        nuevoX - player.getX(),
        nuevoY - player.getY()
    );
} {
            if(sala.getCelda(nuevoY, nuevoX) == 'K') {
            inventario.agregarObjeto("Llave");
            sala.setCelda(nuevoY, nuevoX, '.');
        }  
            player.mover(
                nuevoX - player.getX(),
                nuevoY - player.getY()
            );
        }
    }
}

