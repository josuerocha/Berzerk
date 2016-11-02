#ifndef Projectile_h
#define Projectile_h
#include <math.h>
#include "Estruturas.h"
#include <GL/glut.h>
#pragma once
class Projectile{
public:
	Coord c;
	Coord vetor;
	Dimensao d;
	Cor cor;
	float velocity;
	int alcance, dano;
	bool isActive;
	Projectile();
	Projectile(Coord r, Coord vect, Dimensao d, int alcanc, int dano, float velocity, bool isActive,Cor cor);
	Coord getC();
	void setC(Coord c);
	Coord getVetor();
	void setVetor(Coord c);
	float getVelocity();
	void setVelocity(float velocity);
	float getIsActive();
	void Activate();
	void Deactivate();
	int getDano();
	void setDano(int dano);
	int getAlcance();
	void setAlcance(int alcance);
	void Display();
	~Projectile();
};
#endif