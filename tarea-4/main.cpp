// Tarea grupal: variaciones de listas
#include <iostream>
#include <iomanip>
#include <string>
#include "Gestor.h"

using namespace std;

//PROTOTIPO DE MENUS
int menuPrincipal(int answer);
void menuArbolAVL();
int menuArbolAVLImp(int answer);
void menuArbolB();
int menuArbolBImp(int answer);
void menuArbolBPlus();
int menuArbolBPlusImp(int answer);
void menuArbolRojoNegro();
int menuArbolRojoNegroImp(int answer);
//PROTOTIPO DE METODOS 
void insertarEnAVL();
void mostrarPreOrden();
void mostrarInOrden();
void mostrarPostOrden();
//GESTOR
static Gestor* gestor = new Gestor();

int main()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una variacion de arbol:" << endl;
        cout << "1. Arbol AVL." << endl;
        cout << "2. Arbol B." << endl;
        cout << "3. Arbol B+." << endl;
        cout << "4. Arbol Rojo-Negro." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuPrincipal(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);

}

//MEN� PRINCIPAL
int menuPrincipal(int answer)
{
    switch (answer)
    {
    case 1:
        menuArbolAVL();
        break;
    case 2:
        menuArbolB();
        break;
    case 3:
        menuArbolBPlus();
        break;
    case 4:
        menuArbolRojoNegro();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//---------------------------------------------------------------------------------------

//MEN�S PARA VARIACIONES DE ARBOLES

//1. Men� para �rbol AVL 
void menuArbolAVL()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "ARBOL AVL" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Insertar dato en arbol AVL (AVL)." << endl;
        cout << "2. Mostrar datos en preorden." << endl;
        cout << "3. Mostrar datos en inorden." << endl;
        cout << "4. Mostrar datos en postorden." << endl;
        cout << "5. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolAVLImp(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuArbolAVLImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnAVL();
        break;
    case 2:
        mostrarPreOrden();
        system("PAUSE");
        break;
    case 3:
        mostrarInOrden();
        system("PAUSE");
        break;
    case 4:
        mostrarPostOrden();
        system("PAUSE");
        break;
    case 5:
        main();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//2. Men� para �rbol B 
void menuArbolB()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "�RBOL B" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento a �rbol B." << endl;
        cout << "2. Imprimir lista de n�meros agregados." << endl;
        cout << "3. Imprimir prueba de �rbol B." << endl;
        cout << "4. liminar elemento del �rbol B." << endl;
        cout << "5. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolAVLImp(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuArbolBImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnArbolB();
        break;
    case 2:
        imprimirListaArbolB();
        system("PAUSE");
        break;
    case 3:
        imprimirPruebaArbolB();
        system("PAUSE");
        break;
    case 4:
        eliminarEnArbolB();
        system("PAUSE");
        break;
    case 5:
        main();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//3. Men� para �rbol B 
void menuArbolBPlus()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "�RBOL B" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento a �rbol B." << endl;
        cout << "2. Imprimir lista de n�meros agregados." << endl;
        cout << "3. Imprimir prueba de �rbol B." << endl;
        cout << "4. liminar elemento del �rbol B." << endl;
        cout << "5. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolAVLImp(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuArbolBPlusImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnArbolB();
        break;
    case 2:
        imprimirListaArbolB();
        system("PAUSE");
        break;
    case 3:
        imprimirPruebaArbolB();
        system("PAUSE");
        break;
    case 4:
        eliminarEnArbolB();
        system("PAUSE");
        break;
    case 5:
        main();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//4. Men� para �rbol Rojo-Negro
void menuArbolRojoNegro()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "�RBOL B" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento a �rbol B." << endl;
        cout << "2. Imprimir lista de n�meros agregados." << endl;
        cout << "3. Imprimir prueba de �rbol B." << endl;
        cout << "4. liminar elemento del �rbol B." << endl;
        cout << "5. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolAVLImp(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuArbolRojoNegroImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnArbolB();
        break;
    case 2:
        imprimirListaArbolB();
        system("PAUSE");
        break;
    case 3:
        imprimirPruebaArbolB();
        system("PAUSE");
        break;
    case 4:
        eliminarEnArbolB();
        system("PAUSE");
        break;
    case 5:
        main();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}


//---------------------------------------------------------------------------------------

//M�TODOS PARA �RBOLES (GESTOR)

//1. M�todos para men� de �rbol AVL
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

    cout << gestor->insertarEnAVL(input) << endl;
}

void mostrarPreOrden() {
    cout << gestor->mostrarPreOrdenAVL() << endl;
}

void mostrarInOrden() {
    cout << gestor->mostrarInOrdenAVL() << endl;
}

void mostrarPostOrden() {
    cout << gestor->mostrarPostOrdenAVL() << endl;
}

//2. M�todos para men� de �rbol B
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

    cout << gestor->insertarEnAVL(input) << endl;
}

void mostrarPreOrden() {
    cout << gestor->mostrarPreOrdenAVL() << endl;
}

void mostrarInOrden() {
    cout << gestor->mostrarInOrdenAVL() << endl;
}

void mostrarPostOrden() {
    cout << gestor->mostrarPostOrdenAVL() << endl;
}

//3. M�todos para men� de �rbol B


//4. Metodos para menu de bicola

