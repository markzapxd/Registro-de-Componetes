#include "Zener.h"
#include <iostream>

using namespace std;

Zener::Zener() {
    modelo = "Zener";
}

dadosCSV Zener::Cadastrar() {
    cout << "\nCADASTRO DIODO ZENER\n";
    cout << "Codigo: ";
    getline(cin, codigo);

    if(codigo.empty()) return {};

    cout << "Tensao de ruptura (V): ";
    getline(cin, tensaoRuptura);

   cout << "Potencia (W): ";
    getline(cin, potencia);

    cout << "Tolerancia (%): ";
    getline(cin, tolerancia);

    valor = tensaoRuptura; 

    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = valor;
    dados.atributo1 = potencia;
    dados.atributo2 = tolerancia;
    dados.atributo3 = "-";
    return dados;
}

dadosCSV Zener::Mostrar() {
    dadosCSV dados = Diodo::Mostrar();
    dados.atributo1 = potencia;
    dados.atributo2 = tolerancia;
    dados.atributo3 = "-";
    return dados;
}
