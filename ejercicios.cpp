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
// O(1) porque el loop siempre se ejecuta exáctamente 9 veces (constante)
int minasAdyacentes(tablero& t, pos p) {
    int adyacentes = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
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
// O(n) siendo n = |b| porque siempre recorre toda la lista b
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
// O(n) siendo n = |j| porque si no perdió (el peor de los casos) recorre toda la lista sin encontrar una mina
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
// O(n*m) siendo n = #posiciones en el tablero y m= |j| porque en el peor de los casos,
// por cada posición del tablero recorrió todas las jugadas sin encontrar una mina.
bool gano(tablero& t, jugadas& j) {
    for (int x = 0; x < t.size(); x++) {
        for (int y = 0; y < t[x].size(); y++) {
            pos p;
            p.first = x;
            p.second = y;
            bool fueJugado = posEnJugadas(j, p); // O(m)
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
    jugada nuevaJugada = {p, minasAdyacentes(t,p)};
    j.push_back(nuevaJugada);
    if (minasAdyacentes(t, p) > 0 || t[p.first][p.second] == cMINA) {
        return;
    }
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            pos posAdyacente = {p.first + x, p.second + y};
            if (!esCoordenadaValida(t, posAdyacente) || posEnJugadas(j, posAdyacente)) {
                continue;
            }

            if (posEnBanderitas(b, posAdyacente)) {
                cambiarBanderita(t, j ,posAdyacente, b);
            }

            jugarPlus(t, b, posAdyacente, j);
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    for (int i = 0; i < j.size(); i++) {
        if (es121Horizontal(j, j[i])) {
            pos posJugada = j[i].first;
            pos arriba = {posJugada.first, posJugada.second-1};
            pos abajo = {posJugada.first, posJugada.second+1};
            if (puedeJugarse(t, b, j, arriba)) {
                p = arriba;
                return true;
            }
            if (puedeJugarse(t, b, j, abajo)) {
                p = abajo;
                return true;
            }
        }
        if (es121Vertical(j, j[i])) {
            pos posJugada = j[i].first;
            pos izquierda = {posJugada.first-1, posJugada.second};
            pos derecha = {posJugada.first+1, posJugada.second};
            if (puedeJugarse(t, b, j, derecha)) {
                p = derecha;
                return true;
            }
            if (puedeJugarse(t, b, j, izquierda)) {
                p = izquierda;
                return true;
            }
        }
    }
    return false;
}
