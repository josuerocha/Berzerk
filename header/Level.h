#ifndef Level_h
#define Level_h

// STANDARD INCLUDES
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

//CUSTOM INCLUDES
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
	int xponto; int yponto;
	int xponto2; int yponto2;
	int percorreLinha;
	int percorreColuna;

	int xpontoparedeEsq; int ypontoparedeEsq;
	int ypontoparede2;
	int xpontoparedeDirIn; int xpontoparedeDirFin;

	int vetCores[50];

	int qtdLinhas;
	int qtdColunas;
	int linha;
	int coluna;


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
	bool isDigit( char c );
	void MapeiaFase();
	Coord getPlayerPosition();
	int getQtdInimigos();
	void DecQtdInimigos();
};

#endif
