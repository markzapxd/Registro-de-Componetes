#include "Schottky.h"
#include <iostream>

using namespace std;

Schottky::Schottky() {
    modelo = "Schottky";
}

dadosCSV Schottky::Cadastrar() {
    cout << "\nCADASTRO DIODO SCHOTTKY\n";
    cout << "Codigo: ";
    getline(std::cin, codigo);
    if(codigo.empty()) return {};

   cout << "Tensao Vf (V): ";
    getline(cin, tensaoVf);

    cout << "Corrente Max (A): ";
    getline(cin, correnteMax);

    cout << "Velocidade de Comutacao: ";
    getline(cin, velocidadeComutacao);

    valor = tensaoVf;

    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = valor;
    dados.atributo1 = correnteMax;
    dados.atributo2 = velocidadeComutacao;
    dados.atributo3 = "-";
    return dados;
}

dadosCSV Schottky::Mostrar() {
    dadosCSV dados = Diodo::Mostrar();
    dados.atributo1 = correnteMax;
    dados.atributo2 = velocidadeComutacao;
    dados.atributo3 = tensaoVf;
    return dados;
}
