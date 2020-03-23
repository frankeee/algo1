#include "vectores.h"
#include <iostream>
#include <fstream>


// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio
bool divide(vector<int> v, int a){
    int i = 0;
    while(i< v.size()){
        if(v[i]% a == 0){

        }
        else{
            break;
        }
        i += 1;
    }
    if( i == v.size()){
        return true;

        }
    else{
        return false;
        }

}

//Ejercicio
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	int i = 0;
	int mayor = 0;
	while(i < v.size()){
	    if(mayor < v[i]){
            mayor = v[i];
	    }
	    else{}
	    i++;


	}
	return mayor;
}

//Ejercicio
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
	vector<int> r ;
	int i = v.size()-1;

	while(-1 < i){
	    r.push_back(v[i]);

	    i -=1;
	}
	return r;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
}

bool estaOrdenado(vector<int>v){
    int i = 0;

    while(i< v.size()-1){
        if(v[i] > v[i+1]){
            break;
        }
        else{}
        i ++;
    }
    if(i == v.size()-1){
        return true;
    }
    else{
        return false;
    }
}

//Ejercicio
vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo

}

//Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	int i = 0;
	while(i< v.size()){
	    std :: cout <<v[i]<< std ::endl;
	    i ++;
	}
}

vector<int> leearchivo(string nombreArchivo){
    ifstream archivoIn;

    archivoIn.open(nombreArchivo);
    vector<int>lector;
    if (archivoIn.fail()){
        cout << "fallo lectura" << endl;
    }
    else {
        int i = 0;
        while (i < archivoIn.size()) {
            archivoIn >> lector[i];
            i++;

        }
    }
    return lector;


}
void guardarVector(vector<int>v, string nombreArchivo){
    ofstream archivoOut;
    archivoOut.open(nombreArchivo,ios_base :: app);
    int i = 0;
    while(i < v.size()){
        archivoOut << v[i] << endl;
        i++;
    }
}

bool estaEnLaLista(vector<int> vactor, int r){
    int i = 0;
    while( i < vactor.size()){
        if(r == vactor[i]){
            return true;
        }
        else{}
        i++;
    }
    return false;
}

void cantApariciones(string nombreArchivo){
    vector<int> juancete = leearchivo(nombreArchivo);
    ofstream archivoOut;
    archivoOut.open("archivos/out/nuevonuevo.txt");
    int i = 0;
    vector<int> yaAnalizados;
    while(i < juancete.size()){
        if(estaEnLaLista(yaAnalizados,juancete[i])){

        }
        else{
            int s = i+1;
            int r = 1;
            while(s<juancete.size()){
                if(juancete[s] == juancete[i]){
                    r++;
                }
                else{}
                s++;

            }
            archivoOut << juancete[i] <<"esta" << r <<"veces "<< endl;

        }
        yaAnalizados.push_back(juancete[i]);
        i++;



    }
}



