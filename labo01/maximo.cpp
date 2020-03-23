//
// Created by Franco on 26/3/2019.
//

#include <iostream>
#include "maximo.h"

int maximo(int i ,int r){
    if(i > r){
        return i;
    }
    else{
        return r;
    }
}

int main(){
    std :: cout << "el maximo es "<< maximo(4,5) << std :: endl;

}
