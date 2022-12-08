// #include "gtest/gtest.h"
#include <iostream>
#include <gtest/gtest.h>
#include "ejercicios.h"
#include "auxiliares.h"
#include <locale.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

int main(int argc, char **argv) {
    //testing::InitGoogleTest(&argc, argv);

    _setmode(::_fileno(stdout), _O_U16TEXT);

    tablero t = {};
    jugadas j = {};
    banderitas b = {};

    jueguitoMinesweeper(t, j, b);

    //return RUN_ALL_TESTS();;
    return 0;
}