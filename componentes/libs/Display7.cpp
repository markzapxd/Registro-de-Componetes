#include "Display7.h"
#include <iostream>
#include <limits>
#include <algorithm> 
#include <cctype>

using namespace std;

Display7::Display7() {
    // Inicializações opcionais podem ir aqui, mas a implementação é obrigatória.
}
// Destrutor: Limpa o objeto (Deve ser implementado, pois foi declarado virtual no .h)
Display7::~Display7() {
    
}


int Display7::obterCodigo() {
    int codigo;
    bool entradaValida = false;
    while (!entradaValida) {
        cout << "\nCodigo (Apenas numeros inteiros positivos. Digite '0' para CANCELAR o cadastro): ";
        if (cin >> codigo) {
            
            // Verifica se o usuário quer cancelar
            if (codigo == 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return 0; // Sinal de CANCELAMENTO, que será capturado pelo Cadastrar()
            }
            if (codigo > 0) {
                entradaValida = true; // Sair do loop
            } else {
                cout << "ERRO: O codigo deve ser um numero positivo." << endl;
            }
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear(); // Limpa o estado de erro
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
    return codigo; // Retorna o valor válido
}

double Display7::obterValor() {
    double valor;
    
    while (true) {
        cout << "\nValor (Geralmente 0.0 para displays. Digite '-1' para CANCELAR o cadastro): ";
        
        if (cin >> valor) {
            // 1. Cancelamento
            if (valor == -1.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return -1.0; // Retorna 0.0 (que Cadastrar() interpretará como erro/cancelamento)
            }
            
            // 2. Validação
            if (valor >= 0.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return valor; // Retorna valor válido e sai da função
            } else {
                cout << "ERRO: O Valor deve ser um numero nao negativo." << endl;
            }
        } else {
            // 3. Tratamento de erro de tipo (digitou letra)
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear();
        }
        
        // Limpa o buffer para a próxima tentativa
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
}

std::string Display7::obterPadrao(){
    string padrao;
    
    while (true) {
        cout << "\nPadrao (Anodo Comum ou Catodo Comum. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, padrao);
        
        // Converte para minúsculas para validação
        string padrao_lower = padrao;
        transform(padrao_lower.begin(), padrao_lower.end(), padrao_lower.begin(), ::tolower);

        // 1. Cancelamento (Usamos um caractere que não seria um padrão válido)
        if (padrao_lower == "c") {
            return ""; // Retorna string vazia para sinalizar cancelamento
        }
        
        // 2. Validação (Verifica se contém "anodo" ou "catodo")
        if (padrao_lower.find("anodo") != string::npos) {
            return "Anodo Comum"; 
        } else if (padrao_lower.find("catodo") != string::npos) {
            return "Catodo Comum";
        } else {
            cout << "ERRO: Padrao invalido. Digite 'Anodo Comum' ou 'Catodo Comum'." << endl;
        }
    }
}

std::string Display7::obterCor(){
    string cor;
    
    while (true) {
        cout << "\nCor (Ex: Vermelho, Verde, Amarelo. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, cor);
        
        // 1. Cancelamento
        string cor_lower = cor;
        transform(cor_lower.begin(), cor_lower.end(), cor_lower.begin(), ::tolower);

        if (cor_lower == "c") {
            return ""; // Sinal de cancelamento
        }

        // 2. Validação (Verifica se a string não está vazia ou contém apenas espaços)
        if (!cor.empty() && cor.find_first_not_of(" ") != string::npos) {
            return cor; // Retorna o valor válido
        } else {
            cout << "ERRO: Cor nao pode ser vazia." << endl;
        }
    }
}

std::string Display7::obterDigitos(){
    int num_digitos;

    while (true) {
        cout << "\nNumero de Digitos (Ex: 1, 2, 4. Digite '0' para CANCELAR o cadastro): ";
        
        if (cin >> num_digitos) {
            
            // 1. Cancelamento
            if (num_digitos == 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return ""; // Sinaliza cancelamento com string vazia
            }
            
            // 2. Validação
            if (num_digitos > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return to_string(num_digitos); // Retorna string válida
            } else {
                cout << "ERRO: O numero de Digitos deve ser positivo." << endl;
            }
        
        } else {
            // 3. Tratamento de erro de tipo
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros inteiros." << endl;
            cin.clear();
        }
        
        // Limpa o buffer para a próxima tentativa
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
}

struct dadosCSV Display7::Cadastrar() {
     // Inicializa a struct com valores de erro (código 0, etc.)

    cout << "\n === Cadastro de Display de Sete Segmentos ===" << endl;

    // 1. Aquisição de campos comuns
    dados.codigo = obterCodigo(); 
    if (dados.codigo <= 0) { // Verifica CANCELAMENTO (0)
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        return dados; 
    } 

    dados.valor = obterValor(); 
    if (dados.valor < 0.0) { // Verifica CANCELAMENTO (-1.0, retorna 0.0)
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = 0; // Marca o codigo como 0 para sinalizar falha/cancelamento no main
        return dados; 
    }
    
    // 2. Definição programática (Alinhado com a struct: modelo é a variação)
    dados.tipoComponente = "Display"; 
    dados.modelo = "SeteSegmentos"; 
    
    // 3. Aquisição e validação dos atributos específicos
    
    dados.atributo1 = obterPadrao(); 
    if (dados.atributo1.empty()) { // Verifica CANCELAMENTO (string vazia)
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    } 
    
    dados.atributo2 = obterCor();
    if (dados.atributo2.empty()) { // Verifica CANCELAMENTO
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    } 
    
    dados.atributo3 = obterDigitos();
    if (dados.atributo3.empty()) { // Verifica CANCELAMENTO
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = 0;
        return dados; 
    } 
    
    cout << "Display de Sete Segmentos cadastrado com sucesso!" << endl;
    return dados;
}


struct dadosCSV Display7::Mostrar(){
	cout << "\n---DADOS DO DISPLAY SETE SEGMENTOS CADASTRADO---" <<endl;
    cout << " Codigo: " << dados.codigo << endl;
    cout << " Tipo: " << dados.tipoComponente << endl;
    cout << " Modelo" << dados.modelo << endl;
    cout << " Tensao de Operacao: " << dados.valor << " Volts" << endl;
    cout << " Padrao: " << dados.atributo1 << endl;
    cout << " Cor: " << dados.atributo2 << endl;
    cout << " Digitos: " << dados.atributo3 << endl;
    cout << "-----------------------------------------" << endl; 
   
    return dados;
}