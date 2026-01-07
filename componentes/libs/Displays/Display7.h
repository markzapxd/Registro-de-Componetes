/*
Programa: Classe Display7
arquivo: Display7.h
*/

#ifndef DISPLAY7_H
#define DISPLAY7_H

#include "Display.h"
#include "../Dados.h"

class Display7 : public Display{
	
	private:
		std::string obterCodigo();
		std::string obterValor();
		std::string obterPadrao();//atributo1 anodo ou catodo
		std::string obterCor();//atributo2
		std::string obterDigitos();//atributo3
		struct dadosCSV dados;
	
	public:
		Display7();//construtor
	
		struct dadosCSV Cadastrar() override;
		struct dadosCSV Mostrar() override;
	
		~Display7() override; // destrutor
};


#endif // DISPLAY7_H