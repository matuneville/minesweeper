#include <iostream>
#include "ejercicios.h"
#include "auxiliares.h"

void jueguitoMinesweeper (tablero &t, jugadas &j, banderitas &b){

    int tamano, cantMinas;
    wcout << "Type the size of the quare board from 1 to 10:" << endl;
    cin >> tamano;
    wcout << "Type the amount of mines:" << endl;
    cin >> cantMinas;

    t = crearTableroRandom(tamano, cantMinas);

    while (not perdio(t, j)){
        imprimirJuego(t, j, b);
        wcout << "\n";
        wcout << "Type 1 for uncover a new cell or 2 \nto place a flag, and then the coordinates:"<< endl;
        int elijo, fila, columna;
        cin >> elijo>> fila>> columna;


        pos celda = make_pair(fila, columna);
        if (elijo == 1){
            jugarPlus(t, b, celda, j);
        }

        if (elijo == 2){
            cambiarBanderita(t, j, celda, b);
        }

        if (j.size() == cantPosicionesSinMinas(t)) {
            imprimirJuego(t, j, b);
            wcout << "\nYou won!";
            break;
        }

        if (perdio(t, j)) {
            imprimirJuego(t, j, b);
            wcout << "\nYou lost!";
        }
    }

}