/*
Programa: Classe DisplayLCD
arquivo: DisplayLCD.h
*/

#ifndef DISPLAYLCD_H
#define DISPLAYLCD_H

#include "Display.h"
#include "../Dados.h"

class DisplayLCD : public Display{
	
	private:
		
		std::string obterCodigo(); // será valido se for um inteiro
		std::string obterValor(); // será valido se for um valor positivo
		std::string obterBacklight();//atributo1
		std::string obterColunas();//atributo2
		std::string obterDimensoes();//atributo3
		struct dadosCSV dados;
	
	public:
		DisplayLCD();//construtor
	
		struct dadosCSV Cadastrar() override;
		struct dadosCSV Mostrar() override;
	
		~DisplayLCD() override; // destrutor
};


#endif // DISPLAYLCD_H