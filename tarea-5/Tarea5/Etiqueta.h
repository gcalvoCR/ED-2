#pragma once
#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
class Etiqueta {
public:
    Etiqueta();
    Etiqueta(int);
    int getPeso();
    void setPeso(int);
    string toString();

private:
    int peso;
};

#endif /* ETIQUETA_H */

