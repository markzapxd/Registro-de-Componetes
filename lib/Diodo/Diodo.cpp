#include "Diodo.h"
#include <iostream>

Diodo::Diodo() {
    tipoComponente = "Diodo";
}

dadosCSV Diodo::Mostrar() {
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = valor;
    return dados;
}
