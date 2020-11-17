//A.Programar la simulación de dos grafos(solamente agregar y mostrar).
//
//1. Primer grafo : Este se debe realizar mediante una matriz de adyacencia en la cual se agregarán 8 vertices y arcos según lo decida el usuario.
//
//2. Segundo grafo : Este se debe realizar mediante una lista de adyacencia en la cual se agregarán los vertices y arcos según lo decida el usuario.
//
//B.Programar la simulación de una lista encadenada múltiple de adyacencia(solamente agregar y mostrar)

#include <cstdlib>

#include "Controller.h"

Controller controller;
void mostrarMenu();
int leerOpcion();
void ejecutarAccion(int);
void insertarVertice();
void mostrarVertices();
void insertarArco();
void mostrarEtiquetas();

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int opc;
    do {
        mostrarMenu();
        opc = leerOpcion();
        ejecutarAccion(opc);

    } while (opc != 0);

    return 0;
}

void mostrarMenu() {

    system("CLS");
    cout << "---- Ejercicio usando matrices de adyacencia ----" << endl;
    cout << " "<< endl;
    cout << "Favor digite la opcion que desea insertar:" << endl;
    cout << "1. Insertar vertices (8 numeros positivos)" << endl;
    cout << "2. Mostrar vertices" << endl;
    cout << "3. Insertar informacion de arco (peso) " << endl;
    cout << "4. Mostrar informacion de arcos (pesos)" << endl;
    cout << "0. Salir del sistema." << endl;
    cout << "------------------------------------------------" << endl;

}

int leerOpcion() {

    int opcion;
    cin >> opcion;
    return opcion;
}

void ejecutarAccion(int pOpcion) {

    switch (pOpcion) {

    case 1:
        insertarVertice();
        system("PAUSE");
        break;
    case 2:
        mostrarVertices();
        system("PAUSE");
        break;
    case 3:
        insertarArco();
        system("PAUSE");
        break;
    case 4:
        mostrarEtiquetas();
        system("PAUSE");
        break;
    case 0:
        cout << "Cerrando aplicación";
        break;
    default:
        cout << "OPCION INVALIDA";
    }
}

void insertarVertice() {
    int numero;

    for (int i = 0; i < 8; i++) {
        bool bandera = true;
        do {
            cout << "Digitar numero #" << i << ": ";
            cin >> numero;
            if (controller.insertarVerticeEnArreglo(i, numero)) {
                cout << "Numero agregado\n";
                bandera = false;
            }
            else {
                cout << "El numero ya existe, agregar otro\n";
            }
        } while (bandera);

    }
}

void mostrarVertices() {
    cout << controller.mostrarVertices();
}

void insertarArco() {
    int numero, numero2, peso;
    cout << "Digitar el 1er numero: ";
    cin >> numero;
    cout << "Digitar el 2ndo numero: ";
    cin >> numero2;
    cout << "Peso entre el 1er y 2ndo numero: ";
    cin >> peso;
    cout << controller.agregarArcoEnMatriz(controller.buscarVertice(numero), controller.buscarVertice(numero2), peso);

}

void mostrarEtiquetas() {
    cout << controller.mostrarEtiquetas();
}