#pragma once
struct aristaMultiple {
    struct nodoMultiple* destino;//puntero al nodo de llegada
    struct nodoMultiple* predecesor;//puntero al nodo predecesor
    int valor;//valor del arco
    struct aristaMultiple* sgte;
};

typedef struct aristaMultiple* TaristaMultiple; //Tipo Arista