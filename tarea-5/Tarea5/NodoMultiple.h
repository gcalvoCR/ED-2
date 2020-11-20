#pragma once
struct nodoMultiple {
    char nombre;//nombre del vertice o nodo
    int valor;//valor del vertice o nodo
    struct nodoMultiple* sgte;
    struct aristaMultiple* pdr;//puntero hacia la primera arista del nodo
    struct aristaMultiple* scr;//puntero hacia la primera arista del nodo

};
typedef struct nodoMultiple* TnodoMultiple;//  Tipo Nodo
