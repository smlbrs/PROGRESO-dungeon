# Carpeta src

Esta carpeta contiene todas las implementaciones del proyecto.


# ¿Para qué se implementó?

Se implementó para separar la lógica completa del videojuego de los archivos declarados en include.

# ¿Por qué se consideró necesario?

Separar codigo que permite mantener un código más organizado.
También facilita:

 mantenimiento y reutilización de código

# ¿Cómo se llevó a cabo su implementación?

Cada clase fue implementada en archivos .cpp.

Por ejemplo:

- juego.cpp contiene la lógica principal del videojuego
- jugador.cpp controla movimiento y estadísticas
- sala.cpp administra mapas y enemigos
- inventario.cpp controla objetos obtenidos

# Desarrollos innovadores implementados

## Sistema de múltiples salas

Permite progresión dentro del dungeon y separación por niveles de dificultad.

## Sistema de combate

El jugador puede atacar en la dirección en la que está mirando usando SPACE.

## IA básica del jefe

El jefe detecta la posición del jugador y se mueve hacia él automáticamente.

## Barra de vida gráfica

El jefe utiliza una barra gráfica dinámica implementada con `sf::RectangleShape`.

## Sistema de estados

El juego utiliza estados como:

- MENU
- GAMEOVER
- VICTORIA
