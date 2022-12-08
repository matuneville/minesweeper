// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda
/*
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(jugarPlus, descubre1){
    tablero t = {
            {true, false, false},
            {false, false, false},
            {true, false, false}

    };
    pos p = {0,1};
    banderitas  b = {};
    jugadas j = {};
    jugadas jugadaEsperada = {{{0,1},1}};
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j,jugadaEsperada);
}

TEST(jugarPlus, descubre6){
    tablero t = {
            {true, false, false},
            {false, false, false},
            {true, false, false}

    };
    pos p = {1,2};
    banderitas  b = {};
    jugadas j = {};
    jugadas jugadaEsperada = {{{1,2},0},{{0,1},1},{{0,2},0},
                              {{1,1},2},{{2,1},1},{{2,2},0}};
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j,jugadaEsperada);
}

TEST(jugarPlus, descubre5){
    tablero t = {
            {true, false, false},
            {false, false, false},
            {true, false, false}

    };
    pos p = {1,2};
    banderitas  b = {};
    jugadas j = {{{0,1},1}};
    jugadas jugadaEsperada = {{{0,1},1},{{1,2},0},{{0,2},0},
                              {{1,1},2},{{2,1},1},{{2,2},0}};
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j,jugadaEsperada);
}

TEST(jugarPlus, descubre4){
    tablero t = {
            {true, false, false},
            {false, false, false},
            {true, false, false}

    };
    pos p = {1,2};
    banderitas  b = {{1,1}};
    jugadas j = {{{0,1},1}};
    jugadas jugadaEsperada = {{{0,1},1},{{1,2},0},
                              {{0,2},0},{{2,1},1},{{2,2},0}};
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j,jugadaEsperada);
}
TEST(jugarPlus, tocaMina){
    tablero t = {
            {true, false, false},
            {false, false, true},
            {true, false, false}

    };
    pos p = {1,2};
    banderitas  b = {{1,1}};
    jugadas j = {{{0,1},1}};
    jugadas jugadaEsperada = {{{0,1},1},{{1,2},0}};
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j,jugadaEsperada);
}
*/