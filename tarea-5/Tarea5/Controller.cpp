
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

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

Grafo* Controller::getGrafo() {
    return grafo;
}

bool Controller::agregarEnArreglo(int pPosicion, string pCiudad) {
    return getGrafo()->insertarArreglo(pPosicion, pCiudad);

}

string Controller::agregarEnMatriz(int pFila, int pColumna, int pDistancia, int pTiempo) {
    Etiqueta etiqueta(pDistancia, pTiempo);
    getGrafo()->insertarEtiqueta(pFila, pColumna, etiqueta);
    return "Datos guardados";
}

int Controller::buscarCiudad(string pCiudad) {
    return getGrafo()->buscarCiudad(pCiudad);
}

string Controller::buscarEtiqueta(int pFila, int pColumna) {
    return getGrafo()->buscarDatosEtiqueta(pFila, pColumna);
}

string Controller::mostrarCiudades() {
    return getGrafo()->mostrarArreglo();
}

string Controller::mostrarEtiquetas() {
    return getGrafo()->mostrarEtiquetas();
}
