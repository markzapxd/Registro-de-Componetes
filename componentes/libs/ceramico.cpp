#include "Ceramico.h"
#include <iostream>
using namespace std;

void Ceramico::Cadastrar() {
    cout << "\n=== Cadastro Capacitor Cerâmico ===\n";

    cout << "Código: ";
    cin >> codigo;

    cout << "Capacitância (uF): ";
    cin >> capacitancia;

    cout << "Tensão (V): ";
    cin >> tensao;

    cout << "Temperatura (°C): ";
    cin >> temperatura;

    cout << "Tipo de dielétrico: ";
    cin >> dieletrico;
}

void Ceramico::Exibir() const {
    cout << "\n--- CAPACITOR CERÂMICO ---\n";
    cout << "Código: " << codigo << endl;
    cout << "Capacitância: " << capacitancia << " uF\n";
    cout << "Tensão: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Dielétrico: " << dieletrico << endl;
}
