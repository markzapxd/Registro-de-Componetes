#include "Tantalum.h"
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

dadosCSV Tantalum::Cadastrar() {
    cout << "\n=== Cadastro Capacitor de Tantalo ===\n";

    cout << "Codigo (0 para cancelar): ";
    cin >> codigoStr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (codigoStr == "0") {
        cout << "Cadastro cancelado.\n";
        dados.codigo = "";
        return dados;
    }

    cout << "Capacitancia (uF): ";
    cin >> capacitancia;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Tensao (V): ";
    cin >> tensao;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Temperatura (C): ";
    cin >> temperatura;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Encapsulamento (Ex: SMD, Through-Hole, Axial): ";
    getline(cin, encapsulamento);

    // Preencher struct dadosCSV
    dados.codigo = codigoStr;
    dados.tipoComponente = "Capacitor";
    dados.modelo = "Tantalum";
    
    stringstream ss;
    ss << capacitancia << " uF";
    dados.valor = ss.str();
    
    ss.str("");
    ss << tensao << " V";
    dados.atributo1 = ss.str();
    
    ss.str("");
    ss << temperatura << " C";
    dados.atributo2 = ss.str();
    
    dados.atributo3 = encapsulamento;

    cout << "Capacitor de Tantalo cadastrado com sucesso!\n";
    return dados;
}

dadosCSV Tantalum::Mostrar() {
    cout << "\n--- CAPACITOR DE TANTALO ---\n";
    cout << "Codigo: " << dados.codigo << endl;
    cout << "Tipo: " << dados.tipoComponente << endl;
    cout << "Modelo: " << dados.modelo << endl;
    cout << "Capacitancia: " << dados.valor << endl;
    cout << "Tensao: " << dados.atributo1 << endl;
    cout << "Temperatura: " << dados.atributo2 << endl;
    cout << "Encapsulamento: " << dados.atributo3 << endl;
    cout << "----------------------------\n";
    return dados;
}
