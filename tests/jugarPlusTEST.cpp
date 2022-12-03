// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ....
// ....
// ....
// ....
TEST(JugarPlus, tableroVacio) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    pos p = {1,1};

    banderitas b;
    jugadas j;

    jugarPlus(t, b, p, j);
    jugadas expectedJ;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            expectedJ.push_back({{x, y}, 0});
        }
    }

    ASSERT_TRUE(esPermutacionJugada(j, expectedJ));
}

// ....
// .x..
// ....
// ....
TEST(JugarPlus, jugadaEsMina) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    t[1][1] = cMINA;
    pos p = {1,1};

    banderitas b;
    jugadas j;

    jugarPlus(t, b, p, j);
    jugadas expectedJ = {{p, 0}};

    ASSERT_TRUE(esPermutacionJugada(j, expectedJ));
}

// ....
// ..j.
// ....
// ....
TEST(JugarPlus, yaHayUnaJugada) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    pos p = {1,1};

    banderitas b;
    jugadas j = {{{2, 1}, 0}};

    jugarPlus(t, b, p, j);
    jugadas expectedJ;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            expectedJ.push_back({{x, y}, 0});
        }
    }

    ASSERT_TRUE(esPermutacionJugada(j, expectedJ));
}

// De la corrección
tablero tablero_unaSolaMina = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cMINA,  cVACIA, cVACIA}, // mina en (4, 2)
};

TEST(jugarPlusTEST, banderitasEnElCamino) {
    pos p = pos(0, 0);
    jugadas j = {};
    banderitas b4 =  { pos (1,3), pos (2,1), pos (3,3)};
    jugarPlus(tablero_unaSolaMina, b4, p, j);
    ASSERT_EQ(j.size(), tablero_unaSolaMina.size() * tablero_unaSolaMina.size() - 4);
}