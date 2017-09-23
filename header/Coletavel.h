#ifndef Coletavel_h
#define Coletavel_h
#include <math.h>
#include "Player.h"
#include "Estruturas.h"
#include <GL/glut.h>
#pragma once

class Coletavel {
public:
	Coord c;
	Cor cor;
	Dimensao d;
	bool active;
	Coletavel();
	Coletavel(Coord c, Cor cor, Dimensao d, bool status);
	float cura;
	void Display();
	void Dispose();

	virtual float getCura();
};
#endif