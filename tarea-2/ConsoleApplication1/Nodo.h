#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
    int dato;
    Nodo* der;
    Nodo* izq;

public:
    //CONSTRUCTORES
    Nodo();
    Nodo(int, Nodo* der, Nodo* izq);
    Nodo(int);

    //METODOS
    bool esHoja();
    bool esInteriorUnHijo();

    //GETTERS & SETTERS
    int getDato() const;
    void setDato(int info);
    Nodo* getDer() const;
    void setDer(Nodo*);
    Nodo* getIzq() const;
    void setIzq(Nodo*);

};

#endif