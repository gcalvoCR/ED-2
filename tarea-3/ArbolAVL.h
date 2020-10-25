#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class ArbolAVL
{
private:
    enum {IZQUIERDO, DERECHO};
    Nodo* raiz;
    Nodo* actual;
    int altura;
    string PreOrdenRecursivo(Nodo*);
    string InOrdenRecursivo(Nodo*);
    string PostOrdenRecursivo(Nodo*);

    int max(int a, int b);

    //Funciones para equilibrado
    void equilibrar(Nodo*, int, bool);
    void rotacionSimpleDerecha(Nodo*);
    void rotacionSimpleIzquierda(Nodo*);
    void rotacionDobleDerecha(Nodo*);
    void rotacionDobleIzquierda(Nodo*);

public:
    //CONSTRUCTOR
    ArbolAVL();

    //METODOS
    bool insertarDato(int);// Insertar en arbol
    bool buscarPI(Nodo* nodo, int pDato);
    bool estaVacio();
    bool estaVacio(Nodo* r) { return r == NULL; }
    bool borrar(int pdato);
    bool buscar(Nodo* nodo,int pdato);
    bool buscarEnAVL(int pDato);
    bool esHoja(Nodo* pnodo);
    int numeroNodos();
    int alturaArbol();

    //Mostrar datos en pre-in-post-orden,buscarAVL Y EliminarAVL
    string preOrden();
    string inOrden();
    string postOrden();



    //GETTERS & SETTERS
    Nodo* getRaiz();
    void setRaiz(Nodo*);

    Nodo* getActual();
    void setActual(Nodo* actual);

    int getAltura();
    void setAltura(int altura);

};

