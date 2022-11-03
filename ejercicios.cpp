//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
// O(1)
int minasAdyacentes(tablero& t, pos p) {
    int adyacentes = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            pos p2;
            p2.first = p.first + i;
            p2.second = p.second + j;

            if (!esCoordenadaValida(t, p2)) {
                continue;
            }
            adyacentes += t[p2.first][p2.second] == cMINA ? 1 : 0;
        }
    }
    return adyacentes;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
// O(n)
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == p) {
            pos holder = b[b.size()-1];
            b[b.size()-1] = b[i];
            b[i] = holder;

            b.pop_back();
            return;
        }
    }

    // Si p no está en b
    b.push_back(p);
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
// O(n)
bool perdio(tablero& t, jugadas& j) {
    for (int i = 0; i < j.size(); i++) {
        pos p = j[i].first;

        if (t[p.first][p.second] == cMINA) {
            return true;
        }
    }
    return false;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
// O(n²)
bool gano(tablero& t, jugadas& j) {
    for (int x = 0; x < t.size(); x++) {
        for (int y = 0; y < t[x].size(); y++) {
            pos p;
            p.first = x;
            p.second = y;
            bool fueJugado = posEnJugadas(j, p);
            bool esMina = t[x][y] == cMINA;

            if ((esMina && fueJugado) || (!esMina && !fueJugado)) {
                return false;
            }
        }
    }
    return true;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
