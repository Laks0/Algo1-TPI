
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool esCoordenadaValida(tablero& t, pos p);
bool posEnJugadas(jugadas& j, pos p);
bool posEnBanderitas(banderitas& b, pos p);
bool esPermutacionJugada(jugadas& j1, jugadas& j2);
bool es121Vertical(jugadas& j, jugada jug);
bool es121Horizontal(jugadas& j, jugada jug);
bool puedeJugarse(tablero& t, banderitas& b, jugadas& j, pos p);