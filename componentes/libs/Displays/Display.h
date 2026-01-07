/*
Programa: Classe Display (Classe Base Abstrata)
arquivo: Display.h
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "../Dados.h" 

class Display {
public:
    // **Virtual Puro:** A declaracao esta aqui, mas a implementacao e zero (abstrata).
    // Isso obriga as filhas a implementarem sua propria versao.
    virtual struct dadosCSV Cadastrar() = 0; // Apenas a assinatura, sem corpo
    virtual struct dadosCSV Mostrar() = 0;   // Apenas a assinatura, sem corpo
    
    // O destrutor DEVE ser virtual
    virtual ~Display() = default; 
};

#endif // DISPLAY_H