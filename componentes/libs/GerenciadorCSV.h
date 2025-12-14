#ifndef GERENCIADORCSV_H
#define GERENCIADORCSV_H

#include "DadosCSV.h"
#include <string>

class GerenciadorCSV {
private:
    std::string caminhoArquivo;

public:

    GerenciadorCSV(const std::string &caminho);


    void salvar(const DadosCSV &d);
};

#endif
