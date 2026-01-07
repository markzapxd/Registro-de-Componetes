/*
Programa: Classe DisplayOLED
arquivo: DisplayOLED.h
*/


#ifndef DISPLAYOLED_H
#define DISPLAYOLED_H

#include "Display.h"
#include "../Dados.h"

class DisplayOLED : public Display{
	
	private:
		std::string obterCodigo();
		std::string obterValor();
		std::string obterInterface();//atributo1
		std::string obterResolucao();//atributo2
		std::string obterCor();//atributo3
		struct dadosCSV dados;
	
	
	public:
		DisplayOLED();//construtor
	
		struct dadosCSV Cadastrar() override;
		struct dadosCSV Mostrar() override;
	
		~DisplayOLED() override; // destrutor
};


#endif // DISPLAYOLED_H