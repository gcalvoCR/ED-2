
#include "Controller.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Etiqueta.h"
#include "Grafo.h"

using namespace std;

Controller::Controller() {
    grafo = new Grafo();
}

Controller::~Controller() {
}

Grafo* Controller::getGrafo() {
    return grafo;
}

bool Controller::insertarVerticeEnArreglo(int pPosicion, int pVertice) {
    return grafo->insertarVertice(pPosicion, pVertice);
}

string Controller::agregarArcoEnMatriz(int pFila, int pColumna, int pPeso) {
    Etiqueta etiqueta(pPeso);
    grafo->insertarEtiqueta(pFila, pColumna, etiqueta);
    return "Datos guardados";
}

int Controller::buscarVertice(int pVertice) {
    return getGrafo()->buscarVertice(pVertice);
}

int Controller::buscarEtiqueta(int pFila, int pColumna) {
    return getGrafo()->buscarDatosEtiqueta(pFila, pColumna);
}

string Controller::mostrarVertices() {
    return getGrafo()->mostrarVertices();
}

string Controller::mostrarEtiquetas() {
    return getGrafo()->mostrarArcos();
}
