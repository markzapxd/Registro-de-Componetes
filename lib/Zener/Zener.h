#ifndef ZENER_H
#define ZENER_H

#include "../Diodo/Diodo.h"

class Zener : public Diodo {
private:
    string tensaoRuptura;
    string potencia;
    string tolerancia;

public:
    Zener();
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
