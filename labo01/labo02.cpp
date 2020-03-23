//
// Created by Franco on 26/3/2019.
//

#include <iostream>

void promedio(float s){
    int sumatotal = 0;
    int particular = 0;
    float aprobados = 0;
    int reprobados  = 0;
    for( int a = 1; a <=s ; a= a+1){
        if(s < 6){
            std ::cout <<"la cantidad de alumnos debe ser mayor a 6" << std :: endl;
            break;
        }
        std::cout <<"Ingrese nota del alumno "<<a<< std::endl;
        std :: cin >> particular;
        std :: cout <<"La nota del alumno " << a << " es " << particular << std::endl;
        sumatotal = sumatotal + particular;
        if (particular >= 6){
            aprobados = aprobados + 1;
        }
        else{reprobados = reprobados +1;
        }



    }
    if(aprobados / s >= 0.66){
        std :: cout << " se puede aumentar el numero de plazas " <<  std:: endl;



    }
    else {}
    int promedio = sumatotal / s;
    std :: cout <<"El promedio es " << promedio<< std :: endl;
}

int triplicaPorValor(int r){
    return r *3;
}
void triplicaPorReferencia(int &juan){
    juan = juan *3;
}


int main(){
    promedio(3);
    std :: cout <<triplicaPorValor(3) << std :: endl;
    int porongon = 3;
    triplicaPorReferencia(porongon);
    std :: cout << porongon << std:: endl;

}