#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <string>

class Capacitor {
protected:
    std::string codigo;
    double capacitancia;
    double tensao;
    double temperatura;

public:
    Capacitor() : capacitancia(0), tensao(0), temperatura(0) {}
    virtual ~Capacitor() {}

    // Encapsulamento
    void setCodigo(const std::string& c) { codigo = c; }
    void setCapacitancia(double c) { capacitancia = c; }
    void setTensao(double t) { tensao = t; }
    void setTemperatura(double temp) { temperatura = temp; }

    std::string getCodigo() const { return codigo; }
    double getCapacitancia() const { return capacitancia; }
    double getTensao() const { return tensao; }
    double getTemperatura() const { return temperatura; }

    // Métodos polimórficos
    virtual void Cadastrar() = 0;
    virtual void Exibir() const = 0;
};

#endif
