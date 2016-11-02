
#ifndef Medkit_h
#define Medkit_h
#pragma once
#include "Coletavel.h"

class Medkit : public Coletavel {
public:
	float cura;

	Medkit();
	Medkit(Coord coord, Cor cor, Dimensao dim, bool status, int cura);

	virtual float getCura();

	void onCollectAction(Player * p);

};

#endif