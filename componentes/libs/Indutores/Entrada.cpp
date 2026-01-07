#include "Entrada.h"
#include <iostream>

Entrada::Entrada() : mensagem("") {}

Entrada::Entrada(const std::string &msg) : mensagem(msg) {}

void Entrada::setMensagem(const std::string &msg) {
    mensagem = msg;
}

std::string Entrada::ler() {
    std::cout << mensagem;
    std::string texto;
    std::getline(std::cin, texto);
    return texto;
}

std::string Entrada::lerComMensagem(const std::string &msg) {
    std::cout << msg;
    std::string texto;
    std::getline(std::cin, texto);
    return texto;
}
