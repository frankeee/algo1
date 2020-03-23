//
// Created by Ralo on 14/04/2019.
//
#include "definiciones.h"
#include "auxiliares.h"
// auxiliares del ejercicio 1
bool sonMatrices(eph_h th, eph_i ti){
    return esMatriz(th) && esMatriz(ti);
}
bool esMatriz(vector<vector<int> > t){
    bool res = true;
    int i = 0;
    while(i < t.size() && t[i].size() == t[0].size()){
        i++;
    }
    return i == t.size();
}

bool cantCorrectaDeColumnas(eph_h th, eph_i ti){
    return columnasCorrectas(th, FILAS_HOGAR) && columnasCorrectas(ti,FILAS_INDIVIDUO);
}
bool columnasCorrectas(vector<vector<int> > t, int a){
    bool res = true;
    int i = 0;
    while (i < t.size()){
        if (t[i].size() != a){
            res = false;
            break;
        }
        i++;
    }
    return res;
}

bool hayRepetidos(eph_h th, eph_i ti){
    return hogaresRepetidos(th) || individuosRepetidos(ti);
}
bool hogaresRepetidos(eph_h th){
    bool res = false;
    int i = 0;
    while (i < th.size()-1 && !res){
        int j = i+1;
        while (j < th.size()){
            if (th[i][HOGCODUSU] == th[j][HOGCODUSU]){
                res = true;
                break;
            }
            j++;
        }
        i++;
    }
    return res;
}
bool individuosRepetidos(eph_i ti){
    bool res = false;
    int i = 0;
    while(i < ti.size()-1 && !res){
        int j = i+1;
        while(j < ti.size()){
            if (ti[i][INDCODUSU] == ti[j][INDCODUSU] && ti[i][COMPONENTE] == ti[j][COMPONENTE]){
                res = true;
                break;
            }
            j++;
        }
        i++;
    }
    return res;
}

bool indSinHogar(eph_i ti,eph_h th){
    bool res = false;
    int i = 0;
    while(i < ti.size()){
        int j = 0;
        int hog = 0;
        while (j < th.size()){ // veo si hay un hogar al cual pertenece el individuo
            if (ti[i][INDCODUSU] == th[j][HOGCODUSU]){
                hog = hog + 1;
            }
            j++;
        }
        if ( hog == 1){ //si la cantidad es 1 paso al siguiente individuo
            i++;
        }else{
            res = true; // si la cantidad no es 1 salgo del "while"
            break;
        }

    }
    return res;
}
bool hogarSinInd(eph_h th,eph_i ti){
    bool res = false;
    int i = 0;
    while (i < th.size()){
        int j = 0;
        int ind = 0;
        while (j < ti.size()){ // cuento la cantidad de individuos en el hogar
            if (ti[j][INDCODUSU] == th[i][HOGCODUSU]){
                ind = ind + 1;
            }
            j++;
        }
        if ( ind >= 1){ // si la cant. de individuos es mayor a 0 pasa al siguiente hogar
            i++;
        }else{
            res = true; // si la cantidad es 0 salgo del "while"
            break;
        }
    }
    return res;
}

bool mismosAnioYTrimestre(eph_h th,eph_i ti){
    bool res = true;
    if (th[0][HOGANIO] != ti[0][INDANIO] || th[0][HOGTRIMESTRE] != ti[0][INDTRIMESTRE]){ // revisa que el año y el trimestre sea igual en ambas listas
        res = false;
    }else{
        if (distintoAnio(ti,th)){ // revisa si hay algún elemento de la lista con año distinto
            res = false;
        }else{
            if(distintoTrimestre(ti,th)){ // revisa si hay algún elemento de la lista con trimestre distinto
                res = false;
            }
        }
    }
    return res;
}
bool distintoAnio(eph_i ti, eph_h th){
    int distA = 0;
    int i = 0;
    while (i < ti.size()){ // cuanta la cantidad de individuos con año distinto al primer elemento
        if (ti[i][INDANIO] != ti[0][INDANIO]){
            distA = distA + 1;
        }
        i++;
    }
    int distB = 0;
    int j = 0;
    while (j < th.size()){ // cuanta la cantidad de hogares con año distinto al primer elemento
        if(th[j][HOGANIO] != th[0][HOGANIO]){
            distB = distB + 1;
        }
        j++;
    }
    return distA > 0 || distB > 0; // si la cantidad de individuos o hogares que tienen distinto año es mayor a 0 devuelve true
}
bool distintoTrimestre(eph_i ti, eph_h th){
    int distA = 0;
    int i = 0;
    while (i < ti.size()){ // cuanta la cantidad de individuos con trimestre distinto al primer elemento
        if (ti[i][INDTRIMESTRE] != ti[0][INDTRIMESTRE]){
            distA = distA + 1;
        }
        i++;
    }
    int distB = 0;
    int j = 0;
    while (j < th.size()){ // cuanta la cantidad de hogares con año distinto al primer elemento
        if(th[j][HOGTRIMESTRE] != th[0][HOGTRIMESTRE]){
            distB = distB + 1;
        }
        j++;
    }
    return distA > 0 || distB > 0; // si la cantidad de individuos o hogares que tienen distinto trimestre es mayor a 0 devuelve true

}

