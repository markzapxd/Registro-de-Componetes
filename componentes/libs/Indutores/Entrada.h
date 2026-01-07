#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>

class Entrada {
private:
    std::string mensagem;

public:
    Entrada();
    Entrada(const std::string &msg);
    
    void setMensagem(const std::string &msg);
    std::string ler();
    std::string lerComMensagem(const std::string &msg);
};

#endif
