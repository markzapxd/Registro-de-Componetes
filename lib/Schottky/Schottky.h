#ifndef SCHOTTKY_H
#define SCHOTTKY_H

#include "../Diodo/Diodo.h"
class Schottky : public Diodo {
private:
   string tensaoVf;
   string correnteMax;
   string velocidadeComutacao;

public:
    Schottky();
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() override;
};

#endif
