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
void mostrarPreOrdenAVL();
void mostrarInOrdenAVL();
void mostrarPostOrdenAVL();
void insertarEnArbolB();
void ingresarOrdenArbolB();
void imprimirListaArbolB();
void imprimirPruebaArbolB();
void buscarEnArbolB();
void eliminarEnArbolB();
void insertarEnArbolBPlus();
void ingresarOrdenArbolBPlus();
void imprimirListaArbolBPlus();
void insertarEnArbolRojoNegro();
void imprimirListaArbolRojoNegro();
void eliminarEnArbolRojoNegro();
void mostrarPreOrdenArbolRojoNegro();
void mostrarInRodenArbolRojoNegro();
void mostrarPostOrdenArbolRojoNegro();
//GESTOR
static Gestor* gestor = new Gestor();

int main()
{
    int answer;
    bool keepLooping = true;

    system("CLS");
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
        system("CLS");

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

//MENÚ PRINCIPAL
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

//MENÚS PARA VARIACIONES DE ARBOLES

//1. Menú para árbol AVL 
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
        mostrarPreOrdenAVL();
        system("PAUSE");
        break;
    case 3:
        mostrarInOrdenAVL();
        system("PAUSE");
        break;
    case 4:
        mostrarPostOrdenAVL();
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

//2. Menú para árbol B 
void menuArbolB()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "ARBOL B" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento a arbol B." << endl;
        cout << "2. Imprimir lista de números agregados." << endl;
        cout << "3. Imprimir estado de arbol B." << endl;
        cout << "4. Buscar elemento en arbol B." << endl;
        cout << "5. Eliminar elemento del arbol B." << endl;
        cout << "6. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolBImp(answer);

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
        buscarEnArbolB();
        system("PAUSE");
        break;
    case 5:
        eliminarEnArbolB();
        system("PAUSE");
        break;
    case 6:
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

//3. Menú para árbol B 
void menuArbolBPlus()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "ARBOL B +" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento al arbol B+." << endl;
        cout << "2. Imprimir arbol B+." << endl;
        cout << "3. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolBPlusImp(answer);

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
        insertarEnArbolBPlus();
        break;
    case 2:
        imprimirListaArbolBPlus();
        system("PAUSE");
        break;
    case 3:
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

//4. Menú para árbol Rojo-Negro
void menuArbolRojoNegro()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "ARBOL ROJO-NEGRO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Agregar elemento a Arbol Rojo-Negro." << endl;
        cout << "2. Eliminar elemento del Arbol Rojo-Negro." << endl;
        cout << "3. Imprimir Arbol Rojo-Negro." << endl;
        cout << "4. Mostrar datos en preorden." << endl;
        cout << "5. Mostrar datos en inorden." << endl;
        cout << "6. Mostrar datos en postorden." << endl;
        cout << "7. Volver al menu principal." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuArbolRojoNegroImp(answer);

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
        insertarEnArbolRojoNegro();
        break;
    case 2:
        eliminarEnArbolRojoNegro();
        system("PAUSE");
        break;
    case 3:
        imprimirListaArbolRojoNegro();
        system("PAUSE");
        break;
    case 4:
        mostrarPreOrdenArbolRojoNegro();
        system("PAUSE");
        break;
    case 5:
        mostrarInRodenArbolRojoNegro();
        system("PAUSE");
        break;
    case 6:
        mostrarPostOrdenArbolRojoNegro();
        system("PAUSE");
        break;
    case 7:
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

//MÉTODOS PARA ÁRBOLES (GESTOR)

//1. Métodos para menú de árbol AVL
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

void mostrarPreOrdenAVL() {
    cout << gestor->mostrarPreOrdenAVL() << endl;
}

void mostrarInOrdenAVL() {
    cout << gestor->mostrarInOrdenAVL() << endl;
}

void mostrarPostOrdenAVL() {
    cout << gestor->mostrarPostOrdenAVL() << endl;
}

//2. Métodos para menú de árbol B
void insertarEnArbolB() {
    int input = -1;
    bool valid = false;

    if (gestor->validarOrdenArbol()) {
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
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Favor inserte un numero entero." << endl;
            }
        } while (!valid);

        cout << gestor->insertarElementoEnArbolB(input);
    }
    else {
        ingresarOrdenArbolB();
    }
}

void ingresarOrdenArbolB() {
    int orden = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite el orden del arbol B (entre 3 y 10): " << flush;
        cin >> orden;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Favor inserte un numero entero." << endl;
        }
    } while (orden < 3 || orden>10);
    gestor->insertarOrdenArbolB(orden);
}

void imprimirListaArbolB() {
    cout << gestor->imprimirDatosArbolB() << endl;
}
        
void imprimirPruebaArbolB() {
    cout << gestor->imprimirEstadoArbolB() << endl;
}

void buscarEnArbolB() {
    int input = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite un numero entero a buscar: " << flush;
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

    cout << gestor->buscarElementoEnArbolB(input) << endl;
}

void eliminarEnArbolB() {
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

    cout << gestor->eliminarElementoEnArbolB(input) << endl;
}

//3. Métodos para menú de árbol B+
void insertarEnArbolBPlus() {
    int input = -1;
    bool valid = false;

    if (gestor->validarOrdenArbolBPlus()) {
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
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Favor inserte un numero entero." << endl;
            }
        } while (!valid);

        cout << gestor->insertarElementoEnArbolBPlus(input);
    }
    else {
        ingresarOrdenArbolBPlus();
    }
}

void ingresarOrdenArbolBPlus() {
    int orden = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite el orden del arbol B + (entre 3 y 10): " << flush;
        cin >> orden;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Favor inserte un numero entero." << endl;
        }
    } while (orden < 3 || orden>10);
    gestor->insertarOrdenArbolBPlus(orden);
}

void imprimirListaArbolBPlus() {
    if (gestor->validarOrdenArbolBPlus()) {
      gestor->imprimirDatosArbolBPlus();
    }
    else {
        ingresarOrdenArbolBPlus();
    }
}

//4. Metodos para menu de Arbol Rojo y Negro

void insertarEnArbolRojoNegro() {
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

    cout << gestor->insertarEnRN(input) << endl;
}

void imprimirListaArbolRojoNegro()
{
    gestor->imprimirRN();

}

void eliminarEnArbolRojoNegro()
{
    int input = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite un numero entero a eliminar: " << flush;
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

    cout << gestor->eliminarEnRN(input) << endl;
}

void mostrarPreOrdenArbolRojoNegro()
{
    gestor->mostrarPreOrdenRN();
}

void mostrarInRodenArbolRojoNegro()
{
    gestor->mostrarInOrdenRN();
}

void mostrarPostOrdenArbolRojoNegro()
{
    gestor->mostrarPostOrdenRN();
}