bool menosDe21MiembrosPorHogar(eph_h th,eph_h ti){
    bool res = true;
    int i = 0;
    while (i < th.size()){
        int miembros = cantMiembros(th[i],ti);
        if(miembros > 20){
            res = false;
            break;
        }
        i++;
    }
    return res;
}
int cantMiembros(hogar h, eph_i ti){
    int i = 0;
    int res = 0;
    while (i < ti.size()){
        if (h[HOGCODUSU] == ti[i][INDCODUSU]){
            res = res + 1;
        }
        i++;
    }
    return res;
}

bool cantValidaDormitorios(eph_h th){
    bool res = true;
    int i = 0;
    while (i < th.size()){
        if (th[i][IV2] < th[i][II2]){ // si encuetra un hogar que cumple la condicion del "if"
            res = false;             // devuelve false y termina el ciclo
            break;
        }
        i++;
    }
    return res;
}

bool valoresEnRango(eph_h th,eph_i ti){
    return valoresCorrectosH(th) && valoresCorrectosI(ti);
}
bool valoresCorrectosH(eph_h th){
    bool res = true;
    int i = 0;
    while(i < th.size()){
        if((th[i][HOGCODUSU] > 0) && (th[i][HOGTRIMESTRE] > 0 && th[i][HOGTRIMESTRE] <= 4) && (th[i][II7] > 0 && th[i][II7] <= 3)
           && (th[i][REGION] > 0 && th[i][REGION] <= 6) && (th[i][MAS_500] == 0 || th[i][MAS_500] == 1) &&
           (th[i][IV1] > 0 && th[i][IV1] <= 5) && (th[i][IV2] > 0) && (th[i][II2] >= 1) && (th[i][II3] == 1 || th[i][II3] == 2 )){
            res = true;
        }else{
            res = false;
            break;
        }
        i++;
    }
    return res;
}
bool valoresCorrectosI(eph_i ti){
    bool res = true;
    int i = 0;
    while(i < ti.size()){
        if ((ti[i][INDCODUSU] > 0) && (ti[i][COMPONENTE] > 0) && (ti[i][INDTRIMESTRE] > 0 && ti[i][INDTRIMESTRE] <= 4) &&
            (ti[i][CH4] == 1 || ti[i][CH4] == 2) && (ti[i][CH6] >= 0) && (ti[i][NIVEL_ED] == 0 || ti[i][NIVEL_ED] == 1)
            && (ti[i][ESTADO]>= -1 && ti[i][ESTADO] <= 1) && (ti[i][CAT_OCUP] >= 0 && ti[i][CAT_OCUP] <= 4) &&
            (ti[i][p47T] >= 0 || ti[i][p47T] == -1) && (ti[i][PP04G] > 0 && ti[i][PP04G] <= 10)){
            res = true;
        }else{
            res = false;
            break;
        }
        i++;
    }
    return res;
}
//Auxiliares del ej 2
int casaValidaConMasHabitaciones(eph_h th,int region){
    int h=0;
    int s =0;
    while(h< th.size()){/*va iterando todas la casas*/
        if(th[h][REGION]== region && th[h][IV1]==1 && th[h][IV2]> s){
            s= th[h][IV2];
        }
        h++;
    }
    return s;
}

void agregaCerosAMatrizPorHabitacionMaxima(int s,vector<int> &res){
    int n=0;
    while(n<s){
        res.push_back(0);
        n++;
    }
}

