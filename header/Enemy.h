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
	Coord FollowPlayer(Coord * coordJogador);
	void Move(Coord * c, bool podeMover);
	void Kill();
	void Display();
	int getScoreWorth();
	~Enemy();
};

#endif
