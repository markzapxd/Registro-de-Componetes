#include "LED.h"
#include <iostream>

using namespace std;

LED::LED() {
    modelo = "LED";
}

dadosCSV LED::Cadastrar() {
    cout << "\nCADASTRO LED\n";
    cout << "Codigo: ";
    getline(cin, codigo);
    if(codigo.empty()) return {};

    cout << "Cor: ";
    getline(cin, cor);

    cout << "Corrente Max (mA): ";
    getline(cin, correnteMax);

    cout << "Tensao Vf (V): ";
    getline(cin, tensaoVf);

    valor = tensaoVf;

    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = valor;
    dados.atributo1 = cor;
    dados.atributo2 = correnteMax;
    dados.atributo3 = "-";
    return dados;
}

dadosCSV LED::Mostrar() {
    dadosCSV dados = Diodo::Mostrar();
    dados.atributo1 = cor;
    dados.atributo2 = correnteMax;
    dados.atributo3 = tensaoVf;
    return dados;
}
