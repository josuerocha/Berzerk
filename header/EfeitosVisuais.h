#pragma once
#include <vector>
#include <GL/glut.h>
#include <Utilities.h>
#include "Estruturas.h"
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