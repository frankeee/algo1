//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
// Auxiliares del Ejercicio 1:
bool sonMatrices(eph_h th, eph_i ti);
bool esMatriz(vector<vector<int> > t);
bool cantCorrectaDeColumnas(eph_h th, eph_i ti);
bool columnasCorrectas(vector<vector<int> > t, int a);
bool hayRepetidos(eph_h th, eph_i ti);
bool hogaresRepetidos(eph_h th);
bool individuosRepetidos(eph_i ti);
bool indSinHogar(eph_i ti,eph_h th);
bool hogarSinInd(eph_h th,eph_i ti);
bool mismosAnioYTrimestre(eph_h th,eph_i ti);
bool distintoAnio(eph_i ti,eph_h th);
bool distintoTrimestre(eph_i ti, eph_h th);
bool menosDe21MiembrosPorHogar(eph_h th,eph_h ti);
int cantMiembros (hogar h, eph_i ti);
bool cantValidaDormitorios(eph_h th);
bool valoresEnRango(eph_h th,eph_i ti);
bool valoresCorrectosH(eph_h th);
bool valoresCorrectosI(eph_i ti);

//Auxiliares del ejercicio2
int casaValidaConMasHabitaciones(eph_h th,int region);
void agregaCerosAMatrizPorHabitacionMaxima(int s,vector<int> &res);
void sumaCantidadDeHabitacionesPorCasa(eph_h th, int region,vector<int> &res);

// Auxiliares del ejercicio 3
bool esHogarValido(hogar h, int a);
bool esAsinamientoCritico(int a, hogar h);

// Auxiliares del ejercicio 4
float porcentajeTeleworkers(eph_h th, eph_i ti);
bool esTeleworker(individuo i);
bool noEsTeleworker(individuo i);
bool perteneceAlHogarValido(individuo i, hogar h);

//Auxiliares del ejercicio 5
void ordenaThRegionYCodusu(eph_h &th);
void ordenaTiRcomponenteYCodusu(eph_i &ti,eph_h th);

//Auxiliares del ejercicio 6
void ordenaThIngresos(eph_h &th,eph_i ti);
vector<vector<hogar>> devuelveTodasDiferenciasPosibles(eph_h th,eph_i ti);
vector<hogar> devuelveListaMasLarga(vector<vector<hogar>> auxlista);

// Auxiliares del ejercicio 8
float areaObservada(eph_h th, eph_i ti);
float integralDeIngresosObservados(eph_h th, eph_i ti);
float ingresosPerCapitaEnHogar(hogar h, eph_i ti);
float ingresos(hogar h,eph_i ti);
float ingresosHasta(int n, eph_h th, eph_i ti);
float porcentajeDelIngreso(int n, eph_h th, eph_i ti);
float porcentajeObtenidoEnElhogar(hogar h, eph_h th, eph_i ti);

#endif //SOLUCION_AUXILIARES_H