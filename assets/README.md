# Carpeta assets

Esta carpeta contiene todos los recursos multimedia utilizados en el videojuego.

# ¿Para qué se implementó?

Se implementó para almacenar:

- sprites
- música
- imágenes
- fuentes
- Sonidos de efectos

# ¿Por qué se consideró necesario?

Separar los recursos multimedia del código mejora la organizacion del codigo, y permite cambiar cosas
sin necesidad de modificar el juego

# ¿Cómo se llevó a cabo su implementación?

Los recursos fueron almacenados en formatos compatibles con SFML:

- .png
- .ogg
- .ttf

Estos recursos son cargados usando:

- sf::Texture
- sf::Music
- sf::Font

# Innovaciones implementadas

## Sprite Sheet del jugador

El personaje utiliza múltiples direcciones visuales dentro de una misma imagen.

## Música integrada

Se implementó música de fondo utilizando sf::Music.

## Interfaz visual

Se añadieron elementos gráficos como:

- HUD
- barra de vida
- sprites de enemigos
- sprites del jefe
