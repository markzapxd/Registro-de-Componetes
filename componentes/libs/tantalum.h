#ifndef TANTALUM_H
#define TANTALUM_H

#include "Capacitor.h"
#include <string>

class Tantalum : public Capacitor {
private:
    std::string encapsulamento;

public:
    Tantalum() {}

    void Cadastrar() override;
    void Exibir() const override;
};

#endif
