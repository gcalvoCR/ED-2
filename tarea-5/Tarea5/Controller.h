#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Grafo.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
class Controller {
public:
    Controller();
    virtual ~Controller();
    Grafo* getGrafo();
    bool insertarVerticeEnArreglo(int, int);
    string agregarArcoEnMatriz(int, int, int);
    int buscarVertice(int);
    int buscarEtiqueta(int, int);
    string mostrarVertices();
    string mostrarEtiquetas();
private:
    Grafo* grafo;

};

#endif /* CONTROLLER_H */

