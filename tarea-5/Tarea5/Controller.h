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
    Controller(const Controller& orig);
    virtual ~Controller();
    Grafo* getGrafo();
    bool agregarEnArreglo(int, string);
    string agregarEnMatriz(int, int, int, int);
    int buscarCiudad(string);
    string buscarEtiqueta(int, int);
    string mostrarCiudades();
    string mostrarEtiquetas();
private:
    Grafo* grafo;

};

#endif /* CONTROLLER_H */

