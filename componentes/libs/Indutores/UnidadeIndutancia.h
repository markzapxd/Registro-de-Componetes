#ifndef UNIDADEINDUTANCIA_H
#define UNIDADEINDUTANCIA_H

#include <string>

struct ResultadoIndutancia {
    bool valido;
    double valor;
};

class UnidadeIndutancia {
private:
    std::string unidade;

public:
    UnidadeIndutancia();
    UnidadeIndutancia(const std::string &unid);
    
    void setUnidade(const std::string &unid);
    std::string getUnidade();
    
    ResultadoIndutancia interpretar(const std::string& txt);
    std::string formatar(double h);
};

#endif
