// Proyecto de Aplicación 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include"Datos.h"

using namespace std;

void Verificar(string archivo) {
    // Verifica si el archivo existe antes de intentar abrirlo
    ifstream testFile(archivo);
    if (!testFile.good()) {
        cerr << "El archivo no existe o no se puede acceder." << endl;
        testFile.close();
        return; 
    }
    testFile.close();
}

int main()
{
    // PROYECTO

    Datos datos; 

    string archivo;

    cout << "Ingrese la ruta del archivo que desea utilizar (por ejemplo, C:\\ruta\\del\\archivo.txt): ";
    cin >> archivo;
    cout << endl;

    ifstream testFile(archivo);
    if (!testFile.good()) {
        cerr << "El archivo no existe o no se puede acceder." << endl;
        testFile.close();
        return 1;
    }
    testFile.close();

    datos.CargaArchivo(archivo);

    int opcion;
    string valorBusqueda;
    string claveBusqueda;

    do {

        cout << " -------------------- MENU -------------------- \n";
        cout << "| 1) Cargar datos a memoria.                   |\n";
        cout << "| 2) Busqueda de datos por llave.              |\n";
        cout << "| 3) Busqueda de datos por valor.              |\n";
        cout << "| 4) Salir                                     |\n";
        cout << " ---------------------------------------------- \n";
        cout << "Ingrese una de las opciones: "; 
        cin >> opcion; 

        cout << "\n";

        string llave; 
        string valor; 

        switch (opcion){
        case 1: 

            system("cls");

            cout << "CARGAR DATOS A MEMORIA" << endl; 

            cout << endl; 

            cout << "Ingrese la ruta o nombre del nuevo archivo: ";
            cin >> archivo;
            
            Verificar(archivo);

            datos.CargaArchivo(archivo);

            break; 

        case 2: 

            system("cls");

            // Buscar datos por key

            cout << "BUSCAR DATOS POR LLAVE" << endl;

            cout << endl;

            cout << "BUSQUEDA DE DATOS POR LLAVE" << endl;

            cout << "Ingrese la llave a buscar: ";
            cin >> llave; 

            datos.BusquedaLlave(llave);
            
            break;

        case 3: 

            system("cls");

            cout << "BUSQUEDA DE DATOS POR VALOR" << endl; 

            cout << endl;

            cout << "Ingrese el valor a buscar: ";
            cin >> valor; 
            datos.BusquedaValor(valor);

            break;

        case 4: 

            system("cls");

            cout << endl; 

            cout << "SALIENDO DEL PROGRAMA...";
            break; 

        default: 
            
            system("cls"); 
            cout << "Opción no válida. Por favor, selecciona una opción válida.";
            break; 

        }

        std::cout << std::endl;

    } while (opcion != 4);

    return 0; 
        
}

