#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Grafo.h"
#include "GrafoMultiple.h"
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
    //1. M�todos para primer grafo (matriz de adyacencia)
    bool insertarVerticeEnArreglo(int, int);
    string agregarArcoEnMatriz(int, int, int);
    int buscarVertice(int);
    int buscarEtiqueta(int, int);
    string mostrarVertices();
    string mostrarEtiquetas();
    //2. M�todos para segundo grafo (lista de adyacencia)
    string insertar_nodo_segundoGrafo(char);
    string insertar_arista_segundoGrafo(char, char);
    string eliminar_nodo_segundoGrafo(char);
    string eliminar_arista_segundoGrafo(char, char);
    string mostrar_grafo_segundoGrafo();
    string mostrar_aristas_segundoGrafo(char);
    string imprimir_nodos_segundoGrafo();
    bool verificarExistenciaNodoSegundoGrafo(char);
    bool verificarSegundoGrafoVacio();
    //3. M�todos para lista multiple de adyacencia
    string insertar_nodo_multiple(char, int);
    string insertar_arista_multiple(char, char, int);
    string mostrar_grafo_multiple();
private:
    Grafo* grafo;
    Grafo segundoGrafo;
    GrafoMultiple grafoMult;
};

#endif /* CONTROLLER_H */

