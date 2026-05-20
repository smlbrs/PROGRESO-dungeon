#include "inventario.h"
#include <iostream>

Inventario::Inventario() {

    cantidad = 0;
}

void Inventario::agregarObjeto(std::string objeto) {

    if(cantidad < 5) {

        objetos[cantidad] = objeto;
        cantidad++;
    }
}

void Inventario::mostrar() {

    std::cout << "\nInventario:\n";

    for(int i = 0; i < cantidad; i++) {

        std::cout << "- " << objetos[i] << std::endl;
    }
}
    bool Inventario::tieneObjeto(std::string objeto) {

    for(int i = 0; i < cantidad; i++) {

        if(objetos[i] == objeto) {

            return true;
        }
    }

    return false;
}
