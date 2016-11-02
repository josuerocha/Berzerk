#pragma once
#include "EfeitosVisuais.h"
class AnimacaoMorte : public EfeitosVisuais
{
private:
	int morteCont;
	std::vector <Coord*> vetorPontos;
public:
	AnimacaoMorte();
	~AnimacaoMorte();
	virtual void Display();
	void Reset();
};

