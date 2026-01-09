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

int main() {
    GerenciadorComponentes gerenciadorComponentes("componentes.csv");
    ExibidorComponente exibidorComponente;
    
    int opcaoMenuPrincipal;
    int opcaoTipoComponente;
    int opcaoBusca;
    dadosCSV dadosComponente;
    dadosCSV dadosCadastro;
    bool componenteCadastrado = false;
    string entradaUsuario;
    char respostaUsuario;
    char confirmacaoUsuario;
    int indiceComponente;
    int totalComponentes;
    vector<dadosCSV> listaComponentes;
    vector<dadosCSV> resultadosBusca;
    
    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
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
        
        cout << "Escolha uma opcao: ";
        cin >> opcaoMenuPrincipal;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcaoMenuPrincipal = -1;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch (opcaoMenuPrincipal) {
            case 1:
                componenteCadastrado = false;
                
                do {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif
                    
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
                    
                    cout << "Escolha uma opcao: ";
                    cin >> opcaoTipoComponente;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        opcaoTipoComponente = -1;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    
                    switch (opcaoTipoComponente) {
                        case 1: {
                            IndutorToroidal indutorToroidal;
                            DadosCSV dadosIndutor = indutorToroidal.cadastrar();
                            dadosCadastro.codigo = dadosIndutor.codigo;
                            dadosCadastro.tipoComponente = dadosIndutor.tipo;
                            dadosCadastro.modelo = dadosIndutor.modelo;
                            dadosCadastro.valor = dadosIndutor.valor;
                            dadosCadastro.atributo1 = dadosIndutor.atributo1;
                            dadosCadastro.atributo2 = dadosIndutor.atributo2;
                            dadosCadastro.atributo3 = dadosIndutor.atributo3;
                            dadosComponente = dadosCadastro;
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                indutorToroidal.mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 2: {
                            IndutorBobinaAr indutorBobinaAr;
                            DadosCSV dadosIndutor = indutorBobinaAr.cadastrar();
                            dadosCadastro.codigo = dadosIndutor.codigo;
                            dadosCadastro.tipoComponente = dadosIndutor.tipo;
                            dadosCadastro.modelo = dadosIndutor.modelo;
                            dadosCadastro.valor = dadosIndutor.valor;
                            dadosCadastro.atributo1 = dadosIndutor.atributo1;
                            dadosCadastro.atributo2 = dadosIndutor.atributo2;
                            dadosCadastro.atributo3 = dadosIndutor.atributo3;
                            dadosComponente = dadosCadastro;
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                indutorBobinaAr.mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 3: {
                            IndutorFerrite indutorFerrite;
                            DadosCSV dadosIndutor = indutorFerrite.cadastrar();
                            dadosCadastro.codigo = dadosIndutor.codigo;
                            dadosCadastro.tipoComponente = dadosIndutor.tipo;
                            dadosCadastro.modelo = dadosIndutor.modelo;
                            dadosCadastro.valor = dadosIndutor.valor;
                            dadosCadastro.atributo1 = dadosIndutor.atributo1;
                            dadosCadastro.atributo2 = dadosIndutor.atributo2;
                            dadosCadastro.atributo3 = dadosIndutor.atributo3;
                            dadosComponente = dadosCadastro;
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                indutorFerrite.mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 4: {
                            AmplificadorInversor amplificadorInversor;
                            dadosComponente = amplificadorInversor.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                amplificadorInversor.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 5: {
                            AmplificadorNaoInversor amplificadorNaoInversor;
                            dadosComponente = amplificadorNaoInversor.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                amplificadorNaoInversor.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 6: {
                            AmplificadorDiferencial amplificadorDiferencial;
                            dadosComponente = amplificadorDiferencial.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                amplificadorDiferencial.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 7: {
                            Ceramico capacitorCeramico;
                            dadosComponente = capacitorCeramico.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                capacitorCeramico.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 8: {
                            Eletrolitico capacitorEletrolitico;
                            dadosComponente = capacitorEletrolitico.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                capacitorEletrolitico.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 9: {
                            Tantalum capacitorTantalum;
                            dadosComponente = capacitorTantalum.Cadastrar();
                            if (!dadosComponente.codigo.empty() && dadosComponente.codigo != "0") {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                capacitorTantalum.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 10: {
                            Display7 displaySeteSegmentos;
                            dadosComponente = displaySeteSegmentos.Cadastrar();
                            if (!dadosComponente.codigo.empty()) {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                displaySeteSegmentos.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 11: {
                            DisplayLCD displayLiquidoCristal;
                            dadosComponente = displayLiquidoCristal.Cadastrar();
                            if (!dadosComponente.codigo.empty()) {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                displayLiquidoCristal.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 12: {
                            DisplayOLED displayOrganico;
                            dadosComponente = displayOrganico.Cadastrar();
                            if (!dadosComponente.codigo.empty()) {
                                gerenciadorComponentes.adicionar(dadosComponente);
                                displayOrganico.Mostrar();
                                componenteCadastrado = true;
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "\nOpcao invalida!\n";
                    }
                    
                    if (componenteCadastrado) {
                        cout << "\nComponente cadastrado com sucesso!\n";
                        componenteCadastrado = false;
                    }
                    
                } while (opcaoTipoComponente != 0);
                break;
                
            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                
                cout << "      LISTA DE COMPONENTES             \n";
                
                totalComponentes = gerenciadorComponentes.obterTamanho();
                
                if (totalComponentes == 0) {
                    cout << "Nenhum componente cadastrado.\n";
                } else {
                    cout << "Total de componentes: " << totalComponentes << "\n\n";
                    
                    cout << left
                         << setw(8) << "Indice"
                         << setw(12) << "Codigo"
                         << setw(20) << "Tipo"
                         << setw(20) << "Modelo"
                         << setw(15) << "Valor" << "\n";
                    cout << string(75, '-') << "\n";
                    
                    listaComponentes = gerenciadorComponentes.obterComponentes();
                    for (int i = 0; i < totalComponentes; i++) {
                        dadosCSV componenteAtual = listaComponentes[i];
                        cout << left
                             << setw(8) << i
                             << setw(12) << componenteAtual.codigo
                             << setw(20) << componenteAtual.tipoComponente
                             << setw(20) << componenteAtual.modelo
                             << setw(15) << componenteAtual.valor << "\n";
                    }
                    
                    cout << string(75, '-') << "\n";
                    
                    cout << "\nDeseja ver detalhes de algum componente? (S/N): ";
                    cin >> respostaUsuario;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (respostaUsuario == 'S' || respostaUsuario == 's') {
                        cout << "Digite o indice do componente: ";
                        cin >> indiceComponente;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        if (indiceComponente >= 0 && indiceComponente < totalComponentes) {
                            exibidorComponente.exibir(listaComponentes[indiceComponente]);
                        } else {
                            cout << "Indice invalido!\n";
                        }
                    }
                }
                break;
                
            case 3:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                
                cout << "         OPCOES DE BUSCA               \n";
                cout << "\n";
                cout << "  [1] Buscar por codigo\n";
                cout << "  [2] Buscar por tipo\n";
                cout << "  [0] Voltar\n";
                cout << "\n";
                
                cout << "Escolha uma opcao: ";
                cin >> opcaoBusca;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    opcaoBusca = -1;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                resultadosBusca.clear();
                
                switch (opcaoBusca) {
                    case 1: {
                        cout << "\nDigite o codigo do componente: ";
                        string codigoBusca;
                        getline(cin, codigoBusca);
                        resultadosBusca = gerenciadorComponentes.buscarPorCodigo(codigoBusca);
                        break;
                    }
                    case 2: {
                        cout << "\nTipos disponiveis: Indutor, AmplificadorOperacional, Capacitor, Display\n";
                        cout << "Digite o tipo do componente: ";
                        string tipoBusca;
                        getline(cin, tipoBusca);
                        resultadosBusca = gerenciadorComponentes.buscarPorTipo(tipoBusca);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Invalido!\n";
                        break;
                }
                
                if (opcaoBusca == 1 || opcaoBusca == 2) {
                    cout << "       RESULTADOS DA BUSCA             \n";
                    
                    if (resultadosBusca.empty()) {
                        cout << "Nenhum encontrado.\n";
                    } else {
                    
                        cout << "Encontrados: " << resultadosBusca.size() << " componente(s)\n\n";
                        
                        for (int i = 0; i < (int)resultadosBusca.size(); i++) {
                            exibidorComponente.exibir(resultadosBusca[i]);
                            cout << "\n";
                        }
                    }
                }
                break;
                
            case 4:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                
                cout << "        EDITAR COMPONENTE              \n";
                
                totalComponentes = gerenciadorComponentes.obterTamanho();
                
                if (totalComponentes == 0) {
                    cout << "Nenhum componente cadastrado para editar.\n";
                } else {
                    cout << "Componentes disponiveis:\n\n";
                    listaComponentes = gerenciadorComponentes.obterComponentes();
                    
                    for (int i = 0; i < totalComponentes; i++) {
                        cout << "[" << i << "] " << listaComponentes[i].codigo 
                             << " - " << listaComponentes[i].modelo << "\n";
                    }
                    
                    cout << "\nDigite o indice do componente a editar (-1 para cancelar): ";
                    cin >> indiceComponente;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (indiceComponente != -1) {
                        if (indiceComponente < 0 || indiceComponente >= totalComponentes) {
                            cout << "invalido!\n";
                        } else {
                            dadosCSV componenteAtual = gerenciadorComponentes.obterPorIndice(indiceComponente);
                            dadosCSV novosDadosComponente = componenteAtual;
                            
                            cout << "\nEditando componente\n";
                            cout << "(Pressione ENTER para manter o valor atual)\n\n";
                            
                            cout << "Codigo atual [" << componenteAtual.codigo << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.codigo = entradaUsuario;
                            
                            cout << "Tipo atual [" << componenteAtual.tipoComponente << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.tipoComponente = entradaUsuario;
                            
                            cout << "Modelo atual [" << componenteAtual.modelo << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.modelo = entradaUsuario;
                            
                            cout << "Valor atual [" << componenteAtual.valor << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.valor = entradaUsuario;
                            
                            cout << "Atributo 1 atual [" << componenteAtual.atributo1 << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.atributo1 = entradaUsuario;
                            
                            cout << "Atributo 2 atual [" << componenteAtual.atributo2 << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.atributo2 = entradaUsuario;
                            
                            cout << "Atributo 3 atual [" << componenteAtual.atributo3 << "]: ";
                            getline(cin, entradaUsuario);
                            if (!entradaUsuario.empty()) novosDadosComponente.atributo3 = entradaUsuario;
                            
                            cout << "\nConfirmar alteracoes? (S/N): ";
                            cin >> confirmacaoUsuario;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            
                            if (confirmacaoUsuario == 'S' || confirmacaoUsuario == 's') {
                                gerenciadorComponentes.editar(indiceComponente, novosDadosComponente);
                            } else {
                                cout << "Edicao cancelada.\n";
                            }
                        }
                    }
                }
                break;
                
            case 5:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                
                cout << "        REMOVER COMPONENTE             \n";
                
                totalComponentes = gerenciadorComponentes.obterTamanho();
                
                if (totalComponentes == 0) {
                    cout << "Nenhum componente cadastrado para remover.\n";
                } else {
                    cout << "Componentes cadastrados:\n\n";
                    listaComponentes = gerenciadorComponentes.obterComponentes();
                    
                    for (int i = 0; i < totalComponentes; i++) {
                        cout << "[" << i << "] " << listaComponentes[i].codigo 
                             << " - " << listaComponentes[i].tipoComponente 
                             << " - " << listaComponentes[i].modelo << "\n";
                    }
                    
                    cout << "\nDigite o indice do componente a remover (-1 para cancelar): ";
                    cin >> indiceComponente;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (indiceComponente != -1) {
                        if (indiceComponente < 0 || indiceComponente >= totalComponentes) {
                            cout << "invalido!\n";
                        } else {
                            cout << "\nComponente selecionado:\n";
                            exibidorComponente.exibir(listaComponentes[indiceComponente]);
                            
                            cout << "\nTem certeza que deseja remover? (S/N): ";
                            cin >> confirmacaoUsuario;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            
                            if (confirmacaoUsuario == 'S' || confirmacaoUsuario == 's') {
                                gerenciadorComponentes.remover(indiceComponente);
                            } else {
                                cout << "[INFO] Remocao cancelada.\n";
                            }
                        }
                    }
                }
                break;
                
            case 0:
                cout << "\nSalvando dados\n";
                break;
            default:
                cout << "\ninvalido!\n";
        }
    } while (opcaoMenuPrincipal != 0);
    
    return 0;
}
