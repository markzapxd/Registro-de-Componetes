#include "GerenciadorComponentes.h"
#include <iostream>
#include <sstream>

GerenciadorComponentes::GerenciadorComponentes(string nomeArq) {
    nomeArquivo = nomeArq;
    carregarDoArquivo();
}

GerenciadorComponentes::~GerenciadorComponentes() {
    salvarEmArquivo();
}

void GerenciadorComponentes::adicionar(dadosCSV dados) {
    componentes.push_back(dados);
}

void GerenciadorComponentes::escreverCabecalho(ofstream& arquivo) {
    arquivo << "Codigo,Tipo,Modelo,Valor,Atributo1,Atributo2,Atributo3\n";
}

void GerenciadorComponentes::salvarEmArquivo() {
    ofstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "[ERRO] Nao foi possivel abrir o arquivo para escrita.\n";
        return;
    }
    
    escreverCabecalho(arquivo);
    
    for (const auto& dados : componentes) {
        arquivo << dados.codigo << ","
                << dados.tipoComponente << ","
                << dados.modelo << ","
                << dados.valor << ","
                << dados.atributo1 << ","
                << dados.atributo2 << ","
                << dados.atributo3 << "\n";
    }
    
    arquivo.close();
    cout << "[SUCESSO] Dados salvos em " << nomeArquivo << "\n";
}

void GerenciadorComponentes::carregarDoArquivo() {
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "[INFO] Arquivo nao encontrado. Iniciando com banco vazio.\n";
        return;
    }
    
    string linha;
    getline(arquivo, linha); // Pula cabecalho
    
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        
        dadosCSV dados;
        size_t pos = 0;
        
        // Parse CSV simples
        pos = linha.find(',');
        dados.codigo = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        pos = linha.find(',');
        dados.tipoComponente = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        pos = linha.find(',');
        dados.modelo = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        pos = linha.find(',');
        dados.valor = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        pos = linha.find(',');
        dados.atributo1 = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        pos = linha.find(',');
        dados.atributo2 = linha.substr(0, pos);
        linha.erase(0, pos + 1);
        
        dados.atributo3 = linha;
        
        componentes.push_back(dados);
    }
    
    arquivo.close();
    cout << "[SUCESSO] " << componentes.size() << " componentes carregados.\n";
}

vector<dadosCSV> GerenciadorComponentes::obterComponentes() {
    return componentes;
}

int GerenciadorComponentes::obterTamanho() {
    return componentes.size();
}

dadosCSV GerenciadorComponentes::obterPorIndice(int indice) {
    if (indice >= 0 && indice < (int)componentes.size()) {
        return componentes[indice];
    }
    return {};
}

void GerenciadorComponentes::editar(int indice, dadosCSV novosDados) {
    if (indice >= 0 && indice < (int)componentes.size()) {
        componentes[indice] = novosDados;
        cout << "[SUCESSO] Componente editado na posicao " << indice << "!\n";
        salvarEmArquivo();
    } else {
        cout << "[ERRO] Indice invalido.\n";
    }
}

void GerenciadorComponentes::remover(int indice) {
    if (indice >= 0 && indice < (int)componentes.size()) {
        cout << "[INFO] Removendo: " << componentes[indice].modelo << "\n";
        componentes.erase(componentes.begin() + indice);
        cout << "[SUCESSO] Componente removido!\n";
        salvarEmArquivo();
    } else {
        cout << "[ERRO] Indice invalido.\n";
    }
}

vector<dadosCSV> GerenciadorComponentes::buscarPorTipo(string tipo) {
    vector<dadosCSV> resultados;
    for (const auto& comp : componentes) {
        if (comp.tipoComponente == tipo) {
            resultados.push_back(comp);
        }
    }
    return resultados;
}

vector<dadosCSV> GerenciadorComponentes::buscarPorCodigo(string codigo) {
    vector<dadosCSV> resultados;
    for (const auto& comp : componentes) {
        if (comp.codigo == codigo) {
            resultados.push_back(comp);
        }
    }
    return resultados;
}