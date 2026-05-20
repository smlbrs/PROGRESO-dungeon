#ifndef SALA_H
#define SALA_H

class Sala {
private:
    char mapa[10][10];

public:
    Sala();

    void dibujar();

    char getCelda(int fila, int columna);
    void setCelda(int fila, int columna, char valor);

    void cargarSala2();
    void cargarSala3();
};

#endif