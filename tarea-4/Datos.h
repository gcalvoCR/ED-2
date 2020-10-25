#ifndef DATOS_H_
#define DATOS_H_

struct Registro {
    int valor;
};

struct NodoBPlus
{
    NodoBPlus* padre;
    NodoBPlus* siguiente;
    NodoBPlus* anterior;

    static int max_llaves;

    //Numero de llaves del nodo
    int  cuantas_llaves;

    bool es_hoja;

    //Posiciones llaves
    int* llaves;
    struct {
        Registro** datos;
        NodoBPlus** hijos;
    };

    NodoBPlus();
    NodoBPlus(int o);
};

struct Info
{
    bool encontrado;
    NodoBPlus* donde;
    int indice;

    Info();
};

#endif