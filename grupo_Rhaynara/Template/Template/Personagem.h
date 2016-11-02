#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "Estruturas.h"
#include "FuncoesExtra.h"

/*Classe abstrata herdada por Player e por Enemy*/
class Personagem{
public:
	Coord c;
	Dimensao d;
	bool isActive;
	float velocidade;
	float hp;
	float hpOriginal;
	Cor cor;

	Personagem();
	Personagem(Coord c, Dimensao d,int velocidade, int hp, Cor cor);	
	~Personagem();
	void IncX(int value,bool podeMover);
	void IncY(int value, bool podeMover);
	void IncHP(float value);
	void DecHP(float value);
	void Kill();
	bool getIsActive();
	int getHP();
	Coord Centro();
	Coord getC();
	void setC(Coord c);

	Dimensao getD();
	void setD(Dimensao d);

	void Display();
	void Rotaciona(float teta);
};

#endif