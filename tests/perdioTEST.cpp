// Tests para la función perdio.
// Ver el archovo README.md para ayuda
/*
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST (perdioTest, juegoPerdido) {

    tablero t = {
            {false, false, false, true,  false},
            {false, false, false, true,  true},
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, false, true,  false}
    };
    jugadas j = {{{0,0},0},{{1,3},2}};

    bool juegoPerdido = perdio(t,j);
    ASSERT_TRUE(juegoPerdido);

}

TEST (perdioTest, juegoNoPerdido) {

    tablero t = {
            {false, false, false, true,  false},
            {false, false, false, true,  true},
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, false, true,  false}
    };
    jugadas j = {{{0,0},0},{{4,0},0}};

    bool juegoPerdido = perdio(t,j);
    ASSERT_FALSE(juegoPerdido);

}*/