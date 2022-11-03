//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

// O(1)
bool esCoordenadaValida(tablero& t, pos p) {
    return p.first >= 0 && p.first < t.size() && p.second >= 0 && p.second < t[0].size();
}

// O(n)
bool posEnJugadas(jugadas& j, pos p) {
    for (int i = 0; i < j.size(); i++) {
        if (j[i].first == p) {
            return true;
        }
    }
    return false;
}

// O(n)
bool posEnBanderitas(banderitas& b, pos p) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == p) {
            return true;
        }
    }
    return false;
}

int cantidadDeAparicionesJugadas(jugadas& j, jugada jugada) {
    int cantidad = 0;
    for (int i = 0; i < j.size(); i++) {
        if (j[i] == jugada) {
            cantidad++;
        }
    }
    return cantidad;
}

bool esPermutacionJugada(jugadas& j1, jugadas& j2) {
    if (j1.size() != j2.size()) {
        return false;
    }

    for (int i = 0; i < j1.size(); i++) {
        if (cantidadDeAparicionesJugadas(j1, j1[i]) != cantidadDeAparicionesJugadas(j2, j1[i])) {
            return false;
        }
    }
    return true;
}

// O(n) (búsqueda lineal)
bool jugadaEnJugadas(jugadas& j, jugada jug) {
    for (int i = 0; i < j.size(); i++) {
        if (j[i] == jug) {
            return true;
        }
    }
    return false;
}

// O(n) (3 veces una función de O(n), 3O(n) = O(n))
bool es121Vertical(jugadas& j, jugada jug) {
    pos p = jug.first;
    return jugadaEnJugadas(j, jug) && jugadaEnJugadas(j, {{p.first, p.second-1},1}) && jugadaEnJugadas(j, {{p.first, p.second+1},1});
}
bool es121Horizontal(jugadas& j, jugada jug) {
    pos p = jug.first;
    return jugadaEnJugadas(j, jug) && jugadaEnJugadas(j, {{p.first-1, p.second},1}) && jugadaEnJugadas(j, {{p.first+1, p.second},1});
}

// O(n) (Una función en tiempo constante y dos en tiempo lineal)
bool puedeJugarse(tablero& t, banderitas& b, jugadas& j, pos p) {
    return esCoordenadaValida(t, p) && !posEnBanderitas(b, p) && !posEnJugadas(j, p);
}