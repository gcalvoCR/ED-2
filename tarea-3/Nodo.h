#pragma once
class Nodo
{
private:
    int dato;
    Nodo* padre;
    Nodo* der;
    Nodo* izq;
    int fe;  //factor de equilibrio

public:
    //CONSTRUCTORES
    Nodo();
    Nodo(int, Nodo* der, Nodo* izq);
    Nodo(int);

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
    int getFactorEquilibrio();
    void setFactorEquilibrio(int pfe);

    void incrementarFE();
    void disminuirFE();

};

