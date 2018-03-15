#ifndef Enemy_h
#define Enemy_h
#include <Utilities.h>
#include "Personagem.h"
#include "Estruturas.h"

class Enemy : public Personagem {
public:
	int raioVisao;
	int tipo;
	int scoreWorth;
	Enemy();
	Enemy(Coord c, Dimensao d, float velocidade, int hp, int raioVisao, int tipo, Cor cor);
	Enemy(Coord c, int tipo);
	~Enemy();


	Coord followPlayer(Coord * coordJogador);
	void move(Coord * c, bool podeMover);
	void kill();
	int getScoreWorth();

	//DISPLAY FUNCTIONS
	void drawHPBar(float healthPercentage);
	void display();

};

#endif
