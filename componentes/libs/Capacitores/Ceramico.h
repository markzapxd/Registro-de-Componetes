#ifndef CERAMICO_H
#define CERAMICO_H

#include "Capacitor.h"
#include <string>

class Ceramico : public Capacitor {
private:
    std::string dieletrico;
    dadosCSV dados;

public:
    Ceramico() {}

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
