#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"


bool esEncuestaValida(eph_h th, eph_i ti) {
    bool esValida = true;
    if (th.size() == 0 || ti.size() == 0) {
        esValida = false;
    }else{
        if (!sonMatrices(th,ti) || !cantCorrectaDeColumnas(th,ti)){
            esValida = false;
        }else{
            if (hayRepetidos(th,ti) || indSinHogar(ti,th) || hogarSinInd(th,ti)){
                esValida = false;
            }else{
                if (!mismosAnioYTrimestre(th,ti) || !menosDe21MiembrosPorHogar(th,ti) ||
                    !cantValidaDormitorios(th) || !valoresEnRango(th,ti)){
                    esValida = false;
                }
            }
        }
    }
    return esValida;
}

vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> matrizDeRegion(CANTIDAD_DE_REGIONES);
    vector<int> res  = {};
    int s = casaValidaConMasHabitaciones(th,region);
    agregaCerosAMatrizPorHabitacionMaxima(s,res);
    sumaCantidadDeHabitacionesPorCasa(th,region,res);
    return res;
}

vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<float> res(CANTIDAD_DE_REGIONES);
    int i  = 0;
    while(i < res.size()){
        int h = 0;
        float cantValAsi = 0;
        float cantVal = 0;
        while(h < th.size()){
            int cantPersonas = 0;
            if(esHogarValido(th[h], i+1)){
                cantPersonas = cantMiembros(th[h],ti);
                if(esAsinamientoCritico(cantPersonas,th[h])){
                    cantValAsi++;
                }
                cantVal++;
            }
            h++;
        }
        if(cantVal > 0){
            res[i]= cantValAsi/cantVal;
        }
        i++;
    }
    return res;
}

bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    float proporcion1= porcentajeTeleworkers(t1h,t1i);
    float proporcion2= porcentajeTeleworkers(t2h,t2i);

    return proporcion2 > proporcion1;
}

void ordenarRegionYCodusu(eph_h& th, eph_i& ti) {
    ordenaThRegionYCodusu(th);
    ordenaTiRcomponenteYCodusu(ti,th);
}

vector<hogar> muestraHomogenea(eph_h th, eph_i ti) {
    ordenaThIngresos(th,ti);
    vector<vector<hogar>> auxlista = devuelveTodasDiferenciasPosibles(th,ti);
    vector<hogar> auxito = devuelveListaMasLarga(auxlista);
    vector<hogar> res = {};
    if(auxito.size() > 2){
        res = auxito;
    }
    return res;
}

void corregirRegion(eph_h& th, eph_i ti) {
    int i = 0;
    while (i < th.size()){
        if (th[i][REGION] == GBA){
            th[i][REGION] = PAMPEANA;
        }
        i++;
    }
}

float indiceGini(eph_h th, eph_i ti) {
    float indice = (areaObservada(th,ti)/AREAIGUALDADTOTAL);
    return indice;
}