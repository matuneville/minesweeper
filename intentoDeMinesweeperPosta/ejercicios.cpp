//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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
    bool tieneMina = false;
    if(cantidadMinas > 0)
        tieneMina = true;

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
    if (!tieneBanderita(p, b) && estaEnTablero(p,t) && !esPosicionJugada(p,j)) {
        int minasAdy = minasAdyacentes(t, p);
        if (minasAdy >= 1)
            agregarJugadasNuevas(p, minasAdy, j);
        else if (hayMina(p, t))
            agregarJugadasNuevas(p, 0, j);
        else {
            agregarJugadasNuevas(p, minasAdyacentes(t, p), j);
            for (int i = -1; i <= 1; ++i) {
                for (int k = -1; k <= 1; ++k) {
                    pos posAdy = make_pair(p.first + i, p.second + k);
                    if (estaEnTablero(posAdy, t)) {
                        jugarPlus(t, b, posAdy, j);
                    }
                }
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    int largoJugadas = j.size();
    bool existe2 = false, hayPosSugerible = false;
    int indice2 = 0;
    for(int i = 0; i < largoJugadas && !existe2; i++) {
        if(j[i].second == 2) {
            existe2 = true;
            indice2 = i;
        }
    }

    if(existe2) {
        if(existen1y1Horizontales(j, j[indice2].first,t)){
            hayPosSugerible = true;
            p = sugieroPHorizontal(j[indice2].first, t, j, b, hayPosSugerible);
        } else if(existen1y1Verticales(j, j[indice2].first,t)) {
            hayPosSugerible = true;
            p = sugieroPVertical(j[indice2].first, t, j, b, hayPosSugerible);
        }
    }
    return hayPosSugerible;
}

//********************************** EXTRAS ***********************************************************
void imprimirJuego(tablero &t, jugadas &j, banderitas &b){
    cout << "    ";
    for (int i = 0; i < t.size(); ++i) {
        cout << i << "  ";
    }
    cout<< "\n    ";
    for (int i = 0; i < t.size(); ++i) {
        cout << "|  ";
    }

    cout << "\n";
    for (int i = 0; i < t.size(); ++i) {
        cout << i << "- ";
        for (int k = 0; k < t[i].size(); ++k) {
            pos p = make_pair(i,k);
            if (tieneBanderita(p, b))
                cout << "<!>";
            else if (not esPosicionJugada(p, j))
                cout << "|_|";
            else if (hayMina(p, t))
                cout << " X ";
            else
                cout <<" "<< minasAdyacentes(t, p)<< " ";
        }
        cout<<"\n";
    }
}

tablero crearTableroRandom (int largoAncho, int cantidadMinas){
    tablero t (largoAncho, vector<bool>(largoAncho, false));
    vector<pos> minasFilaColumna{};
    int i = 1;
    while (i <= cantidadMinas) {
        srand(time(0));
        pos minaCoord = make_pair((rand() % largoAncho),(rand() % largoAncho));
        if (not tieneBanderita(minaCoord, minasFilaColumna)) {
            minasFilaColumna.push_back(minaCoord);
            i++;
        }
    }

    for (int i = 0; i < minasFilaColumna.size(); ++i) {
        t[minasFilaColumna[i].first][minasFilaColumna[i].second] = true;
    }

    return t;
}