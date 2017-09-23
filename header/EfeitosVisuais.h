#pragma once
#include <vector>
#include <GL/glut.h>
#include "Estruturas.h"
#include "FuncoesExtra.h"
#include <iostream>
class EfeitosVisuais
{
public:
	bool isActive;
	Coord c;
	Cor cor;
	EfeitosVisuais();
	~EfeitosVisuais();
	virtual void Display();
};