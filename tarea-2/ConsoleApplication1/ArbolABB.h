#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class ArbolABB
{
private:
    //Atributos
    Nodo* raiz;
    int altura;

    //GETTERS & SETTERS
    Nodo* getRaiz();
    void setRaiz(Nodo*);
    int getAltura();
    void setAltura(int paltura);

    bool buscarEinsertarOrdenado(Nodo* nodo, int pdato);
    string PreOrdenRecursivo(Nodo*);
    string InOrdenRecursivo(Nodo*);
    string PostOrdenRecursivo(Nodo*);

public:
    //CONSTRUCTORA
    ArbolABB();

    //METODOS
    //Insertar en árbol ordenado
    bool insertarElem(int pdato);
    bool estaVacio();

    // Recorridos
    string preOrden();
    string inOrden();
    string postOrden();

};

#endif