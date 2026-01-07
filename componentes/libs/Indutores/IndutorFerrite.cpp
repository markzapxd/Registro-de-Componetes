#include "IndutorFerrite.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

std::string IndutorFerrite::lerCodigo() {
    Entrada entrada("Codigo: ");
    std::string CodigoRegistro;
    do CodigoRegistro = entrada.ler(); while (CodigoRegistro.empty());
    return CodigoRegistro;
}

double IndutorFerrite::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        std::cout << "Valor invalido.\n";
    }
}


DadosCSV IndutorFerrite::montarCSV() {
    UnidadeIndutancia unidade;
    return DadosCSV(
        codigo, "Indutor", "Ferrite",
        unidade.formatar(valorH),
        tipoFerrite, permeabilidade, correnteSat
    );
}

DadosCSV IndutorFerrite::cadastrar() {
    codigo = lerCodigo();
    valorH = lerIndutancia();
    const std::vector<std::string> permitidos = {"Duro", "Macio", "Ferrite"};
    tipoFerrite = solicitarMaterial("Tipo de ferrite (Duro/Macio): ", permitidos);

    double ValorPermeabilidade = solicitarDoubleRange("Permeabilidade relativa (k): ", 10.0, 20000.0);
    permeabilidade = std::to_string(ValorPermeabilidade);

    double Corrente = solicitarDoubleRange("Corrente de saturacao (A): ", 0.01, 100.0);
    correnteSat = std::to_string(Corrente);
    return montarCSV();
}

DadosCSV IndutorFerrite::mostrar() {
    return montarCSV();
}
