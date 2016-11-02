#pragma once
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "Estruturas.h"
#include "FuncoesExtra.h"
class MainMenu
{
public:
	/*	************** VARIÁVEIS DE MENU *****************/
	bool emJogo;
	bool emTela;
	bool emMenu;
	bool emMenuPrincipal;
	bool inicia;
	bool opcao;

	//FLAGS DE FUNÇOES
	bool iniciarMenuButton;
	bool opcaoMenuButton;
	bool desenharMenuButton;
	bool sairButton;

	//MOUSE
	bool clickAtivo;
	Coord mouse;

	MainMenu();
	~MainMenu();
	void Run();
	void DesenhaTextoMenu(char * string, Coord c);
	void DesenhaInstrucoes(char * string, Coord c);
	void DesenhaInstrucoesBloco(char * string, Coord c);
	void OpcaoMenu();
	void IniciarJogo();
	void Display();
	void OpcaoClick(int op);
	void PosicaoMenu();
};

