#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#include "Dados.h"
#include "DadosCSV.h"

#include "GerenciadorComponentes/GerenciadorComponentes.h"
#include "ExibidorComponente/ExibidorComponente.h"

#include "Indutores/Indutor.h"
#include "Indutores/IndutorToroidal.h"
#include "Indutores/IndutorBobinaAr.h"
#include "Indutores/IndutorFerrite.h"

#include "AmplificadorOperacional/AmplificadorOperacional.h"
#include "AmplificadorInversor/AmplificadorInversor.h"
#include "AmplificadorNaoInversor/AmplificadorNaoInversor.h"
#include "AmplificadorDiferencial/AmplificadorDiferencial.h"

#include "Capacitores/Capacitor.h"
#include "Capacitores/Ceramico.h"
#include "Capacitores/Eletrolitico.h"
#include "Capacitores/Tantalum.h"

#include "Displays/Display.h"
#include "Displays/Display7.h"
#include "Displays/DisplayLCD.h"
#include "Displays/DisplayOLED.h"

using namespace std;

dadosCSV converterParaDadosCSV(const DadosCSV& d) {
    dadosCSV resultado;
    resultado.codigo = d.codigo; //d de dados csv
    resultado.tipoComponente = d.tipo;
    resultado.modelo = d.modelo;
    resultado.valor = d.valor;
    resultado.atributo1 = d.atributo1;
    resultado.atributo2 = d.atributo2;
    resultado.atributo3 = d.atributo3;
    return resultado;
}

void limparTela();
void pausar();
void limparBuffer();
int lerOpcao();
void exibirMenuPrincipal();
void exibirMenuCadastro();
void exibirMenuBusca();

void cadastrarComponente(GerenciadorComponentes& gerenciador);
void listarComponentes(GerenciadorComponentes& gerenciador);
void buscarComponente(GerenciadorComponentes& gerenciador);
void editarComponente(GerenciadorComponentes& gerenciador);
void removerComponente(GerenciadorComponentes& gerenciador);

