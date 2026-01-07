#include "DisplayLCD.h"
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

DisplayLCD::DisplayLCD() {}
DisplayLCD::~DisplayLCD() {}

string DisplayLCD::obterCodigo() {
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

string DisplayLCD::obterValor() {
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

string DisplayLCD::obterBacklight() {
    string resp;
    while (true) {
        cout << "\nPossui Backlight? (S/N, 'C' para CANCELAR): ";
        getline(cin, resp);
        if (resp == "c" || resp == "C") return "";
        if (resp == "s" || resp == "S" || resp == "sim" || resp == "Sim") return "Sim";
        if (resp == "n" || resp == "N" || resp == "nao" || resp == "Nao") return "Nao";
        cout << "ERRO: Resposta invalida." << endl;
    }
}

string DisplayLCD::obterColunas() {
    int colunas;
    while (true) {
        cout << "\nNumero de Colunas (Ex: 16, 20. 0 para CANCELAR): ";
        if (cin >> colunas) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (colunas == 0) return "";
            if (colunas > 0) return to_string(colunas);
            cout << "ERRO: Numero deve ser positivo." << endl;
        } else {
            cout << "ERRO: Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string DisplayLCD::obterDimensoes() {
    string dim;
    while (true) {
        cout << "\nDimensoes (Ex: 16x2, 20x4. 'C' para CANCELAR): ";
        getline(cin, dim);
        if (dim == "c" || dim == "C") return "";
        if (!dim.empty()) return dim;
        cout << "ERRO: Dimensoes invalidas." << endl;
    }
}

struct dadosCSV DisplayLCD::Cadastrar() {
    cout << "\n=== Cadastro de Display LCD ===" << endl;

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
    dados.modelo = "LCD";

    dados.atributo1 = obterBacklight();
    if (dados.atributo1.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo2 = obterColunas();
    if (dados.atributo2.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo3 = obterDimensoes();
    if (dados.atributo3.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    cout << "Display LCD cadastrado com sucesso!" << endl;
    return dados;
}

struct dadosCSV DisplayLCD::Mostrar() {
    cout << "\n--- DISPLAY LCD ---" << endl;
    cout << "Codigo: " << dados.codigo << endl;
    cout << "Tipo: " << dados.tipoComponente << endl;
    cout << "Modelo: " << dados.modelo << endl;
    cout << "Tensao: " << dados.valor << endl;
    cout << "Backlight: " << dados.atributo1 << endl;
    cout << "Colunas: " << dados.atributo2 << endl;
    cout << "Dimensoes: " << dados.atributo3 << endl;
    cout << "-------------------" << endl;
    return dados;
}
