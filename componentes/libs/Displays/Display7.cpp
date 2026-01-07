#include "Display7.h"
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

Display7::Display7() {}
Display7::~Display7() {}

string Display7::obterCodigo() {
    string codigo;
    while (true) {
        cout << "\nCodigo (Digite '0' para CANCELAR): ";
        cin >> codigo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (codigo == "0") {
            return "";
        }
        if (!codigo.empty()) {
            return codigo;
        }
        cout << "ERRO: Codigo invalido." << endl;
    }
}

string Display7::obterValor() {
    double valor;
    while (true) {
        cout << "\nValor/Tensao (Digite '-1' para CANCELAR): ";
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

string Display7::obterPadrao() {
    string padrao;
    while (true) {
        cout << "\nPadrao (Anodo/Catodo, 'C' para CANCELAR): ";
        getline(cin, padrao);
        if (padrao == "c" || padrao == "C") return "";
        if (padrao.find("anodo") != string::npos || padrao.find("Anodo") != string::npos) 
            return "Anodo Comum";
        if (padrao.find("catodo") != string::npos || padrao.find("Catodo") != string::npos) 
            return "Catodo Comum";
        if (!padrao.empty()) return padrao;
        cout << "ERRO: Padrao invalido." << endl;
    }
}

string Display7::obterCor() {
    string cor;
    while (true) {
        cout << "\nCor (Ex: Vermelho, Verde. 'C' para CANCELAR): ";
        getline(cin, cor);
        if (cor == "c" || cor == "C") return "";
        if (!cor.empty()) return cor;
        cout << "ERRO: Cor invalida." << endl;
    }
}

string Display7::obterDigitos() {
    int digitos;
    while (true) {
        cout << "\nNumero de Digitos (0 para CANCELAR): ";
        if (cin >> digitos) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (digitos == 0) return "";
            if (digitos > 0) return to_string(digitos);
            cout << "ERRO: Numero deve ser positivo." << endl;
        } else {
            cout << "ERRO: Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

struct dadosCSV Display7::Cadastrar() {
    cout << "\n=== Cadastro de Display 7 Segmentos ===" << endl;

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
    dados.modelo = "SeteSegmentos";

    dados.atributo1 = obterPadrao();
    if (dados.atributo1.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo2 = obterCor();
    if (dados.atributo2.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    dados.atributo3 = obterDigitos();
    if (dados.atributo3.empty()) {
        cout << "Cadastro cancelado." << endl;
        dados.codigo = "";
        return dados;
    }

    cout << "Display 7 Segmentos cadastrado com sucesso!" << endl;
    return dados;
}

struct dadosCSV Display7::Mostrar() {
    cout << "\n--- DISPLAY 7 SEGMENTOS ---" << endl;
    cout << "Codigo: " << dados.codigo << endl;
    cout << "Tipo: " << dados.tipoComponente << endl;
    cout << "Modelo: " << dados.modelo << endl;
    cout << "Tensao: " << dados.valor << endl;
    cout << "Padrao: " << dados.atributo1 << endl;
    cout << "Cor: " << dados.atributo2 << endl;
    cout << "Digitos: " << dados.atributo3 << endl;
    cout << "---------------------------" << endl;
    return dados;
}
