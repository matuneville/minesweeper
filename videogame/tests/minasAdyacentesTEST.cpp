// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda
/*
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;



TEST(minasAdyacentesTest, NingunaMinaAdy){

    tablero t = {
            {false, false, false, true, false},
            {false, false, false, true, true},
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, false, true, false}
    };
    int minasAdy1 = minasAdyacentes(t, {0,0});
    ASSERT_EQ(minasAdy1, 0);

    int minasAdy2 = minasAdyacentes(t, {2,1});
    ASSERT_EQ(minasAdy2, 0);
}

TEST(minasAdyacentesTest, UnaODosMinaAdy){

    tablero t = {
            {false, false, false, true, false},
            {false, false, false, true, true},
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, false, true, false}
    };
    int minasAdy1 = minasAdyacentes(t, {3,4});
    ASSERT_EQ(minasAdy1, 1);

    int minasAdy2 = minasAdyacentes(t, {4,4});
    ASSERT_EQ(minasAdy2, 2);

    int minasAdy3 = minasAdyacentes(t, {3,3});
    ASSERT_EQ(minasAdy3, 2);
}

TEST(minasAdyacentesTest, TresMinaAdy){

    tablero t = {
            {false, false, false, true, false},
            {false, false, false, true, true},
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, false, true, false}
    };
    int minasAdy1 = minasAdyacentes(t, {0,4});
    ASSERT_EQ(minasAdy1, 3);

    int minasAdy2 = minasAdyacentes(t, {2,4});
    ASSERT_EQ(minasAdy2, 3);
}
*/