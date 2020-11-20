#pragma once

#ifndef GRAFOMULTIPLE_H
#define GRAFOMULTIPLE_H
#include "NodoMultiple.h"
#include "AristaMultiple.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class GrafoMultiple {
public:
    GrafoMultiple();
    string insertar_nodo(char, int);
    void agrega_arista(TnodoMultiple&, TnodoMultiple&, TaristaMultiple&);
    bool insertar_arista(char, char, int);
    string mostrar_grafo();

private:
    TnodoMultiple p;//puntero cabeza

};

#endif /* GRAFOMULTIPLE_H */

