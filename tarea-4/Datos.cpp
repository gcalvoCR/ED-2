#include "Datos.h"
#include <iostream>
int NodoBPlus::max_llaves;

// Constructor info
Info::Info() {
    encontrado = false;
    donde = NULL;
    indice = -1;
}

// Construccion nodo
NodoBPlus::NodoBPlus()
{
    cuantas_llaves = 0;
    es_hoja = true;
    padre = siguiente = anterior = NULL;
}

NodoBPlus::NodoBPlus(int o)
{
    cuantas_llaves = 0;
    es_hoja = true;
    padre = siguiente = anterior = NULL;
    max_llaves = o;
}