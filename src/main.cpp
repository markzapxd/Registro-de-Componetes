#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/dadosCSV.h"
#include "../lib/LED/LED.h"
#include "../lib/Zener/Zener.h"
#include "../lib/Schottky/Schottky.h"

using namespace std;

vector<dadosCSV> cadastro;

// ================= SALVAR CSV =================

void salvarCSV(const string &nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if(!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }

    for(dadosCSV &d : cadastro) {
        arquivo << d.codigo << ","
                << d.tipoComponente << ","
                << d.modelo << ","
                << d.valor << ","
                << d.atributo1 << ","
                << d.atributo2 << ","
                << d.atributo3 << "\n";
    }

    arquivo.close();
    cout << "Dados salvos!\n";
}

// ================= CARREGAR CSV =================

void carregarCSV(const string &nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if(!arquivo.is_open()) {
        cout << "Arquivo nao encontrado, iniciando vazio.\n";
        return;
    }

    cadastro.clear();
    string linha;
    while(getline(arquivo, linha)) {
        stringstream ss(linha);
        dadosCSV dados;
        getline(ss, dados.codigo, ',');
        getline(ss, dados.tipoComponente, ',');
        getline(ss, dados.modelo, ',');
        getline(ss, dados.valor, ',');
        getline(ss, dados.atributo1, ',');
        getline(ss, dados.atributo2, ',');
        getline(ss, dados.atributo3, ',');

        cadastro.push_back(dados);
    }

    arquivo.close();
    cout << "Dados carregados!\n";
}

// ================= LISTAR =================

void listar() {
    cout << "\n----- LISTA DE COMPONENTES -----\n";
    for(dadosCSV &d : cadastro) {
        cout << d.codigo << " | "
             << d.tipoComponente << " | "
             << d.modelo << " | "
             << d.valor << " | "
             << d.atributo1 << " | "
             << d.atributo2 << " | "
             << d.atributo3 << "\n";
    }
}

// ================= BUSCAR POR CÓDIGO =================

void buscarPorCodigo() {
    string cod;
    cout << "codigo: ";
    getline(cin, cod);

    for(dadosCSV &d : cadastro) {
        if(d.codigo == cod) {
            cout << "\nEncontrado:\n";
            cout << d.codigo << " | " << d.tipoComponente << " | " << d.modelo
                 << " | " << d.valor << " | " << d.atributo1
                 << " | " << d.atributo2 << " | " << d.atributo3 << "\n";
            return;
        }
    }
    cout << "Nenhum componente encontrado.\n";
}

// ================= BUSCAR POR TIPO =================

void buscarPorTipo() {
    string tipo;
    cout << "Digite o tipo (Zener / LED / Schottky): ";
    getline(cin, tipo);

    bool achou = false;

    for(dadosCSV &d : cadastro) {
        if(d.modelo == tipo) {
            cout << d.codigo << " | "
                 << d.modelo << " | "
                 << d.valor << " | "
                 << d.atributo1 << " | "
                 << d.atributo2 << " | "
                 << d.atributo3 << "\n";

            achou = true;
        }
    }

    if(!achou) cout << "Nenhum componente desse tipo encontrado.\n";
}

// ================= REMOVER =================

void removerComponente() {
    string cod;
    cout << "codigo a remover: ";
    getline(cin, cod);

    for(size_t i = 0; i < cadastro.size(); i++) {
        if(cadastro[i].codigo == cod) {
            cadastro.erase(cadastro.begin() + i);
            cout << "Removido!\n";
            return;
        }
    }

    cout << "Codigo nao encontrado.\n";
}

// ================= EDITAR =================

void editarComponente() {
    string cod;
    cout << "codigo a editar: ";
    getline(cin, cod);

    for(dadosCSV &d : cadastro) {
        if(d.codigo == cod) {
            string temp;

            cout << "Novo valor (ENTER = manter) [" << d.valor << "]: ";
            getline(cin, temp);
            if(!temp.empty()) d.valor = temp;

            cout << "Novo atributo1 (ENTER = manter) [" << d.atributo1 << "]: ";
            getline(cin, temp);
            if(!temp.empty()) d.atributo1 = temp;

            cout << "Novo atributo2 (ENTER = manter) [" << d.atributo2 << "]: ";
            getline(cin, temp);
            if(!temp.empty()) d.atributo2 = temp;

            cout << "Novo atributo3 (ENTER = manter) [" << d.atributo3 << "]: ";
            getline(cin, temp);
            if(!temp.empty()) d.atributo3 = temp;

            cout << "Editado com sucesso!\n";
            return;
        }
    }

    cout << "Codigo nao encontrado.\n";
}

// ================= MENU CADASTRO =================

int menuCadastro() {
    int op;
    cout << "\nCadastrar:\n"
         << "1 - Diodo Zener\n"
         << "2 - LED\n"
         << "3 - Schottky\n"
         << "0 - Voltar\n"
         << "Opcao: ";
    cin >> op;
    cin.ignore();
    return op;
}

// ================= MAIN =================

int main() {
    carregarCSV("componentes.csv");

    int opcao;
    while(true) {
        cout << "\n===== SISTEMA DE CADASTRO =====\n"
             << "1 - Cadastrar novo componente\n"
             << "2 - Listar componentes\n"
             << "3 - Buscar por codigo\n"
             << "4 - Buscar por tipo\n"
             << "5 - Editar componente\n"
             << "6 - Remover componente\n"
             << "7 - Salvar\n"
             << "0 - Sair\n"
             << "Opcao: ";

        cin >> opcao;
        cin.ignore();

        if(opcao == 0) break;

        switch(opcao) {
        case 1: {
            int tipo = menuCadastro();
            dadosCSV d;

            if(tipo == 1) {
                Zener z;
                d = z.Cadastrar();
            } else if(tipo == 2) {
                LED l;
                d = l.Cadastrar();
            } else if(tipo == 3) {
                Schottky s;
                d = s.Cadastrar();
            } else continue;

            if(!d.codigo.empty()) cadastro.push_back(d);
            break;
        }

        case 2:
            listar();
            break;

        case 3:
            buscarPorCodigo();
            break;

        case 4:
            buscarPorTipo();
            break;

        case 5:
            editarComponente();
            break;

        case 6:
            removerComponente();
            break;

        case 7:
            salvarCSV("componentes.csv");
            break;

        default:
            cout << "Opcao invalida!\n";
        }
    }

    salvarCSV("componentes.csv");
    return 0;
}
