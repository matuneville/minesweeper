#include <iostream>
#include "ejercicios.h"
#include "auxiliares.h"

void jueguitoMinesweeper (tablero &t, jugadas &j, banderitas &b){

    int tamano, cantMinas;
    cout << "Ingrese tamanio del tablero" << endl;
    cin >> tamano;
    cout << "Ingrese cantidad de minas" << endl;
    cin >> cantMinas;

    t = crearTableroRandom(tamano, cantMinas);

    while (not perdio(t, j)){
        imprimirJuego(t, j, b);
        cout << "\n";
        cout << "Ingrese 1 para descubrir celda \no 2 para plantar banderita"<< endl;
        int elijo, fila, columna;
        cin >> elijo;
        cout << "Ingrese fila"<<endl;
        cin >> fila;
        cout << "Ingrese columna"<<endl;
        cin >> columna;


        pos celda = make_pair(fila, columna);
        if (elijo == 1){
            jugarPlus(t, b, celda, j);
        }

        if (elijo == 2){
            cambiarBanderita(t, j, celda, b);
        }

        if (j.size() == cantPosicionesSinMinas(t)) {
            imprimirJuego(t, j, b);
            cout << "Ganaste pa B)";
            break;
        }

        if (perdio(t, j)) {
            imprimirJuego(t, j, b);
            cout << "\nJaja perdiste gil";
        }
    }

}