int main() {
    GerenciadorComponentes gerenciador("componentes.csv");
    ExibidorComponente exibidor;
    
    int opcao;
    
    do {
        limparTela();
        exibirMenuPrincipal();
        opcao = lerOpcao();
        
        switch (opcao) {
            case 1:
                cadastrarComponente(gerenciador);
                break;
            case 2:
                listarComponentes(gerenciador);
                break;
            case 3:
                buscarComponente(gerenciador);
                break;
            case 4:
                editarComponente(gerenciador);
                break;
            case 5:
                removerComponente(gerenciador);
                break;
            case 0:
                cout << "\nSalvando dados\n";
                break;
            default:
                cout << "\ninvalido!\n";
                pausar();
        }
    } while (opcao != 0);
    
    return 0;
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int lerOpcao() {
    int opcao;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    
    if (cin.fail()) {
        limparBuffer();
        return -1;
    }
    limparBuffer();
    return opcao;
}

void exibirMenuPrincipal() {
    cout << "   SISTEMA DE CADASTRO DE COMPONENTES  \n";
    cout << "           ELETRONICOS                 \n";
    cout << "\n";
    cout << "  [1] Cadastrar novo componente\n";
    cout << "  [2] Listar todos os componentes\n";
    cout << "  [3] Buscar componente\n";
    cout << "  [4] Editar componente\n";
    cout << "  [5] Remover componente\n";
    cout << "  [0] Sair\n";
    cout << "\n";
}

void exibirMenuCadastro() {
    cout << "    SELECIONE O TIPO DE COMPONENTE     \n";
    cout << "\n";
    cout << "   INDUTORES \n";
    cout << "  [1] Indutor Toroidal\n";
    cout << "  [2] Indutor Bobina de Ar\n";
    cout << "  [3] Indutor Ferrite\n";
    cout << "\n";
    cout << "   AMPLIFICADORES OPERACIONAIS \n";
    cout << "  [4] Amplificador Inversor\n";
    cout << "  [5] Amplificador Nao-Inversor\n";
    cout << "  [6] Amplificador Diferencial\n";
    cout << "\n";
    cout << "   CAPACITORES \n";
    cout << "  [7] Capacitor Ceramico\n";
    cout << "  [8] Capacitor Eletrolitico\n";
    cout << "  [9] Capacitor Tantalum\n";
    cout << "\n";
    cout << "   DISPLAYS \n";
    cout << "  [10] Display 7 Segmentos\n";
    cout << "  [11] Display LCD\n";
    cout << "  [12] Display OLED\n";
    cout << "\n";
    cout << "  [0] Voltar ao menu principal\n";
    cout << "\n";
}

void exibirMenuBusca() {
    cout << "         OPCOES DE BUSCA               \n";
    cout << "\n";
    cout << "  [1] Buscar por codigo\n";
    cout << "  [2] Buscar por tipo\n";
    cout << "  [0] Voltar\n";
    cout << "\n";
}

void cadastrarComponente(GerenciadorComponentes& gerenciador) {
    int opcao;
    dadosCSV dados;
    bool cadastrado = false;
    
    do {
        limparTela();
        exibirMenuCadastro();
        opcao = lerOpcao();
        
        switch (opcao) {
            case 1: {
                IndutorToroidal toroidal;
                DadosCSV dadosInd = toroidal.cadastrar();
                dados = converterParaDadosCSV(dadosInd);
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    toroidal.mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 2: {
                IndutorBobinaAr bobinaAr;
                DadosCSV dadosInd = bobinaAr.cadastrar();
                dados = converterParaDadosCSV(dadosInd);
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    bobinaAr.mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 3: {
                IndutorFerrite ferrite;
                DadosCSV dadosInd = ferrite.cadastrar();
                dados = converterParaDadosCSV(dadosInd);
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    ferrite.mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 4: {
                AmplificadorInversor inversor;
                dados = inversor.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    inversor.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 5: {
                AmplificadorNaoInversor naoInversor;
                dados = naoInversor.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    naoInversor.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 6: {
                AmplificadorDiferencial diferencial;
                dados = diferencial.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    diferencial.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 7: {
                Ceramico ceramico;
                dados = ceramico.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    ceramico.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 8: {
                Eletrolitico eletrolitico;
                dados = eletrolitico.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    eletrolitico.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 9: {
                Tantalum tantalum;
                dados = tantalum.Cadastrar();
                if (!dados.codigo.empty() && dados.codigo != "0") {
                    gerenciador.adicionar(dados);
                    tantalum.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 10: {
                Display7 display7;
                dados = display7.Cadastrar();
                if (!dados.codigo.empty()) {
                    gerenciador.adicionar(dados);
                    display7.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 11: {
                DisplayLCD displayLCD;
                dados = displayLCD.Cadastrar();
                if (!dados.codigo.empty()) {
                    gerenciador.adicionar(dados);
                    displayLCD.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 12: {
                DisplayOLED displayOLED;
                dados = displayOLED.Cadastrar();
                if (!dados.codigo.empty()) {
                    gerenciador.adicionar(dados);
                    displayOLED.Mostrar();
                    cadastrado = true;
                }
                break;
            }
            case 0:
                return;
            default:
                cout << "\nOpcao invalida!\n";
        }
        
        if (cadastrado) {
            cout << "\nComponente cadastrado com sucesso!\n";
            cadastrado = false;
        }
        
        if (opcao != 0) {
            pausar();
        }
        
    } while (opcao != 0);
}

void listarComponentes(GerenciadorComponentes& gerenciador) {
    limparTela();
    
    cout << "      LISTA DE COMPONENTES             \n";
    
    int total = gerenciador.obterTamanho();
    
    if (total == 0) {
        cout << "[INFO] Nenhum componente cadastrado.\n";
    } else {
        cout << "Total de componentes: " << total << "\n\n";
        
        cout << left
             << setw(8) << "Indice"
             << setw(12) << "Codigo"
             << setw(20) << "Tipo"
             << setw(20) << "Modelo"
             << setw(15) << "Valor" << "\n";
        cout << string(75, '-') << "\n";
        
        vector<dadosCSV> componentes = gerenciador.obterComponentes();
        for (int i = 0; i < total; i++) {
            dadosCSV comp = componentes[i];
            cout << left
                 << setw(8) << i
                 << setw(12) << comp.codigo
                 << setw(20) << comp.tipoComponente
                 << setw(20) << comp.modelo
                 << setw(15) << comp.valor << "\n";
        }
        
        cout << string(75, '-') << "\n";
        
        cout << "\nDeseja ver detalhes de algum componente? (S/N): ";
        char resposta;
        cin >> resposta;
        limparBuffer();
        
        if (resposta == 'S' || resposta == 's') {
            cout << "Digite o indice do componente: ";
            int indice;
            cin >> indice;
            limparBuffer();
            
            if (indice >= 0 && indice < total) {
                ExibidorComponente exibidor;
                exibidor.exibir(componentes[indice]);
            } else {
                cout << "Indice invalido!\n";
            }
        }
    }
    
    pausar();
}

void buscarComponente(GerenciadorComponentes& gerenciador) {
    limparTela();
    exibirMenuBusca();
    
    int opcao = lerOpcao();
    vector<dadosCSV> resultados;
    
    switch (opcao) {
        case 1: {
            cout << "\nDigite o codigo do componente: ";
            string codigo;
            getline(cin, codigo);
            resultados = gerenciador.buscarPorCodigo(codigo);
            break;
        }
        case 2: {
            cout << "\nTipos disponiveis: Indutor, AmplificadorOperacional, Capacitor, Display\n";
            cout << "Digite o tipo do componente: ";
            string tipo;
            getline(cin, tipo);
            resultados = gerenciador.buscarPorTipo(tipo);
            break;
        }
        case 0:
            return;
        default:
            cout << "Invalido!\n";
            pausar();
            return;
    }
    
    cout << "       RESULTADOS DA BUSCA             \n";
    
    if (resultados.empty()) {
        cout << "Nenhum encontrado.\n";
    } else {
        cout << "Encontrados: " << resultados.size() << " componente(s)\n\n";
        
        ExibidorComponente exibidor;
        for (const auto& comp : resultados) {
            exibidor.exibir(comp);
            cout << "\n";
        }
    }
    
    pausar();
}

void editarComponente(GerenciadorComponentes& gerenciador) {
    limparTela();
    

    cout << "        EDITAR COMPONENTE              \n";
    
    int total = gerenciador.obterTamanho();
    
    if (total == 0) {
        cout << "Nenhum componente cadastrado para editar.\n";
        pausar();
        return;
    }
    
    cout << "Componentes disponiveis:\n\n";
    vector<dadosCSV> componentes = gerenciador.obterComponentes();
    
    for (int i = 0; i < total; i++) {
        cout << "[" << i << "] " << componentes[i].codigo 
             << " - " << componentes[i].modelo << "\n";
    }
    
    cout << "\nDigite o indice do componente a editar (-1 para cancelar): ";
    int indice;
    cin >> indice;
    limparBuffer();
    
    if (indice == -1) {
        return;
    }
    
    if (indice < 0 || indice >= total) {
        cout << "invalido!\n";
        pausar();
        return;
    }
    
    dadosCSV compAtual = gerenciador.obterPorIndice(indice);
    dadosCSV novosDados = compAtual;
    
    cout << "\nEditando componente\n";
    cout << "(Pressione ENTER para manter o valor atual)\n\n";
    
    string entrada;
    
    cout << "Codigo atual [" << compAtual.codigo << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.codigo = entrada;
    
    cout << "Tipo atual [" << compAtual.tipoComponente << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.tipoComponente = entrada;
    
    cout << "Modelo atual [" << compAtual.modelo << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.modelo = entrada;
    
    cout << "Valor atual [" << compAtual.valor << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.valor = entrada;
    
    cout << "Atributo 1 atual [" << compAtual.atributo1 << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.atributo1 = entrada;
    
    cout << "Atributo 2 atual [" << compAtual.atributo2 << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.atributo2 = entrada;
    
    cout << "Atributo 3 atual [" << compAtual.atributo3 << "]: ";
    getline(cin, entrada);
    if (!entrada.empty()) novosDados.atributo3 = entrada;
    
    cout << "\nConfirmar alteracoes? (S/N): ";
    char confirma;
    cin >> confirma;
    limparBuffer();
    
    if (confirma == 'S' || confirma == 's') {
        gerenciador.editar(indice, novosDados);
    } else {
        cout << "Edicao cancelada.\n";
    }
    
    pausar();
}

void removerComponente(GerenciadorComponentes& gerenciador) {
    limparTela();
    
    cout << "        REMOVER COMPONENTE             \n";
    
    int total = gerenciador.obterTamanho();
    
    if (total == 0) {
        cout << "Nenhum componente cadastrado para remover.\n";
        pausar();
        return;
    }
    
    cout << "Componentes cadastrados:\n\n";
    vector<dadosCSV> componentes = gerenciador.obterComponentes();
    
    for (int i = 0; i < total; i++) {
        cout << "[" << i << "] " << componentes[i].codigo 
             << " - " << componentes[i].tipoComponente 
             << " - " << componentes[i].modelo << "\n";
    }
    
    cout << "\nDigite o indice do componente a remover (-1 para cancelar): ";
    int indice;
    cin >> indice;
    limparBuffer();
    
    if (indice == -1) {
        return;
    }
    
    if (indice < 0 || indice >= total) {
        cout << "invalido!\n";
        pausar();
        return;
    }
    
    cout << "\nComponente selecionado:\n";
    ExibidorComponente exibidor;
    exibidor.exibir(componentes[indice]);
    
    cout << "\nTem certeza que deseja remover? (S/N): ";
    char confirma;
    cin >> confirma;
    limparBuffer();
    
    if (confirma == 'S' || confirma == 's') {
        gerenciador.remover(indice);
    } else {
        cout << "[INFO] Remocao cancelada.\n";
    }
    
    pausar();
}
