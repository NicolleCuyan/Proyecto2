#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <chrono>
#include <sstream>
#include <vector>
#include "Datos.h"

Datos::Datos() {}

std::list<Datos> ListaDatos;

void Datos::CargaArchivo(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "ERROR....SE PRODUJO UN ERROR AL ABRIR EL ARCHIVO" << archivo << std::endl;
        std::cerr << "Asegurese de que la ruta del archivo sea correcta y que tenga permisos para leerlo." << std::endl;
        printFileError();
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();

    std::string line;
    while (getline(file, line)) {
        Datos datos;
        std::istringstream ss(line);
        std::string token;

        // Obtener la clave inicial
        getline(ss, datos.key, ',');

        // Obtener los valores intermedios
        while (getline(ss, token, ',')) {
            datos.evaluar.push_back(token);
        }

        // Asegurar que exista al menos un valor intermedio
        if (!datos.evaluar.empty()) {
            // La última entrada en evaluar es la siguiente clave
            datos.nextKey = datos.evaluar.back();
            datos.evaluar.pop_back(); // Remover nextKey de los valores
        }

        ListaDatos.push_back(datos);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    file.close();
    std::cout << "Datos cargados correctamente desde el archivo: " << archivo << std::endl;
    std::cout << "Duracion de la carga: " << duration.count() << " ms" << std::endl;
}

void Datos::BusquedaLlave(const std::string& llave) {
    auto it = std::find_if(ListaDatos.begin(), ListaDatos.end(), [&](const Datos& datos) {
        return datos.key == llave;
        });

    if (it != ListaDatos.end()) {
        std::cout << "Encontrado:\n";
        std::cout << "  Llave: " << it->key << std::endl;
        for (const auto& value : it->evaluar) {
            std::cout << "  Valor: " << value << std::endl;
        }
        std::cout << "  Siguiente Llave: " << it->nextKey << std::endl;
    }
    else {
        std::cout << "No se encontro la llave: " << llave << std::endl;
    }
}

void Datos::BusquedaValor(const std::string& valor) {
    bool found = false;

    for (const auto& datos : ListaDatos) {
        if (find(datos.evaluar.begin(), datos.evaluar.end(), valor) != datos.evaluar.end()) {
            std::cout << "Encontrado en la llave: " << datos.key << std::endl;
            std::cout << "  Valor: " << valor << std::endl;
            std::cout << "  Siguiente Llave: " << datos.nextKey << std::endl;
            found = true;
            break; // Salir del bucle después de encontrar el primer match
        }
    }

    if (!found) {
        std::cout << "No se encontro el valor: " << valor << std::endl;
    }
}

// Función para imprimir mensajes de error relacionados con el archivo
void Datos::printFileError() {
    std::cout << "Detalles del error al abrir el archivo:\n";
    perror("Error");
}
