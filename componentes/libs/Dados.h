#ifndef DADOS_H
#define DADOS_H

#include <string>
using namespace std;

struct dadosCSV {
    string codigo;           // Código do componente
    string tipoComponente; 
    string modelo;
    string valor;            // Valor principal (tensão, capacitância, etc)
    
    // Atributos Genéricos
    string atributo1; 
    string atributo2; 
    string atributo3;
    
    // Construtor padrão
    dadosCSV() {}
};

#endif