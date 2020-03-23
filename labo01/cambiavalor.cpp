//
// Created by Franco on 26/3/2019.
//

#include <iostream>

void cambiarValor(int &x) {
    x = 15;
    }
int main() {
    int y = 10;
    cambiarValor(y);
    std :: cout << y << std ::endl;
    return 0;
}
