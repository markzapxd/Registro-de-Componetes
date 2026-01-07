#ifndef DADOSCSV_H
#define DADOSCSV_H

#include <string>

class DadosCSV {
public:
    std::string codigo;
    std::string tipo;
    std::string modelo;
    std::string valor;
    std::string atributo1;
    std::string atributo2;
    std::string atributo3;

    DadosCSV();
    DadosCSV(const std::string& cod, const std::string& tip, const std::string& mod,
             const std::string& val, const std::string& a1,
             const std::string& a2, const std::string& a3);

    std::string toCSV() const;
    static DadosCSV fromCSV(const std::string &linha);
};

#endif