void sumaCantidadDeHabitacionesPorCasa(eph_h th, int region,vector<int> &res){
    int h= 0;


    while(h< th.size()) {
        if (th[h][REGION] == region && th[h][IV1] == 1){
            res[th[h][IV2]-1]++;
        }
        h++;
    }
}

// Auxiliares del Ejercicio 3
bool esHogarValido(hogar h, int a){
    return h[REGION] == a && h[MAS_500] == 0 && h[IV1] == CASA;
}
bool esAsinamientoCritico(int a, hogar h){
    return a > 3*h[II2];
}

// Auxiliares del Ejercicio 4
float porcentajeTeleworkers(eph_h th, eph_i ti){
    int i = 0;
    float teleworkers = 0;
    float trabajadores = 0;
    while(i < ti.size()){
        if (esTeleworker(ti[i])){
            int h = 0;
            while (h < th.size()){
                if(perteneceAlHogarValido(ti[i],th[h])){
                    trabajadores++;
                    teleworkers++;
                }
                else if (perteneceAlHogarValido(ti[i],th[h])){
                    trabajadores++;
                }
                h++;
            }
        }else if (noEsTeleworker(ti[i])){
            int h = 0;
            while (h < th.size()){
                if (perteneceAlHogarValido(ti[i],th[h])){
                    trabajadores++;
                }
                h++;
            }
        }
        i++;
    }
    return teleworkers/trabajadores;
}
bool esTeleworker(individuo i){
    return i[ESTADO]==1 && i[PP04G]== 6;
}
bool noEsTeleworker(individuo i){
    return i[ESTADO] == 1 && i[PP04G] != 6;
}
bool perteneceAlHogarValido(individuo i, hogar h){
    if (i[PP04G] == 6){
        return h[HOGCODUSU] == i[INDCODUSU] && (h[IV1] == CASA || h[IV1] == 2)&& h[MAS_500] == 1 && h[II3] == 1;
    }else{
        return h[HOGCODUSU] == i[INDCODUSU] && (h[IV1] == CASA || h[IV1] == 2)&& h[MAS_500] == 1;
    }
}

//axuliares del ejercicio 5
void ordenaThRegionYCodusu(eph_h &th){
    int r = 0;
    int n = 0;
    hogar aux;
    int i =0;
    vector<hogar> s;
    //ordena2elementos
    //itera toda la lista inicial
    while(i < th.size()){
        s.push_back(th[i]);
    //itera todala lista secundaria para ver si alguno es menor al ultimo que es el que agrege
        while(n < s.size()-1){
            if (s[s.size()-1][REGION]<s[n][REGION]||(s[s.size()-1][REGION]==s[n][REGION] && s[s.size()-1][HOGCODUSU]<s[n][HOGCODUSU])){
    //si lo encuentra agarra a  ulitmo termino y iguala el aux a este
                aux = s[s.size()-1];
                r = s.size()-1;
    //itera la lista s desde el final hasta la poiscion que quiero cambiar sumandole +1 a todos
                while(r > n){
                    s[r] = s[r-1];
                    r--;
                }
            s[n] = aux;
            }
            n++;
        }
    n= 0;
    i++;
    }
    th = s;
}

void ordenaTiRcomponenteYCodusu(eph_i &ti,eph_h th){
    int n = 0;
    individuo aux1;
    int i = 0;
    int r = 0;
    vector<individuo> z;
//ordena2elementos
//itera toda la lista inicial
    while(i < ti.size()){
        z.push_back(ti[i]);
//itera todala lista secundaria para ver si alguno es menor al ultimo que es el que agrege
        while(n < z.size()-1){
            if(z[z.size()-1][INDCODUSU]!= z[n][INDCODUSU]){
                hogar compara1;
                hogar compara2;
                int f = 0;
                while(f<th.size()){
                    if(th[f][0]== z[z.size()-1][0] ){
                        compara1  = th[f];
                    }
                    else if(th[f][0] == z[n][0]){
                        compara2 = th[f];
                    }
                    f++;
                }
                if(compara1[REGION]<compara2[REGION]||(compara1[REGION]==compara2[REGION] && compara1[HOGCODUSU] < compara2[HOGCODUSU])){
                    //si lo encuentra agarra a  ulitmo termino y iguala el aux a este
                    aux1 = z[z.size()-1];
                    r = z.size()-1;
//itera la lista s desde el final hasta la poiscion que quiero cambiar sumandole +1 a todos
                    while(r > n){
                        z[r] = z[r-1];
                        r--;
                    }
                    z[n] = aux1;
                }
            }
            else if (z[z.size()-1][INDCODUSU]==z[n][INDCODUSU] && z[z.size()-1][COMPONENTE]<z[n][COMPONENTE]){
//si lo encuentra agarra a  ulitmo termino y iguala el aux a este
                aux1 = z[z.size()-1];
                r = z.size()-1;
//itera la lista s desde el final hasta la poiscion que quiero cambiar sumandole +1 a todos
                while(r > n){
                    z[r] = z[r-1];
                    r--;
                }
                z[n] = aux1;
            }
            n++;
        }
        n= 0;
        i++;
    }
    ti = z;
}
//auxiliares del ejercicio 6

