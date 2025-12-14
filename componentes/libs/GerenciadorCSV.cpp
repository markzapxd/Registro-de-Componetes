#include "GerenciadorCSV.h"
#include <fstream>
#include <iostream>

GerenciadorCSV::GerenciadorCSV(const std::string &caminho)
    : caminhoArquivo(caminho) {}


void GerenciadorCSV::salvar(const DadosCSV &d) {
    std::ofstream arq(caminhoArquivo, std::ios::app); 
    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << "\n";
        return;
    }
    arq << d.toCSV() << "\n";
}
