#ifndef Pensonagem_h
#define Pensonagem_h
#include "Personagem.h"
#pragma once
class Player : public Personagem{
private:
	int vidas;
	int tirosEspeciais;

	Coord cBackup;
	Dimensao dBackup;
	bool isActiveBackup;
	float velocidadeBackup;
	float hpBackup;
	float hpOriginalBackup;
	Cor corBackup;
	int vidasBackup;
	int tirosEspeciaisBackup;

public:
	Player();
	Player(Coord c, Dimensao d, int velocidade, float hp, Cor cor, int vidas, int tiros);
	~Player();
	void Kill();
	void Display();
	void onMedikitCollectAction(float cura);
	int getVidas();
	void Reset();
	void ResetVidas();
	void decTirosEspeciais();
	int getTiros();
};

#endif