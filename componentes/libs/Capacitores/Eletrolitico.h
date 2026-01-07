#ifndef ELETROLITICO_H
#define ELETROLITICO_H

#include "Capacitor.h"
#include <string>

class Eletrolitico : public Capacitor {
private:
    bool polarizado;
    dadosCSV dados;

public:
    Eletrolitico() : polarizado(false) {}

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
