#ifndef INDUTORFERRITE_H
#define INDUTORFERRITE_H

#include "Indutor.h"
#include "Entrada.h"
#include "UnidadeIndutancia.h"

class IndutorFerrite : public Indutor {
private:
    std::string codigo;
    double valorH;
    std::string tipoFerrite;
    std::string permeabilidade;
    std::string correnteSat;

    std::string lerCodigo();
    double lerIndutancia();
    DadosCSV montarCSV();

public:
    DadosCSV cadastrar() override;
    DadosCSV mostrar() override;
};

#endif
