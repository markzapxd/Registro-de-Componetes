#ifndef CERAMICO_H
#define CERAMICO_H

#include "Capacitor.h"
#include <string>

class Ceramico : public Capacitor {
private:
    std::string dieletrico;

public:
    Ceramico() {}

    void Cadastrar() override;
    void Exibir() const override;
};

#endif
