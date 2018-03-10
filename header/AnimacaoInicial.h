#pragma once
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <Utilities.h>

class AnimacaoInicial
{
public:
	//VARI�VEIS DA ANIMA��O
	int x1;
	int yaa;
	int py ;
	int x2 ;
	int y2 ;
	int x3 ;
	int y3 ;
	int x4 ;
	int y4;
	int x5;
	int y5;
	int x6;
	int y6;
	int x7;
	int y7;
	int x8;
	int y8;
	int x9;
	int y9;
	int x10;
	int y10;
	int x11;
	int y11;
	int x12;
	int y12;

	float fps;
	float tempomaximo;
	float tempo;
	float tempoapresentacao;
	float tempoTotal;

	bool emAnimacao;

	bool Run();
	~AnimacaoInicial();
	void EscreveSubida(char * string, int px, int velocidade);
	void Animacao(void);
	AnimacaoInicial();

};

