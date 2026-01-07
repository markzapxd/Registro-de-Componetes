#include "UnidadeIndutancia.h"
#include <algorithm>
#include <cctype>
#include <string>

UnidadeIndutancia::UnidadeIndutancia() : unidade("H") {}

UnidadeIndutancia::UnidadeIndutancia(const std::string &unid) : unidade(unid) {}

void UnidadeIndutancia::setUnidade(const std::string &unid) {
    unidade = unid;
}

std::string UnidadeIndutancia::getUnidade() {
    return unidade;
}

ResultadoIndutancia UnidadeIndutancia::interpretar(const std::string &orig) {
    std::string txt = orig;
    txt.erase(std::remove_if(txt.begin(), txt.end(), ::isspace), txt.end());

    if (txt.empty()) return {false, 0.0};

    size_t pos = 0;
    while (pos < txt.size() && (isdigit(txt[pos]) || txt[pos] == '.' || txt[pos] == ',')) pos++;

    std::string numStr = txt.substr(0, pos);
    std::string unidadeExtraida = txt.substr(pos);

    double num;
    try { num = std::stod(numStr); } 
    catch (...) { return {false, 0.0}; }

    for (char &c : unidadeExtraida) c = tolower(c);

    if (unidadeExtraida == "" || unidadeExtraida == "h") return {true, num};
    if (unidadeExtraida == "mh") return {true, num * 1e-3};
    if (unidadeExtraida == "uh") return {true, num * 1e-6};
    if (unidadeExtraida == "nh") return {true, num * 1e-9};

    return {false, 0.0};
}

std::string UnidadeIndutancia::formatar(double h) {
    if (h >= 1) return std::to_string(h) + " H";
    if (h >= 1e-3) return std::to_string(h * 1e3) + " mH";
    if (h >= 1e-6) return std::to_string(h * 1e6) + " uH";
    if (h >= 1e-9) return std::to_string(h * 1e9) + " nH";
    return std::to_string(h) + " H";
}
