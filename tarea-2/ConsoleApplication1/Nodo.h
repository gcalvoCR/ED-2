#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
    //CONSTRUCTORES
    Nodo();
    Nodo(int, Nodo* der, Nodo* izq);
    Nodo(int);

    //GETTERS & SETTERS
    int getDato() const;
    void setDato(int info);
    Nodo* getDer() const;
    void setDer(Nodo*);
    Nodo* getIzq() const;
    void setIzq(Nodo*);

protected:
    int dato;
    Nodo* der;
    Nodo* izq;
};

#endif