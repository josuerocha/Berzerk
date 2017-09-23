#pragma once
#include "Estruturas.h"
#include <vector>
#include <GL/glut.h>
#include <iostream>
#include "EfeitosVisuais.h"
#include <GL/freeglut.h>
#include <string>
class Explosao : public EfeitosVisuais
{
public:
	std::vector <Coord*> vetorPontos;
	bool decrementa;
	float limite;
	float size;
	Explosao();
	Explosao(Coord c, std::string tamanho);
	~Explosao();
	virtual void Display();
};

