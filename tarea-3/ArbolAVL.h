#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class ArbolAVL
{
private:
    //atributos
    enum {IZQUIERDO, DERECHO};
    Nodo* raiz;

    //GETTERS & SETTERS
    Nodo* getRaiz();
    void setRaiz(Nodo*);

    //Metodo recursivo para buscar e insertar
    bool buscarEinsertarOrdenado(Nodo* nodo, int pDato);

    //recorridos
    string PreOrdenRecursivo(Nodo*);
    string InOrdenRecursivo(Nodo*);
    string PostOrdenRecursivo(Nodo*);

    //Funciones para equilibrado
    void equilibrar(Nodo*, int, bool);
    void rotacionSimpleDerecha(Nodo*);
    void rotacionSimpleIzquierda(Nodo*);
    void rotacionDobleDerecha(Nodo*);
    void rotacionDobleIzquierda(Nodo*);

public:
    //CONSTRUCTOR
    ArbolAVL();
    ~ArbolAVL();

    //METODOS
    bool insertarElem(int pdato);   // Insertar en arbol
    bool eliminarElem(int pdato);   // elimina el dato
    int peso();                     // numero de elementos
    bool esHoja(Nodo* pnodo);       // verifica si elemento es hoja
    int numHojas();                 // devuelve el numero de hojas
    bool estaVacio();               // verifica si el arbol esta vacio
    void borrar(int pdato);         // borra elemento
    bool buscar(int pdato);         // busca elemento en el arbol 
    int altura();                   // devuelve la altura del arbol

    //Mostrar datos en pre-in-post-orden
    string preOrden();
    string inOrden();
    string postOrden();

};

