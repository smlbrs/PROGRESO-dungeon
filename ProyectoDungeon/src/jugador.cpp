#include <iostream>
#include "jugador.h"

jugador::jugador() {

    std::cout << "Constructor jugador\n";

    x = 1;
    y = 1;
    vidas = 3;
    puntos = 0;
    direccion = 's';
}

int jugador::getX() {
    return x;
}

int jugador::getY() {
    return y;
}

int jugador::getVidas() {
    return vidas;
}

int jugador::getPuntos() {

    return puntos;
}

void jugador::mover(int dx, int dy) {

    x += dx;
    y += dy;
}

void jugador::perderVida() {

    vidas--;
}

void jugador::curar() {
    if(vidas < 3) {

        vidas++;
    }
}

void jugador::sumarPuntos(int cantidad) {

    puntos += cantidad;
}

void jugador::setDireccion(char d) {
    direccion = d;
}

char jugador::getDireccion() {
    return direccion;
}
