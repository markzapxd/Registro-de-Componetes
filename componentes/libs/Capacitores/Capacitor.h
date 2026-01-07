#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "../Dados.h"
#include <string>

class Capacitor {
protected:
    std::string codigoStr;
    double capacitancia;
    double tensao;
    double temperatura;

public:
    Capacitor() : capacitancia(0), tensao(0), temperatura(0) {}
    virtual ~Capacitor() {}

    // Encapsulamento
    void setCodigo(const std::string& c) { codigoStr = c; }
    void setCapacitancia(double c) { capacitancia = c; }
    void setTensao(double t) { tensao = t; }
    void setTemperatura(double temp) { temperatura = temp; }

    std::string getCodigo() const { return codigoStr; }
    double getCapacitancia() const { return capacitancia; }
    double getTensao() const { return tensao; }
    double getTemperatura() const { return temperatura; }

    // Métodos polimórficos - agora retornam dadosCSV
    virtual dadosCSV Cadastrar() = 0;
    virtual dadosCSV Mostrar() = 0;
};

#endif
