#include "Eletrolitico.h"
#include <iostream>
using namespace std;

void Eletrolitico::Cadastrar() {
    cout << "\n=== Cadastro Capacitor Eletrolítico ===\n";

    cout << "Código: ";
    cin >> codigo;

    cout << "Capacitância (uF): ";
    cin >> capacitancia;

    cout << "Tensão (V): ";
    cin >> tensao;

    cout << "Temperatura (°C): ";
    cin >> temperatura;

    cout << "É polarizado? (1=sim, 0=nao): ";
    cin >> polarizado;
}

void Eletrolitico::Exibir() const {
    cout << "\n--- CAPACITOR ELETROLÍTICO ---\n";
    cout << "Código: " << codigo << endl;
    cout << "Capacitância: " << capacitancia << " uF\n";
    cout << "Tensão: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Polarizado: " << (polarizado ? "Sim" : "Não") << endl;
}
