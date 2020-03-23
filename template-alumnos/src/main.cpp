#include "vectores.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;



int main() {
    vector<int> juan ;
    int i =3;

    while(i<=15){
        juan.push_back(i);
        i = i+3;

    }

    holaModuloVectores(); // función definida en vectores.cpp

    /*cout << divide(juan,3) <<  endl;
    cout << mayor(juan) << endl;
    vector<int> jorge = reverso(juan);
    int s = 0;
    while(s < jorge.size()){
        cout << jorge[s]<< endl;
        s ++;
    }
    cout << estaOrdenado(juan) << endl;

    mostrarVector(juan);*/
    /*int d = 0;

    vector<int> superlector = leearchivo("archivos/in/10NumerosEntre1y10EnOrden2.in");

    while(d < superlector.size()){
        cout << superlector[d] << endl;
        d ++;
    }*/

    guardarVector(juan,"archivos/out/metonumeros.txt");

    cantApariciones("archivos/in/cantidadApariciones.in");


    return 0;
}
