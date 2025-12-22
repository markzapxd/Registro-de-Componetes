#ifndef ELETROLITICO_H
#define ELETROLITICO_H

#include "Capacitor.h"
#include <string>

class Eletrolitico : public Capacitor {
private:
    bool polarizado;

public:
    Eletrolitico() : polarizado(false) {}

    void Cadastrar() override;
    void Exibir() const override;
};

#endif
