#include "Tantalum.h"
#include <iostream>
using namespace std;

void Tantalum::Cadastrar() {
    cout << "\n=== Cadastro Capacitor de Tântalo ===\n";

    cout << "Código: ";
    cin >> codigo;

    cout << "Capacitância (uF): ";
    cin >> capacitancia;

    cout << "Tensão (V): ";
    cin >> tensao;

    cout << "Temperatura (°C): ";
    cin >> temperatura;

    cout << "Encapsulamento: ";
    cin >> encapsulamento;
}

void Tantalum::Exibir() const {
    cout << "\n--- CAPACITOR DE TÂNTALO ---\n";
    cout << "Código: " << codigo << endl;
    cout << "Capacitância: " << capacitancia << " uF\n";
    cout << "Tensão: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Encapsulamento: " << encapsulamento << endl;
}
