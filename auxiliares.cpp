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

bool esCoordenadaValida(tablero& t, pos p) {
    return p.first >= 0 && p.first < t.size() && p.second >= 0 && p.second < t[0].size();
}

bool posEnJugadas(jugadas& j, pos p) {
    for (int i = 0; i < j.size(); i++) {
        if (j[i].first == p) {
            return true;
        }
    }
    return false;
}
