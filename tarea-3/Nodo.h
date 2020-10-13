#pragma once
class Nodo
{
private:
    int dato;       // dato
    Nodo* padre;    // nodo padre
    Nodo* der;      // hijo derecho
    Nodo* izq;      // hijo izquierdo
    int fe;         // factor de equilibrio

public:
    //CONSTRUCTORES
    Nodo();
    Nodo(int pdato, Nodo* ppadre, Nodo* der, Nodo* izq);
    Nodo(int pdato, Nodo* ppadre);
    Nodo(int pdato);

    //METODOS
    bool esHoja();
    bool esInteriorUnHijo();

    //GETTERS & SETTERS
    int getDato();
    void setDato(int info);
    Nodo* getPadre();
    void setPadre(Nodo* padre);
    Nodo* getDer();
    void setDer(Nodo*);
    Nodo* getIzq();
    void setIzq(Nodo*);
    int getFE();
    void setFE(int pfe);

    //METODOS MISCELANEOS
    void incrementarFE();
    void disminuirFE();

};

