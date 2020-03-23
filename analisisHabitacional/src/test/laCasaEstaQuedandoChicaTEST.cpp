#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define UMBRAL 0.0001


// todo valido, calculo algunos valores
TEST(laCasaEstaQuedandoChicaTEST, todos50) {

//                          Región\ +500 /Tipo
//                                 v  v  v
    eph_h th = {{334,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {960,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {1366, 2017, 1, 2, 2, 0, 1, 2, 1, 2},
                {1250, 2017, 1, 3, 2, 1, 1, 2, 1, 2}, // Esta no: +500
                {1550, 2017, 1, 3, 2, 0, 1, 2, 1, 2},
                {1388, 2017, 1, 3, 3, 0, 1, 2, 1, 2},
                {118,  2017, 1, 3, 3, 0, 1, 2, 1, 2},
                {1500, 2017, 1, 3, 4, 0, 1, 2, 1, 2},
                {500,  2017, 1, 3, 4, 0, 4, 2, 1, 2}, // Esta no: Hotel
                {961,  2017, 1, 1, 4, 0, 1, 2, 1, 2},
                {66,   2017, 1, 2, 5, 0, 1, 2, 1, 2},
                {550,  2017, 1, 3, 5, 0, 1, 2, 1, 2},
                {288,  2017, 1, 3, 6, 0, 1, 2, 1, 2},
                {18,   2017, 1, 3, 6, 0, 1, 2, 1, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {961,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {961,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {550,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {550,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {288,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1250, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1550, 1, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 2, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 3, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 4, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {66,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1},
                {1388, 2, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    vector<float> esperado = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
    vector<float> resultado = laCasaEstaQuedandoChica(th, ti);

    int i=0;
    while( i < 6 ) {
      EXPECT_EQ( true, flotante_valido(esperado[i], resultado[i], UMBRAL) );
      i++;
    }
}

// no hay casas
TEST(laCasaEstaQuedandoChicaTEST, sinCasasChico) {

//                          Región\ +500 /Tipo
//                                 v  v  v
    eph_h th = {{334,  2017, 1, 1, 1, 0, 2, 2, 1, 2},
                {1366, 2017, 1, 2, 2, 0, 3, 2, 1, 2},
                {118,  2017, 1, 3, 3, 0, 5, 2, 1, 2},
                {1500, 2017, 1, 3, 4, 0, 4, 2, 1, 2},
                {66,   2017, 1, 2, 5, 0, 2, 2, 1, 2},
                {288,  2017, 1, 3, 6, 0, 2, 2, 1, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {1366, 2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {118,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {288,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {66,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6}};

    if (!esEncuestaValida(th,ti)) {
        ASSERT_TRUE(esEncuestaValida(th,ti));
    }
    else {
        vector<float> esperado = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        vector<float> resultado = laCasaEstaQuedandoChica(th, ti);

        int i=0;
        while( i < 6 ) {
            EXPECT_EQ( true, flotante_valido(esperado[i], resultado[i], UMBRAL) );
            i++;
        }
    }
}

// Caso (0/0), sin casas con menos 500 (misma region)
TEST(laCasaEstaQuedandoChicaTEST, menos500_2) {

//                          Región\ +500 /Tipo
//                                 v  v  v
    eph_h th = {{334,  2017, 1, 1, 3, 1, 1, 2, 1, 2},
                {960,  2017, 1, 1, 3, 1, 1, 2, 1, 2},
                {1366, 2017, 1, 2, 3, 1, 1, 2, 1, 2},
                {1250, 2017, 1, 3, 3, 1, 1, 2, 1, 2}, // Esta no: +500
                {1550, 2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {1388, 2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {118,  2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {1500, 2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {500,  2017, 1, 3, 3, 1, 4, 2, 1, 2}, // Esta no: Hotel
                {961,  2017, 1, 1, 3, 1, 1, 2, 1, 2},
                {66,   2017, 1, 2, 3, 1, 1, 2, 1, 2},
                {550,  2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {288,  2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {18,   2017, 1, 3, 3, 1, 1, 2, 1, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {961,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {961,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {550,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {550,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {288,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1250, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1550, 1, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 2, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 3, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 4, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {66,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1},
                {1388, 2, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    if (!esEncuestaValida(th,ti)) {
        ASSERT_TRUE(esEncuestaValida(th,ti));
    }
    else {
        vector<float> esperado = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        vector<float> resultado = laCasaEstaQuedandoChica(th, ti);

        int i=0;
        while( i < 6 ) {
            EXPECT_EQ( true, flotante_valido(esperado[i], resultado[i], UMBRAL) );
            i++;
        }
    }
}

// Casas en una unica region
TEST(laCasaEstaQuedandoChicaTEST, unicoIndice) {

//                          Región\ +500 /Tipo
//                                 v  v  v
    eph_h th = {{334,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {960,  2017, 1, 1, 1, 0, 1, 2, 1, 2},
                {1366, 2017, 1, 2, 2, 1, 1, 2, 1, 2},
                {1250, 2017, 1, 3, 2, 1, 1, 2, 1, 2}, // Esta no: +500
                {1550, 2017, 1, 3, 2, 1, 1, 2, 1, 2},
                {1388, 2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {118,  2017, 1, 3, 3, 1, 1, 2, 1, 2},
                {1500, 2017, 1, 3, 4, 1, 1, 2, 1, 2},
                {500,  2017, 1, 3, 4, 1, 4, 2, 1, 2}, // Esta no: Hotel
                {961,  2017, 1, 1, 4, 1, 1, 2, 1, 2},
                {66,   2017, 1, 2, 5, 1, 1, 2, 1, 2},
                {550,  2017, 1, 3, 5, 1, 1, 2, 1, 2},
                {288,  2017, 1, 3, 6, 1, 1, 2, 1, 2},
                {18,   2017, 1, 3, 6, 1, 1, 2, 1, 2}};

    eph_i ti = {{334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {334,  2, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
                {961,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {961,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {960,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1366, 2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {550,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {550,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {118,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {500,  4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {288,  1, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  2, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {288,  4, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
                {1250, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1250, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1550, 1, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 2, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 3, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1550, 4, 2017, 1, 0, 2, 30, 1,  3, 8500,  2},
                {1500, 1, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 3, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {1500, 4, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
                {66,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   3, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {66,   4, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {18,   2, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
                {1388, 1, 2017, 1, 0, 1, 67, 1,  3, 20000, 1},
                {1388, 2, 2017, 1, 0, 1, 67, 1,  3, 20000, 1}};

    vector<float> esperado = {0.5, 0.0, 0.0, 0.0, 0.0, 0.0};
    vector<float> resultado = laCasaEstaQuedandoChica(th, ti);

    int i=0;
    while( i < 6 ) {
        EXPECT_EQ( true, flotante_valido(esperado[i], resultado[i], UMBRAL) );
        i++;
    }
}
