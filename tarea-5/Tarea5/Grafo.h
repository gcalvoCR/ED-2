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
    bool insertarArreglo(int, string);
    int buscarCiudad(string);
    string buscarDatosEtiqueta(int, int);
    string mostrarArreglo();
    string mostrarEtiquetas();

private:
    Etiqueta matriz[8][8];
    string referencia[8];

};

#endif /* GRAFO_H */

