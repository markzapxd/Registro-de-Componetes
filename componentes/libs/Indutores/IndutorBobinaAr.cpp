#include "IndutorBobinaAr.h"
#include <iostream>
#include <algorithm>
#include <cctype>

std::string IndutorBobinaAr::lerCodigo() {
    Entrada entrada("Codigo: ");
    std::string CodigoRegistro;
    do CodigoRegistro = entrada.ler(); while (CodigoRegistro.empty());
    return CodigoRegistro;
}

double IndutorBobinaAr::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        std::cout << "Valor invalido.\n";
    }
}

DadosCSV IndutorBobinaAr::montarCSV() {
    UnidadeIndutancia unidade;
    return DadosCSV(
        codigo, "Indutor", "BobinaAr",
        unidade.formatar(valorH),
        espiras, diametroFio, comprimento
    );
}

DadosCSV IndutorBobinaAr::cadastrar() {
    codigo = lerCodigo();
    valorH = lerIndutancia();


    int nEspiras = solicitarIntRange("Numero de espiras: ", 1, 1000000);
    espiras = std::to_string(nEspiras);

    double dFio = solicitarDoubleRange("Diametro do fio (mm): ", 0.05, 5.0);
    diametroFio = std::to_string(dFio);

    double comp = solicitarDoubleRange("Comprimento (mm): ", 0.5, 2000.0);
    comprimento = std::to_string(comp);
    return montarCSV();
}

DadosCSV IndutorBobinaAr::mostrar() {
    return montarCSV();
}
