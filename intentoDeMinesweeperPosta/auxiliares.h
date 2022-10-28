
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool estaEnTablero (pos p, tablero &t);
bool hayMina (pos p, tablero& t);
void removerPosicion (banderitas &b, int posicion);
int cantPosicionesSinMinas(tablero& t);
void agregarJugadasNuevas(pos p, int minas, jugadas& j);
bool esPosicionJugada(pos p, jugadas& j);
bool tieneBanderita(pos p, banderitas &b);
bool existen1y1Horizontales(jugadas& j, pos posicionCon2, tablero &t);
bool existen1y1Verticales(jugadas& j, pos posicionCon2, tablero &t);
pos sugieroPHorizontal(pos pos2, tablero &t, jugadas &j, banderitas &b, bool &esSugerible);
pos sugieroPVertical(pos pos2, tablero &t, jugadas &j, banderitas &b, bool &esSugerible);