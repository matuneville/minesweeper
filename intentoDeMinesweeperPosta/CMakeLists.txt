cmake_minimum_required(VERSION 3.8)
project(intentoDeMinesweeperPosta)

set(SOURCE_FILES main.cpp
        comenzarJuego.cpp
        auxiliares.cpp
        ejercicios.cpp)

add_executable(tpi ${SOURCE_FILES}
        )


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
