#pragma once

//STANDARD INCLUDES
#include <vector>
#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>
#include <string>

//CUSTOM INCLUDES
#include "Estruturas.h"
#include "EfeitosVisuais.h"

//DEFINITIONS

#define SPEED 0.7


class Explosao : public EfeitosVisuais {

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

