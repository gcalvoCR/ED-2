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
    Etiqueta(int, int);
    int getDistancia();
    void setDistancia(int);
    int getMinutos();
    void setMinutos(int);
    string toString();

private:
    int distancia;
    int minutos;
};

#endif /* ETIQUETA_H */

