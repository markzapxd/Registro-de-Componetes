#ifndef INDUTORTOROIDAL_H
#define INDUTORTOROIDAL_H

#include "Indutor.h"
#include "Entrada.h"
#include "UnidadeIndutancia.h"

class IndutorToroidal : public Indutor {
private:
    std::string codigo;
    double valorH;
    std::string material;
    std::string diametro;
    std::string corrente;

    std::string lerCodigo();
    double lerIndutancia();
    DadosCSV montarCSV();

public:
    DadosCSV cadastrar() override;
    DadosCSV mostrar() override;
};

#endif
