#ifndef INDUTOR_H
#define INDUTOR_H

#include "../DadosCSV.h"
#include <string>
#include <vector>

class Indutor {
public:
    virtual ~Indutor() {}
    virtual DadosCSV cadastrar() = 0;
    virtual DadosCSV mostrar() = 0;
protected:

    std::string solicitarString(const std::string &mensagem, int tamanhoMinimo = 1);
    int solicitarIntRange(const std::string &mensagem, int minVal, int maxVal);
    double solicitarDoubleRange(const std::string &mensagem, double minVal, double maxVal);
    std::string solicitarMaterial(const std::string &mensagem, const std::vector<std::string> &permitidos);
};

#endif
