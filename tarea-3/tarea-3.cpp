/*
    TAREA 03: 
    1. Realizar la implementación de un árbol AVL en el cual se pueda agregar balanceado y recorrer con los tres tipos de recorrido.
    2. Inserte los siguientes valores en un árbol AVL: 7, 14, 28, 5, 9, 8, 21, 3, 15, 24, 100 y 1
    
    ESTUDIANTES:
    Gabriel Calvo
    David Solano
    Monica Zuniga
*/


#include <iostream>
#include <iomanip>
#include <string>
#include "Gestor.h"

using namespace std;

//PROTOTIPO DE FUNCIONES
int menu(int answer);
void insertarValoresDefault();
void insertarEnAVL();
void mostrarPreOrden();
void mostrarInOrden();
void mostrarPostOrden();

//VARIABLES ESTATICAS
static Gestor* gestor = new Gestor();

int main()
{
    int answer;
    bool keepLooping = true;

    do
    {
        system("CLS");
        cout << "-------------------------------------" << endl;
        cout << "Favor digite un numero del menu:" << endl;
        cout << "1. Insertar dato en arbol AVL (AVL)." << endl;
        cout << "2. Agregar datos 7, 14, 28, 5, 9, 8, 21, 3, 15, 24, 100 y 1" << endl;
        cout << "3. Mostrar datos en preorden." << endl;
        cout << "4. Mostrar datos en inorden." << endl;
        cout << "5. Mostrar datos en postorden." << endl; 
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;
        system("CLS");

        menu(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }

    } while (keepLooping);
}

//MENU PRINCIPAL

int menu(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnAVL();
        break;
    case 2:
        insertarValoresDefault();
        system("PAUSE");
        break;
    case 3:
        mostrarPreOrden();
        system("PAUSE");
        break;
    case 4:
        mostrarInOrden();
        system("PAUSE");
        break;
    case 5:
        mostrarPostOrden();
        system("PAUSE");
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//FUNCIONES DEL MENU


void insertarValoresDefault() {

    gestor->insertarEnABB(7);
    gestor->insertarEnABB(14);
    gestor->insertarEnABB(28);
    gestor->insertarEnABB(5);
    gestor->insertarEnABB(9);
    gestor->insertarEnABB(8);
    gestor->insertarEnABB(21);
    gestor->insertarEnABB(3);
    gestor->insertarEnABB(15);
    gestor->insertarEnABB(24);
    gestor->insertarEnABB(100);
    gestor->insertarEnABB(1);

    cout << "Valores insertados correctamente!" << endl;
}

void insertarEnAVL() {
    int input = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite un numero entero a agregar: " << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Favor inserte un numero entero." << endl;
        }
    } while (!valid);

    cout << gestor->insertarEnABB(input) << endl;
}

void mostrarPreOrden() {
    cout << gestor->mostrarPreOrden() << endl;
}

void mostrarInOrden() {
    cout << gestor->mostrarInOrden() << endl;
}

void mostrarPostOrden() {
    cout << gestor->mostrarPostOrden() << endl;
}
