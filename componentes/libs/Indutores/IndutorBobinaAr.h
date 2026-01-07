#ifndef INDUTORBOBINAAR_H
#define INDUTORBOBINAAR_H

#include "Indutor.h"
#include "Entrada.h"
#include "UnidadeIndutancia.h"

class IndutorBobinaAr : public Indutor {
private:
    std::string codigo;
    double valorH;
    std::string espiras;
    std::string diametroFio;
    std::string comprimento;

    std::string lerCodigo();
    double lerIndutancia();
    DadosCSV montarCSV();

public:
    DadosCSV cadastrar() override;
    DadosCSV mostrar() override;
};

#endif
