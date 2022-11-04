// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// x.
// ..
TEST(Perdio, noPerdio) {
    tablero t = {
            {cMINA, cVACIA},
            {cVACIA, cVACIA}
    };

    jugadas j = {{{1,1}, 1}};

    bool p = perdio(t, j);

    ASSERT_FALSE(p);
}

TEST(Perdio, perdio) {
    tablero t = {
            {cMINA, cVACIA},
            {cVACIA, cVACIA}
    };

    jugadas j = {{{1,1}, 1}, {{0,0}, 0}};

    bool p = perdio(t, j);

    ASSERT_TRUE(p);
}
