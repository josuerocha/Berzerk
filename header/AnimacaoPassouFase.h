#pragma once
#include "EfeitosVisuais.h"
#include <cstring>
#include <string>

class AnimacaoPassouFase : public EfeitosVisuais
{
	std::vector <Coord*> vetorPontos;
public:
	int animacaoCont;
	AnimacaoPassouFase(int numFase);
	~AnimacaoPassouFase();
	void setNumFase();
	void Reset();
	void Display(int numFase);
};

