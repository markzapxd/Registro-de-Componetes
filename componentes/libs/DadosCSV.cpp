#include "DadosCSV.h"
#include <sstream>
#include <vector>

DadosCSV::DadosCSV() {}

DadosCSV::DadosCSV(const std::string& cod, const std::string& tip, const std::string& mod,
                   const std::string& val, const std::string& a1,
                   const std::string& a2, const std::string& a3)
    : codigo(cod), tipo(tip), modelo(mod), valor(val),
      atributo1(a1), atributo2(a2), atributo3(a3) {}

std::string DadosCSV::toCSV() const {
    return codigo + "," + tipo + "," + modelo + "," + valor + "," +
           atributo1 + "," + atributo2 + "," + atributo3;
}

DadosCSV DadosCSV::fromCSV(const std::string &linha) {
    std::stringstream ss(linha);
    std::string campo;
    std::vector<std::string> cols;
    while (std::getline(ss, campo, ',')) cols.push_back(campo);
    while (cols.size() < 7) cols.push_back("");

    return DadosCSV(cols[0], cols[1], cols[2], cols[3], cols[4], cols[5], cols[6]);
}
