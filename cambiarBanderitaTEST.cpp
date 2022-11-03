// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(CambiarBanderita, esta) {
    pos b1 = {0,0};
    pos b2 = {1, 1};
    pos b3 = {2, 2};

    banderitas b = {b1, b2, b3};
    tablero t;
    jugadas j;
    cambiarBanderita(t, j, b2, b);

    banderitas expected = {b1, b3};
    ASSERT_EQ(b, expected);
}

TEST(CambiarBanderita, estaAlFinal) {
    pos b1 = {0,0};
    pos b2 = {1, 1};
    pos b3 = {2, 2};

    banderitas b = {b1, b3, b2};

    tablero t;
    jugadas j;
    cambiarBanderita(t, j, b2, b);

    banderitas expected = {b1, b3};
    ASSERT_EQ(b, expected);
}

TEST(CambiarBanderita, noEsta) {
    pos b1 = {0,0};
    pos b2 = {1, 1};
    pos b3 = {2, 2};

    banderitas b = {b1, b3};

    tablero t;
    jugadas j;
    cambiarBanderita(t, j, b2, b);

    banderitas expected = {b1, b3, b2};
    ASSERT_EQ(b, expected);
}
