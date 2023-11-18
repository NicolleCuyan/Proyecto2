#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include"Datos.h"

class Datos
{

public:

    Datos();

    std::string key;
    std::string nextKey;
    std::vector<std::string> evaluar; 

    void CargaArchivo(const std::string& archivo);
    void BusquedaLlave(const std::string& llave);
    void BusquedaValor(const std::string& valor);
    void printFileError();

private:
    std::list<Datos> ListaDatos;
};
