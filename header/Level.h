#ifndef Level_h
#define Level_h

#pragma once
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Estruturas.h"
#include "Medkit.h"
#include "Parede.h"

class Level
{
private:
	Coord playerPosicao;
	int qtdInimigos;
	int tipo;
	int xponto = 100; int yponto = 300;
	int xponto2 = 740; int yponto2 = 200;
	int percorreLinha = 0;
	int percorreColuna = 0;

	int xpontoparedeEsq = 25; int ypontoparedeEsq = 50;
	int ypontoparede2 = 550;
	int xpontoparedeDirIn = 1040; int xpontoparedeDirFin = 740;

	int vetCores[50];

	int qtdLinhas = 26;
	int qtdColunas = 50;
	int linha = 0;
	int coluna = 0;


public:
	int contParedes;

	//Vectors de inimigos e paredes
	std::vector <Enemy*> vetorInimigos;
	std::vector <Parede*> vetorParede;
	std::vector <Coletavel*> vetorColetaveis;

	int matTela[26][50];
	Level();
	~Level();
	Level(int tipo);
	void DesenhaFase();
	void LerArquivo(std::string url);
	void MapeiaFase();
	Coord getPlayerPosition();
	int getQtdInimigos();
	void DecQtdInimigos();
};

#endif
