#ifndef ARBOLBPLUS
#define ARBOLBPLUS
#include <string>
#include "Datos.h"
using namespace std;

class ArbolBPlus {
    NodoBPlus* raiz;
    NodoBPlus* principio;
    NodoBPlus* final;
    int orden;

public:
    ArbolBPlus();
    ArbolBPlus(int o);
    Info buscar(int k);
    bool agregar(int k);
    void imprimirArbol();
    //GETTERS & SETTERS
    int getOrden();
    void setOrden(int);

protected:

    NodoBPlus* buscar_hoja(NodoBPlus* n, int k);
    void agregar_en_nodo_lleno(NodoBPlus* n, int k, int i, Registro* r);
    void agregar_en_nodo_no_lleno(NodoBPlus* n, int k, int i, Registro* r);
    bool agregar_y_partir_hoja(NodoBPlus* n, int k, int i, Registro* r, NodoBPlus*& n_s, int& k_s);
    bool agregar_y_partir_intermedio(NodoBPlus* n, NodoBPlus*& n_s, int& k_s);
    void agregar_y_partir_raiz(NodoBPlus* n, int k, int i, Registro* r);
    void inicializar();
};

#endif

//----------------------------------------------------------------------------------------------------------

#ifndef METODOS_HOJA
#define METODOS_HOJA

#include <iostream>
#include <string>

Registro* crearRegistro(int k);

bool nodo_lleno(NodoBPlus* n);

int buscar_hijo_en_nodo(NodoBPlus* n, int k);
int buscar_llave_en_nodo(NodoBPlus* n, int k);

void desplazar_en_hoja_a_la_derecha(NodoBPlus* n, int desde, int hasta, int e);
void desplazar_en_intermedio_a_la_derecha(NodoBPlus* n, int desde, int hasta, int e);

void copiar_hoja(NodoBPlus* origen, NodoBPlus* destino, int desde, int hasta, int e);
void copiar_intermedio(NodoBPlus* origen, NodoBPlus* destino, int desde, int hasta, int e);

void imprimirNodo(NodoBPlus* n);
void imprimirNivel(NodoBPlus* n);

#endif
