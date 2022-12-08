// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda
/*
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(sugerir121TEST, ningunaPosSugerible){
    tablero t4 = {
            { cMINA,  cVACIA,  cVACIA,cMINA},
            { cVACIA, cVACIA, cVACIA, cMINA},
            { cVACIA, cVACIA,  cVACIA, cVACIA },
            { cVACIA, cVACIA, cMINA, cVACIA },
    };
    jugadas juegoValido2 = {
            jugada(pos(2,1),0),jugada(pos(3,3),1),
            jugada(pos(2,0),0),jugada(pos(2,3),1), jugada(pos(1,0),1),
            jugada(pos(2,2),1),jugada(pos(1,1),1), jugada(pos(1,2),2)
    };
    pos p = {};
    banderitas b;
    pos sugerible = {-1,-1};
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (p == sugerible);
    bool x = (!u && o);
    ASSERT_TRUE(x);
}

TEST(sugerir121TEST, 121horizontal){
    tablero t4 = {
            { cMINA,  cVACIA,  cMINA,cVACIA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA, cVACIA,  cVACIA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA },
    };
    jugadas juegoValido2 = {
            jugada(pos(1,1),2), jugada(pos(2,3),0),
            jugada(pos(3,2),1),jugada(pos(1,0),1),jugada(pos(2,1),1),
            jugada(pos(1,2),1)
    };
    pos p = {};
    banderitas b;
    pos sugerible (0,1);
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (u && p == sugerible);
    ASSERT_TRUE(o);
}

TEST(sugerir121TEST, 121verticalLadoDerecho){
    tablero t = {
            { cVACIA,  cVACIA,  cMINA,cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA, cVACIA,  cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA },
    };
    jugadas juegoValido = {
            jugada(pos(1,1),2), jugada(pos(3,3),1),jugada(pos(0,1),1),
            jugada (pos(0,0),0),jugada(pos(1,3),3), jugada(pos(2,1),1)
    };
    pos p = {};
    banderitas b = {};
    pos sugerible = {1,2};
    bool u = sugerirAutomatico121(t,b,juegoValido,p);
    bool o = (u && p == sugerible);
    ASSERT_TRUE(o);
}
TEST(sugerir121TEST, 121verticalLadoIzquierda){
    tablero t = {
            { cMINA,  cVACIA,  cVACIA,cMINA},
            { cVACIA, cVACIA, cVACIA, cMINA},
            { cMINA, cVACIA,  cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA },
    };
    jugadas juegoValido = {
            jugada(pos(0,2),1),jugada(pos(1,1),2),jugada(pos(1,2),2), jugada(pos(3,3),0),jugada(pos(0,1),1),
            jugada(pos(1,3),1), jugada(pos(2,1),1)
    };
    pos p = {};
    banderitas b = {};
    pos sugerible1 = {1,0};
    bool u = sugerirAutomatico121(t,b,juegoValido,p);
    bool o = (u && p == sugerible1 );
    ASSERT_TRUE(o);
}

TEST(sugerir121TEST, 121horizontalAbajo){
    tablero t4 = {
            { cVACIA,  cVACIA,  cVACIA,cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA, cVACIA,  cVACIA, cVACIA },
            { cMINA, cVACIA, cMINA, cVACIA },
    };
    jugadas juegoValido2 = {
            jugada(pos(0,2),1),jugada(pos(1,3),1),jugada(pos(2,1),2),
            jugada(pos(3,3),1),jugada(pos(2,0),1),jugada(pos(2,3),1),
            jugada(pos(2,2),1), jugada(pos(1,1),0)
    };
    pos p = {};
    banderitas b;
    pos sugerible1 (3,1);
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (u && p == sugerible1 );
    ASSERT_TRUE(o);
}

TEST(sugerir121TEST, dosSugeridas){
    tablero t4 = {
            { cMINA,  cVACIA,  cMINA,cVACIA},
            { cVACIA, cVACIA, cVACIA, cVACIA},
            { cVACIA, cVACIA,  cVACIA, cVACIA },
            { cMINA, cVACIA, cMINA, cVACIA },
    };
    jugadas juegoValido2 = {
            jugada(pos(1,3),1),jugada(pos(2,1),2),jugada(pos(3,3),1),
            jugada(pos(2,0),1),jugada(pos(2,3),1), jugada(pos(1,0),1),
            jugada(pos(2,2),1),jugada(pos(1,1),2), jugada(pos(1,2),1)
    };
    pos p = {};
    banderitas b;
    pos sugerible1 (3,1);
    pos sugerible2 (0,1);
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (u && (p == sugerible1 || p == sugerible2));
    ASSERT_TRUE(o);
}

TEST(sugerir121TEST, dosPosibles121){
    tablero t4 = {
            { cMINA,  cVACIA,  cMINA,cVACIA,cVACIA},
            { cVACIA, cVACIA, cVACIA, cVACIA,cVACIA},
            { cVACIA, cVACIA,  cVACIA, cVACIA, cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA , cVACIA, cMINA, cVACIA,cMINA}
    };
    jugadas juegoValido2 = {
            jugada(pos(1,3),1),jugada(pos(3,3),2),
            jugada(pos(2,0),1),jugada(pos(2,3),1), jugada(pos(1,0),1),
            jugada(pos(2,2),0),jugada(pos(1,1),2), jugada(pos(1,2),1),
            jugada(pos(4,3),1)
    };
    pos p = {};
    banderitas b;
    pos sugerible1 (3,4);
    pos sugerible2 (0,1);
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (u && (p == sugerible1 || p == sugerible2));
    ASSERT_TRUE(o);
}
TEST(sugerir121TEST, dosPosibles121_2){
    tablero t4 = {
            { cMINA,  cVACIA,  cMINA,cVACIA,cVACIA},
            { cVACIA, cVACIA, cVACIA, cVACIA,cVACIA}, //aca, pos 1,3
            { cVACIA, cVACIA,  cVACIA, cVACIA, cMINA},
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA , cVACIA, cMINA, cVACIA,cMINA}
    };
    jugadas juegoValido2 = {
            jugada(pos(1,3),2),jugada(pos(3,3),2),
            jugada(pos(2,0),0),jugada(pos(2,3),1), jugada(pos(1,0),1),
            jugada(pos(2,2),0),jugada(pos(1,1),2), jugada(pos(1,2),1),
            jugada(pos(4,3),2),jugada(pos(0,3),1)
    };
    pos p = {};
    banderitas b;
    pos sugerible1 (3,4);
    pos sugerible2 (0,1);
    pos sugerible3 (1,4);
    pos sugerible4 (1,2);
    bool u = sugerirAutomatico121(t4,b,juegoValido2,p);
    bool o = (u && (p == sugerible1 || p == sugerible2 || p == sugerible3 || p == sugerible4));
    ASSERT_TRUE(o);
}*/