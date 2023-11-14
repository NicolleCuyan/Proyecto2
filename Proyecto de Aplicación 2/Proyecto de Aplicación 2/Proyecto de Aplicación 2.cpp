// Proyecto de Aplicación 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


string cargar() {

    /*int j = (archivo[i] + 1) % n;
    do {
        if (archivo[j] == 0) {
            llave[j] = llave[j];
            archivo[j] = 1;
        }
        else {
            j++;
        }
    } while (j > n);

    return j;*/

    return "hola";

}

string BusquedaLlave() {

    
    /*int j = 0;

    while (j > n) {
        if (archivo[j] == llave) {
            return j; 
        }
        else {
            j++;
        }
    }

    return -1; */

    return "hola";
}

string BusquedaValor() {
    
    return "hola";

}


int main()
{
    // PROYECTO

    string archivoBuscar; 

    cout << "Ingrese el nombre del archivo: ";
    cin >> archivoBuscar;
    cout << "";

    ifstream archivo(archivoBuscar);

    if (!archivo.is_open()) {
        cerr << "ERROR...SE PRODUJO UN ERROR AL ABRIR EL ARCHIVO" << endl; 
        return 1; 
    }

    string linea; 

    while (getline(archivo, linea)) {
        size_t pos = linea.find(",");
        if (pos != std::string::npos) {
            string llave = linea.substr(0, pos);
            string datos = linea.substr(pos + 1);

        }
    }

    archivo.close(); 

    int opcion;
    string llave; 
    list<string> BusquedaKey;
    list<string> BusquedaVal;

    do {

        cout << "-------------------- MENU -------------------- \n";
        cout << "1) Cargar mas datos a memoria. \n";
        cout << "2) Busqueda de datos por llave. \n";
        cout << "3) Busqueda de datos por valor. \n"; 
        cout << "4) Salir \n";
        cout << "---------------------------------------------- \n";
        cout << "Ingrese una de las opciones: "; 
        cin >> opcion; 

        cout << "\n";

        switch (opcion){
        case 1: 

            system("cls");
            cout << "CARGAR DATOS A MEMORIA";



            break;
        case 2: 

            system("cls");

            cout << "BUSQUEDA DE DATOS POR LLAVE" << endl;



            cout << "Ingrese la llave que desea buscar: ";
            cin >> llave; 
            if (llave == "hola") {
                cout << "" << endl; 
            }
            else {
                cout << "LA LLAVE BUSCADA NO EXISTE" << endl; 
            }

            /*int op = 0, n, llave, x;

            cout << "Ingrese la llave que desea buscar: ";
            cin >> llave; 

            int x, n; 
            int* archivo; 

            x = BusquedaLlave(archivo, n, llave);

            if (x == -1) {
                cout << "No se encontro ninguna llave" << endl; 
            }
            else {
                cout << "Llave encontrada: " << x << endl; 
            }*/

                break;
        case 3: 

            system("cls");
            cout << "BUSQUEDA DE DATOS POR VALOR";



            break;

        case 4: 

            system("cls");
            cout << "SALIENDO DEL PROGRAMA...";
            break; 

        default: 
            
            system("cls"); 
            cout << "Opción no válida. Por favor, selecciona una opción válida.";
            break; 

        }

        std::cout <<" " << std::endl;

    } while (opcion != 4);

    return 0; 
        
}

