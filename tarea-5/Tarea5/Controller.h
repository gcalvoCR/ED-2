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
    //1. Métodos para primer grafo (matriz de adyacencia)
    bool insertarVerticeEnArreglo(int, int);
    string agregarArcoEnMatriz(int, int, int);
    int buscarVertice(int);
    int buscarEtiqueta(int, int);
    string mostrarVertices();
    string mostrarEtiquetas();
    //2. Métodos para segundo grafo (lista de adyacencia)
    string insertar_nodo_segundoGrafo(char);
    string insertar_arista_segundoGrafo(char, char);
    string eliminar_nodo_segundoGrafo(char);
    string eliminar_arista_segundoGrafo(char, char);
    string mostrar_grafo_segundoGrafo();
    string mostrar_aristas_segundoGrafo(char);
    string imprimir_nodos_segundoGrafo();
    bool verificarExistenciaNodoSegundoGrafo(char);
    bool verificarSegundoGrafoVacio();
private:
    Grafo* grafo;
    Grafo segundoGrafo;


};

#endif /* CONTROLLER_H */

