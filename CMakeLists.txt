cmake_minimum_required(VERSION 3.10)

project(DungeonGame)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)

include_directories(
    ProyectoDungeon/include
    SFML/include
)

link_directories(SFML/lib)

add_executable(dungeon
    ProyectoDungeon/src/main.cpp
    ProyectoDungeon/src/juego.cpp
    ProyectoDungeon/src/jugador.cpp
    ProyectoDungeon/src/sala.cpp
    ProyectoDungeon/src/inventario.cpp
)

target_link_libraries(dungeon
    sfml-main
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)