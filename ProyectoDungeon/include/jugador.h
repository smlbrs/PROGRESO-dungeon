#ifndef JUGADOR_H
#define JUGADOR_H

class jugador {
private:
    int x;
    int y;
    int vidas;
    int puntos;
    char direccion;

public:
    jugador();

    int getX();
    int getY();
    int getVidas();

    void mover(int dx, int dy);
    void perderVida();
    void curar();
    int getPuntos();

    void sumarPuntos(int cantidad);
    void setDireccion(char d);

    char getDireccion();
};

#endif  