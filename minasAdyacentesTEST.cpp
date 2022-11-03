// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

// ....
// ....
// .o..
// ....
TEST(minasAdyacentes, sinMinas) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    pos p = {1, 2};
    int res = minasAdyacentes(t, p);

    ASSERT_EQ(res, 0);
}

// ....
// ....
// .3x.
// x.x.
TEST(minasAdyacentes, tresMinas) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    t[2][2] = cMINA;
    t[2][3] = cMINA;
    t[0][3] = cMINA;
    pos p = {1, 2};
    int res = minasAdyacentes(t, p);

    ASSERT_EQ(res, 3);
}

// 2x..
// x...
// ....
// ....
TEST(minasAdyacentes, esquina) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    t[1][0] = cMINA;
    t[0][1] = cMINA;
    pos p = {0, 0};
    int res = minasAdyacentes(t, p);

    ASSERT_EQ(res, 2);
}


// ....
// xxx.
// x8x.
// xxx.
TEST(minasAdyacentes, ochoMinas) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    t[0][1] = cMINA;
    t[0][2] = cMINA;
    t[0][3] = cMINA;
    t[1][1] = cMINA;
    t[2][1] = cMINA;
    t[2][2] = cMINA;
    t[2][3] = cMINA;
    t[1][3] = cMINA;
    pos p = {1, 2};
    int res = minasAdyacentes(t, p);

    ASSERT_EQ(res, 8);
}

// ....
// xxx.
// xxx.
// xxx.
TEST(minasAdyacentes, posEsMina) {
    tablero t = vector<vector<bool>>(4, vector<bool>(4, false));
    t[0][1] = cMINA;
    t[0][2] = cMINA;
    t[0][3] = cMINA;
    t[1][1] = cMINA;
    t[2][1] = cMINA;
    t[2][2] = cMINA;
    t[2][3] = cMINA;
    t[1][3] = cMINA;
    t[1][2] = cMINA;
    pos p = {1, 2};
    int res = minasAdyacentes(t, p);

    ASSERT_EQ(res, 8);
}