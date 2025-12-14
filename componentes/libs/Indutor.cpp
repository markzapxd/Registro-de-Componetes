#include "Indutor.h"
#include "Entrada.h"
#include <iostream>
#include <algorithm>
#include <cctype>

std::string Indutor::solicitarString(const std::string &mensagem, int tamanhoMinimo) {
    Entrada entrada;
    while (true) {
        std::string s = entrada.lerComMensagem(mensagem);
        if (s.empty()) {
            std::cout << "Campo nao pode ficar sem nada\n";
            continue;
        }
        if (static_cast<int>(s.size()) < tamanhoMinimo) {
            std::cout << "minimo de " << tamanhoMinimo << " caracteres\n";
            continue;
        }
        return s;
    }
}

int Indutor::solicitarIntRange(const std::string &mensagem, int minVal, int maxVal) {
    Entrada entrada;
    while (true) {
        std::string s = entrada.lerComMensagem(mensagem);
        try {
            int v = std::stoi(s);
            if (v < minVal || v > maxVal) {
                std::cout << "Valor fora da faixa (" << minVal << " a " << maxVal << ")!\n";
                continue;
            }
            return v;
        } catch (...) {
            std::cout << "digite um numero inteiro valid\n";
        }
    }
}

double Indutor::solicitarDoubleRange(const std::string &mensagem, double minVal, double maxVal) {
    Entrada entrada;
    while (true) {
        std::string s = entrada.lerComMensagem(mensagem);
        try {
            double v = std::stod(s);
            if (v < minVal || v > maxVal) {
                std::cout << "Valor fora da faixa (" << minVal << " a " << maxVal << ")!\n";
                continue;
            }
            return v;
        } catch (...) {
            std::cout << "digite um numero decimal valido\n";
        }
    }
}

std::string Indutor::solicitarMaterial(const std::string &mensagem, const std::vector<std::string> &permitidos) {
    Entrada entrada;
    while (true) {
        std::string s = entrada.lerComMensagem(mensagem);
        std::string sl = s;
        std::transform(sl.begin(), sl.end(), sl.begin(), [](unsigned char c){ return std::tolower(c); });
        for (const auto &p : permitidos) {
            std::string pl = p;
            std::transform(pl.begin(), pl.end(), pl.begin(), [](unsigned char c){ return std::tolower(c); });
            if (sl == pl) return p; // return canonical permitted string
        }
        std::cout << "Não tem esse material. Opcoes: ";
        for (size_t i = 0; i < permitidos.size(); ++i) {
            std::cout << permitidos[i];
            if (i + 1 < permitidos.size()) std::cout << ", ";
        }
        std::cout << ".\n";
    }
}
