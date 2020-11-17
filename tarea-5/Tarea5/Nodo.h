#pragma once
struct nodo {
    char nombre;//nombre del vertice o nodo
    struct nodo* sgte;
    struct arista* ady;//puntero hacia la primera arista del nodo
};
typedef struct nodo* Tnodo;//  Tipo Nodo
