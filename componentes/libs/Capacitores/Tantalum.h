#ifndef TANTALUM_H
#define TANTALUM_H

#include "Capacitor.h"
#include <string>

class Tantalum : public Capacitor {
private:
    std::string encapsulamento;
    dadosCSV dados;

public:
    Tantalum() {}

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
