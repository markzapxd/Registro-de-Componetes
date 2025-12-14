#include "IndutorToroidal.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

std::string IndutorToroidal::lerCodigo() {
    Entrada entrada("Codigo: ");
    std::string CodigoRegistro;
    do CodigoRegistro = entrada.ler(); while (CodigoRegistro.empty());
    return CodigoRegistro;
}

double IndutorToroidal::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        std::cout << "Valor invalido.\n";
    }
}


DadosCSV IndutorToroidal::montarCSV() {
    UnidadeIndutancia unidade;
    return DadosCSV(
        codigo, "Indutor", "Toroidal",
        unidade.formatar(valorH),
        material, diametro, corrente
    );
}

DadosCSV IndutorToroidal::cadastrar() {
    codigo = lerCodigo();
    valorH = lerIndutancia();
    const std::vector<std::string> permitidos = {"Ferrite", "Pó de ferro", "Ar"};
    material = solicitarMaterial("Material do nucleo (Ferrite/Pó de ferro/Ar): ", permitidos);

    double d = solicitarDoubleRange("Diametro (mm): ", 1.0, 200.0);
    diametro = std::to_string(d);

    double i = solicitarDoubleRange("Corrente maxima (A): ", 0.01, 100.0);
    corrente = std::to_string(i);
    return montarCSV();
}

DadosCSV IndutorToroidal::mostrar() {
    return montarCSV();
}
