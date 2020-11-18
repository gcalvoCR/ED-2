#pragma once
struct arista {
    struct nodo* destino;//puntero al nodo de llegada
    struct arista* sgte;
};

typedef struct arista* Tarista; //Tipo Arista