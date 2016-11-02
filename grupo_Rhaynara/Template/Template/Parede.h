#pragma once
#include "Estruturas.h"
#include <GL/glut.h>
class Parede
{
public:
	Coord c;
	Dimensao d;
	Cor cor1, cor2;


	Parede();
	Parede(Coord c, Dimensao d, Cor cor1, Cor cor2);
	~Parede();
	void Display();
};

