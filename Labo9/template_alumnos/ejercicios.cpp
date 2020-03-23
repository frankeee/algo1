#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>
#include <cmath>

using namespace std;

int busquedaBinaria(vector<int> v, int x){
    int max = v.size()-1;
    int min = 0;
    while(max-min > 2){
        if(max % 2 == 1){
            int medio =(max-1)/2+1;
            if(x > v[medio]){
                min = medio;
            }
            else if(x<v[medio]){
                max = medio;
            }
            else {
                return medio;
            }
        }
        else if(max % 2 == 0){
            int medio = max /2;
            if(v[medio] < x){
                min = medio;
            }
            else if(v[medio]> x){
                max = medio;
            }
            else{
                return medio;
            }


        }
    }
    if(max - min == 2){
        if(x == v[max]){
            return max;
        }
        else if(x == v[max-1]){
            return max-1;
        }
        else if( x == v[min]){
            return min;
        }
        else {
            return -1;
        }
    }
    if(max - min == 1){
        if(x == v[max]){
            return max;
        }
        else if(x == v[min]){
            return min;
        }
        else {
            return -1;
        }

    }

	return -1;
}

int busquedaJumpSearch(vector<int> v, int x) {
    int m = 2;
    int i = 1;
    int h = 0 + m * i;
    if (v[0] > v[1]) {
        return 0;
    }


    while (h < v.size()) {
        if (h = v.size() - 1 && v[h] > v[h - 1]) {
            return h;
        }
        else if (v[h] > v[h + 1] && v[h] > v[h - 1]) {
            return h;

        }
        else if (v[h - 1] > v[h] && v[h - 1] > v[h - 2]) {
                return h - 1;
        }
        else if (v[h + 1] > v[h] && v[h + 1] > v[h + 2]) {
                return h + 1;
        }
        else {
                i++;

            }
        }



    return -1;
}

int buscar(vector<int> v, int x){
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    using namespace std;
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC/1000);
    return elapsed_secs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> v){

    int juan = busquedaJumpSearch(v,9);
	return juan;
}

int puntoFijo(vector<int> v){
	return -1;
}

int encontrarRotado(vector<int> v, int x){
	return -1;
}

int menorMasGrande(vector<int> v, int x){
	return -1;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
