#pragma once

#ifndef GRAFO_H
#define GRAFO_H
#include "Etiqueta.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Grafo {
public:
    Grafo();
    Grafo(const Grafo& orig);
    virtual ~Grafo();
    Etiqueta* getMatriz();
    bool insertarEtiqueta(int, int, Etiqueta);
    bool insertarVertice(int, int);
    int buscarVertice(int);
    int buscarDatosEtiqueta(int, int);
    string mostrarVertices();
    string mostrarArcos();

private:
    Etiqueta matriz[8][8];
    int referencia[8];

};

#endif /* GRAFO_H */