void ordenaThIngresos(eph_h &th,eph_i ti){
    int h=0;
    while(h<th.size()-1){
        if(ingresos(th[h],ti) > ingresos(th[h+1],ti)){
            hogar aux = th[h+1];
            int s= 0;
            while(s<h+1){
                if(ingresos(th[s],ti) > ingresos(th[h+1],ti)){
                    int r= h+1;
                    while(r>s){
                        th[r]= th[r-1];
                        r--;
                    }
                    th[s]= aux;
                    break;
                }
                s++;
            }
        }
        h++;
    }
}

vector<vector<hogar>> devuelveTodasDiferenciasPosibles(eph_h th,eph_i ti){

    vector<vector<hogar>> auxlista = {{}};
    int i = 0;
    while(i < th.size()-2){
        int g = i+1;
        while(g < th.size()-1){
            float dif = ingresos(th[g],ti) - ingresos(th[i],ti);
            int z = g+1;
            int a = g; // agregue esta variable
            int p = auxlista.size()-1;
            auxlista[p].push_back(th[i]);
            auxlista[p].push_back(th[g]);
            while(z < th.size()){
                if(ingresos(th[z],ti) - ingresos(th[a],ti) == dif && ingresos(th[a],ti)!= 0){
                    auxlista[p].push_back(th[z]);
                    a = z; // me parecio que el problema Esta aquí por que cuando era g=z y salia de este "while(z<..)"
                }         //  se salteaba algunos hogares.
                z++;
            }
            g++;
            auxlista.emplace_back();
        }
        i++;
    }
    return auxlista;
}

vector<hogar> devuelveListaMasLarga(vector<vector<hogar>> auxlista){
    vector<hogar> auxito = {};
    int v = 0;
    while(v<auxlista.size()){
        if(auxito.size()<auxlista[v].size()){
            auxito = auxlista[v];
        }
        v++;
    }
    return auxito;
}

// auxiliares del ejercicio 8

float areaObservada(eph_h th, eph_i ti){
    return AREAIGUALDADTOTAL - integralDeIngresosObservados(th,ti);
}
float ingresosPerCapitaEnHogar(hogar h, eph_i ti){
    return (ingresos(h,ti)/cantMiembros(h,ti));
}
float ingresos(hogar h,eph_i ti){
    int i = 0;
    float sumaIngresos = 0.0;
    while (i < ti.size()){
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1){
            sumaIngresos = sumaIngresos + ti[i][p47T];
        }
        i++;
    }
    return sumaIngresos;
}

float ingresosHasta(int n, eph_h th, eph_i ti){
    int i = 0;
    float total = 0.0;
    while ( i <= n){
        total = total + ingresosPerCapitaEnHogar(th[i],ti);
        i++;
    }
    return total;
}
float integralDeIngresosObservados(eph_h th, eph_i ti){
    int i = 0;
    float result = 0.0;
    while(i < th.size()){
        result = result + (porcentajeDelIngreso(i-1,th,ti) + (porcentajeObtenidoEnElhogar(th[i],th,ti))/2);
        i++;
    }
    float res = result / th.size();
    return res;
}
float porcentajeDelIngreso(int n, eph_h th, eph_i ti){ //Es la proporcion de ingresos acumulados con respecto al total
    float result = 0.0;
    if (n >= 0) {
        result =  ingresosHasta(n, th, ti) / ingresosHasta(th.size() - 1, th, ti);
    }
    return result;
}
float porcentajeObtenidoEnElhogar(hogar h, eph_h th, eph_i ti){ //Es el porcentaje del ingreso total que se queda el hogar
    float result = ingresosPerCapitaEnHogar(h,ti)/ingresosHasta(th.size()-1,th,ti);
    return result;
}
