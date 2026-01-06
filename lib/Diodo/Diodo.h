#ifndef DIODO_H
#define DIODO_H

using namespace std;

#include "../../include/dadosCSV.h"

class Diodo {
protected:
    string codigo;
    string tipoComponente;
    string modelo;
    string valor;

public:
    Diodo();
    virtual dadosCSV Cadastrar() = 0; 
    virtual dadosCSV Mostrar();
};

#endif
