#include "DisplayOLED.h"
#include <iostream>
#include <string>
#include <limits> 
#include <algorithm> 
#include <cctype>

using namespace std;

// ===============================================
// CONSTRUTOR E DESTRUTOR
// ===============================================

DisplayOLED::DisplayOLED() {
    // Construtor padrão
}

DisplayOLED::~DisplayOLED() {
    // Destrutor
}

// ===============================================
// IMPLEMENTAÇÃO DOS MÉTODOS PRIVADOS (VALIDAÇÃO COM LOOP)
// ===============================================

// Método genérico para obter e validar o Código (Comum)
int DisplayOLED::obterCodigo() {
    int codigo;
    
    while (true) {
        cout << "\nCodigo (Apenas numeros inteiros positivos. Digite '0' para CANCELAR o cadastro): ";
        
        if (cin >> codigo) {
            
            if (codigo == 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return 0; // Sinal de CANCELAMENTO
            }
            
            if (codigo > 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return codigo; // Retorna valor válido
            } else {
                cout << "ERRO: O codigo deve ser um numero positivo." << endl;
            }
        
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear();
        }
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
}

// Método genérico para obter e validar o Valor Principal (Comum: Tensão de Operação)
double DisplayOLED::obterValor() {
    double valor;
    
    while (true) {
        cout << "\nValor (Tensao de operacao em Volts. Digite '-1' para CANCELAR o cadastro): ";
        
        if (cin >> valor) {
            
            if (valor == -1.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return -1.0; // Sinaliza cancelamento (retorno <= 0)
            }
            
            if (valor >= 0.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return valor; // Retorna valor válido
            } else {
                cout << "ERRO: O Valor deve ser um numero nao negativo." << endl;
            }
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear();
        }
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
}

// ATRIBUTO 1: Interface (Ex: I2C, SPI, Paralela)
std::string DisplayOLED::obterInterface(){
    string interface_tipo;
    
    while (true) {
        cout << "\nInterface de Comunicacao (Ex: I2C, SPI, Paralela. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, interface_tipo);

        string interface_lower = interface_tipo;
        transform(interface_lower.begin(), interface_lower.end(), interface_lower.begin(), ::tolower);

        if (interface_lower == "c") {
            return ""; // Sinal de cancelamento
        }
        
        if (!interface_tipo.empty() && interface_tipo.find_first_not_of(" ") != string::npos) {
            return interface_tipo; 
        } else {
            cout << "ERRO: O campo Interface nao pode ser vazio." << endl;
        }
    }
}

// ATRIBUTO 2: Resolucao (Ex: 128x64, 96x96)
std::string DisplayOLED::obterResolucao(){
    string resolucao;
    
    while (true) {
        cout << "\nResolucao (Ex: 128x64, 96x96. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, resolucao);

        string res_lower = resolucao;
        transform(res_lower.begin(), res_lower.end(), res_lower.begin(), ::tolower);

        if (res_lower == "c") {
            return ""; // Sinal de cancelamento
        }
        
        if (!resolucao.empty() && resolucao.find_first_not_of(" ") != string::npos) {
            return resolucao; 
        } else {
            cout << "ERRO: O campo Resolucao nao pode ser vazio." << endl;
        }
    }
}

// ATRIBUTO 3: Cor (Ex: Branco, Amarelo/Azul, Full Color)
std::string DisplayOLED::obterCor(){
    string cor;
    
    while (true) {
        cout << "\nCor do Display (Ex: Branco, Amarelo/Azul, Full Color. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, cor);

        string cor_lower = cor;
        transform(cor_lower.begin(), cor_lower.end(), cor_lower.begin(), ::tolower);

        if (cor_lower == "c") {
            return ""; // Sinal de cancelamento
        }
        
        if (!cor.empty() && cor.find_first_not_of(" ") != string::npos) {
            return cor; 
        } else {
            cout << "ERRO: O campo Cor nao pode ser vazio." << endl;
        }
    }
}


// ===============================================
// MÉTODO PÚBLICO: CADASTRAR (ORQUESTRAÇÃO POLIMÓRFICA)
// ===============================================

struct dadosCSV DisplayOLED::Cadastrar() {
   

    cout << "\n === Cadastro de Display OLED ===" << endl;

    // 1. Aquisição de campos comuns
    dados.codigo = obterCodigo(); 
    if (dados.codigo <= 0) { 
        cout << "Cadastro de Display OLED cancelado." << endl;
        return dados; 
    } 

    dados.valor = obterValor(); 
    if (dados.valor < 0.0) { // Verifica cancelamento/erro
        cout << "Cadastro de Display OLED cancelado." << endl;
        dados.codigo = 0; 
        return dados; 
    }
    
    // 2. Definição programática
    dados.tipoComponente = "Display"; 
    dados.modelo = "OLED"; // Variação Específica
    
    // 3. Aquisição e validação dos atributos específicos
    
    dados.atributo1 = obterInterface(); 
    if (dados.atributo1.empty()) { 
        cout << "Cadastro de Display OLED cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    } 
    
    dados.atributo2 = obterResolucao();
    if (dados.atributo2.empty()) { 
        cout << "Cadastro de Display OLED cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    }
    
    dados.atributo3 = obterCor();
    if (dados.atributo3.empty()) { 
        cout << "Cadastro de Display OLED cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    } 
    
    cout << "Display OLED cadastrado com sucesso!" << endl;
    return dados;
}

// ===============================================
// MÉTODO PÚBLICO: MOSTRAR
// ===============================================

struct dadosCSV DisplayOLED::Mostrar(){
   
   cout << "\n---DADOS DO DISPLAY OLED CADASTRADO---" <<endl;
   cout << " Codigo: " << dados.codigo << endl;
   cout << " Tipo: " << dados.tipoComponente << endl;
   cout << " Modelo" << dados.modelo << endl;
   cout << " Tensao de Operacao: " << dados.valor << " Volts" << endl;
   cout << " Interface: " << dados.atributo1 << endl;
   cout << " Resolucao: " << dados.atributo2 << endl;
   cout << " Cor: " << dados.atributo3 << endl;
   cout << "-----------------------------------------" << endl; 
   
    return dados;
}