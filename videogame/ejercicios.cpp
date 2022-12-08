//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//
#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
int minasAdyacentes(tablero& t, pos p) {
    int contadorMinas = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            pos celdaAdyacente = make_pair(p.first + i, p.second + j);
            if (estaEnTablero(celdaAdyacente, t) && (i != 0 || j != 0) &&
            hayMina(celdaAdyacente, t))
                contadorMinas++;
        }
    }
    return contadorMinas;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    int banderitasLargo = b.size();
    for (int i = 0; i < b.size() && b.size() == banderitasLargo; ++i) {
        if (b[i] == p)
            removerPosicion(b, i);
    }
    if (banderitasLargo == b.size())
        b.push_back(p);
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    int cantidadMinas = 0;
    for (int i = 0; i < j.size(); ++i) {
        if(hayMina((j[i].first), t))
            cantidadMinas++;
    }
    bool tieneMina = (cantidadMinas == 1);
    return tieneMina;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    int cantJugadasConMinas = 0;
    for (int i = 0; i < j.size(); ++i) {
        if(hayMina((j[i].first), t)) {
            cantJugadasConMinas++;
        }
    }
    bool gano = false;
    if(cantJugadasConMinas == 0 && j.size() == cantPosicionesSinMinas(t)) {
        gano = true;
    }
    return gano;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    if (!tieneBanderita(p, b) && estaEnTablero(p,t) && !esPosicionJugada(p,j) && !perdio(t,j)) {
        int minasAdy = minasAdyacentes(t, p);
        if (minasAdy >= 1)
            agregarJugadasNuevas(p, minasAdy, j);
        else {
            agregarJugadasNuevas(p, minasAdyacentes(t, p), j);
            for(int i = -1; i <= 1; i++){
                for(int k = -1; k <= 1; k++){
                    jugarPlus(t,b, make_pair(p.first+i,p.second+k),j);
                }
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    int largoJugadas = j.size();
    bool hayPosSugerible = false;
    p = {-1,-1};

    for(int i = 0; i < largoJugadas && !hayPosSugerible; i++) {
        if(j[i].second == 2) {
            if(existen1y1Horizontales(j, j[i].first,t)){
                hayPosSugerible = true;
                p = sugieroPHorizontal(j[i].first, t, j, b);
            }
            else if(existen1y1Verticales(j, j[i].first,t)) {
                hayPosSugerible = true;
                p = sugieroPVertical(j[i].first, t, j, b);
            }
        }
    }
    return hayPosSugerible;
}

// Parte jugable

void imprimirJuego(tablero &t, jugadas &j, banderitas &b){
    _setmode(::_fileno(stdout), _O_U16TEXT);
    // ACA IMPRIMO EL TECHO DEL TABLERO
    wcout<<"  ";
    for (int i = 0; i < t.size(); ++i) {
        wcout<<"  "<< i<< " ";
    }
    for (int i = 0; i < t.size(); ++i) {
        if (i == 0){
            wcout<< L"\n  ┌───";
        }
        else if (i == t.size()-1){
            wcout<< L"┬───┐\n";
        }
        else
            wcout<< L"┬───";
    }

    // ACA IMPRIMO EL JUEGO
    for (int i = 0; i < t.size(); ++i) {
        for (int k = 0; k < t[i].size(); ++k) {
            if (k == 0) wcout<< i<< " ";
            pos p = make_pair(i,k);
            if (tieneBanderita(p, b))
                wcout << L"│ ▶ ";
            else if (not esPosicionJugada(p, j))
                wcout << L"│   ";
            else if (hayMina(p, t))
                wcout << L"│ X ";
            else if (minasAdyacentes(t, p) == 0)
                wcout <<L"│ ✓ ";
            else
                wcout <<L"│ "<< minasAdyacentes(t, p)<< " ";
        }
        wcout<< L"│ \n";
        // AHORA IMPRIMO LA SEPARACIÓN
        if (i < t.size()-1) for (int l = 0; l < t.size(); ++l) {
            if (l == 0){
                wcout<< L"  ├───";
            }
            else if (l == t.size()-1){
                wcout<< L"┼───┤\n";
            }
            else
                wcout<< L"┼───";
        }
    }

    // ACA IMPRIMO EL PISO DEL TABLERO
    for (int i = 0; i < t.size(); ++i) {
        if (i == 0){
            wcout<< L"  └───";
        }
        else if (i == t.size()-1){
            wcout<< L"┴───┘\n";
        }
        else
            wcout<< L"┴───";
    }
}

tablero crearTableroRandom (int largoAncho, int cantidadMinas){
    tablero t (largoAncho, vector<bool>(largoAncho, false));
    vector<pos> minasFilaColumna = generateRandomInts(cantidadMinas, largoAncho);

    for (int i = 0; i < minasFilaColumna.size(); ++i) {
        t[minasFilaColumna[i].first][minasFilaColumna[i].second] = true;
    }

    return t;
}

vector<pair<int,int>> generateRandomInts(int quant, int sizeT){
    srand((unsigned) time(NULL));
    vector<pair<int,int>> output(quant);

    for (int i = 0; i < quant; ++i) {
        int coordA = rand() % sizeT;
        int coordB = rand() % sizeT;
        output[i] = make_pair(coordA, coordB);
    }

    return output;
}

/* CARACTERES DEL TABLERO
        " ┌───┬───┬───┬───┬───┐\n"
        " │ * │ * │ 2 │ 1 │ 1 │\n"
        " ├───┼───┼───┼───┼───┤\n"
        " │ 3 │ 3 │ 3 │ * │ 1 │\n"
        " ├───┼───┼───┼───┼───┤\n"
        " │ 1 │ * │ 2 │ 1 │ 1 │\n"
        " ├───┼───┼───┼───┼───┤\n"
        " │ 2 │ 3 │ 2 │ 1 │ 0 │\n"
        " ├───┼───┼───┼───┼───┤\n"
        " │ * │ 2 │   │ 1 │ 0 │\n"
        " └───┴───┴───┴───┴───┘"
        ;
*/