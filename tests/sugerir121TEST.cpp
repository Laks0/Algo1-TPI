// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// .....
// ...x.
// .121.
// .x...
// .....
TEST(Sugerir121, horizontalPosible) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[4][1] = cMINA;
    t[1][4] = cMINA;
    jugadas j = {{{1, 2}, 1}, {{2, 2}, 2}, {{3,2},1}};

    banderitas b;

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    pos posCorrecta = {2, 1};
    bool correcto = (p == posCorrecta) && hay;
    ASSERT_TRUE(correcto);
}

// .....
// ..bx.
// .121.
// .x...
// .....
TEST(Sugerir121, horizontalPosibleConBanderita) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[4][1] = cMINA;
    t[1][4] = cMINA;
    jugadas j = {{{1, 2}, 1}, {{2, 2}, 2}, {{3,2},1}};

    banderitas b = {{2,1}};

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    pos posCorrecta = {2, 3};
    bool correcto = (p == posCorrecta) && hay;
    ASSERT_TRUE(correcto);
}

// .....
// ..bx.
// .121.
// .x1..
// .....
TEST(Sugerir121, horizontalImposible) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[4][1] = cMINA;
    t[1][4] = cMINA;
    jugadas j = {{{1, 2}, 1}, {{2, 2}, 2}, {{3,2},1}, {{2,3}, 1}};

    banderitas b = {{2,1}};

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    ASSERT_FALSE(hay);
}

// .....
// .x1..
// ..2..
// ..1x.
// .....
TEST(Sugerir121, verticalPosible) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[1][1] = cMINA;
    t[3][3] = cMINA;
    jugadas j = {{{2,1}, 1}, {{2,2},2}, {{2,3},1}};

    banderitas b;

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    pos posCorrecta = {3, 2};
    bool correcto = (p == posCorrecta) && hay;
    ASSERT_TRUE(correcto);
}

// .....
// .x1..
// ..2b.
// ..1x.
// .....
TEST(Sugerir121, verticalPosibleConBanderita) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[1][1] = cMINA;
    t[3][3] = cMINA;
    jugadas j = {{{2,1}, 1}, {{2,2},2}, {{2,3},1}};

    banderitas b = {{3,2}};

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    pos posCorrecta = {1, 2};
    bool correcto = (p == posCorrecta) && hay;
    ASSERT_TRUE(correcto);
}

// .....
// 1x...
// 2b...
// 1x...
// .....
TEST(Sugerir121, verticalImposible) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    t[1][1] = cMINA;
    t[1][3] = cMINA;
    jugadas j = {{{0,1}, 1}, {{0,2},2}, {{0,3},1}};

    banderitas b = {{1,2}};

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    ASSERT_FALSE(hay);
}

// .....
// .....
// .....
// .....
// .....
TEST(Sugerir121, sin121) {
    tablero t = vector<vector<bool>>(5, vector<bool>(5, false));
    jugadas j = {};

    banderitas b = {};

    pos p;
    bool hay = sugerirAutomatico121(t, b, j, p);
    ASSERT_FALSE(hay);
}