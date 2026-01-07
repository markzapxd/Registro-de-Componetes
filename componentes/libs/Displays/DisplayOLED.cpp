#include "DisplayOLED.h"
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

DisplayOLED::DisplayOLED() {}
DisplayOLED::~DisplayOLED() {}

string DisplayOLED::obterCodigo() {
    string codigo;
    while (true) {
        cout << "\nCodigo (Digite '0' para CANCELAR): ";
        cin >> codigo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (codigo == "0") return "";
        if (!codigo.empty()) return codigo;
        cout << "ERRO: Codigo invalido." << endl;
    }
}

string DisplayOLED::obterValor() {
    double valor;
    while (true) {
        cout << "\nTensao de Operacao em Volts (Digite '-1' para CANCELAR): ";
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (valor == -1.0) return "";
            if (valor >= 0.0) {
                stringstream ss;
                ss << valor << " V";
                return ss.str();
            }
            cout << "ERRO: Valor deve ser positivo." << endl;
        } else {
            cout << "ERRO: Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string DisplayOLED::obterResolucao() {
    string res;
    while (true) {
        cout << "\nResolucao (Ex: 128x64, 128x32. 'C' para CANCELAR): ";
        getline(cin, res);
        if (res == "c" || res == "C") return "";
        if (!res.empty()) return res;
        cout << "ERRO: Resolucao invalida." << endl;
    }
}

string DisplayOLED::obterInterface() {
    string interf;
    while (true) {
        cout << "\nInterface (I2C, SPI, etc. 'C' para CANCELAR): ";
        getline(cin, interf);
        if (interf == "c" || interf == "C") return "";
        if (!interf.empty()) return interf;
        cout << "ERRO: Interface invalida." << endl;
    }
}

string DisplayOLED::obterCor() {
    string cor;
    while (true) {
        cout << "\nCor do Display (Ex: Branco, Azul, Amarelo. 'C' para CANCELAR): ";
        getline(cin, cor);
        if (cor == "c" || cor == "C") return "";
        if (!cor.empty()) return cor;
        cout << "ERRO: Cor invalida." << endl;
    }
}

struct dadosCSV DisplayOLED::Cadastrar() {
    cout << "\n=== Cadastro de Display OLED ===" << endl;

    dados.codigo = obterCodigo();
    if (dados.codigo.empty()) {
        cout << "Cadastro cancelado." << endl;
        return dados;
    }

    dados.valor = obterValor();
    if (dados.valor.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.tipoComponente = "Display";
    dados.modelo = "OLED";

    dados.atributo1 = obterResolucao();
    if (dados.atributo1.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo2 = obterInterface();
    if (dados.atributo2.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo3 = obterCor();
    if (dados.atributo3.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    cout << "Display OLED cadastrado com sucesso!" << endl;
    return dados;
}

struct dadosCSV DisplayOLED::Mostrar() {
    cout << "\n--- DISPLAY OLED ---" << endl;
    cout << "Codigo: " << dados.codigo << endl;
    cout << "Tipo: " << dados.tipoComponente << endl;
    cout << "Modelo: " << dados.modelo << endl;
    cout << "Tensao: " << dados.valor << endl;
    cout << "Resolucao: " << dados.atributo1 << endl;
    cout << "Interface: " << dados.atributo2 << endl;
    cout << "Cor: " << dados.atributo3 << endl;
    cout << "--------------------" << endl;
    return dados;
}
