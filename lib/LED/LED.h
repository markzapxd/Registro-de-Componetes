#ifndef LED_H
#define LED_H

#include "../Diodo/Diodo.h"

class LED : public Diodo {
private:
    string cor;
    string correnteMax;
    string tensaoVf;

public:
    LED();
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
