#pragma once
#include "EfeitosVisuais.h"
class AnimacaoGameOver : public EfeitosVisuais
{
public:
	int efeitoCont;
	std::vector <Coord*> vetorPontos;
	AnimacaoGameOver();
	~AnimacaoGameOver();
	void Display();
	void Reset();
};

