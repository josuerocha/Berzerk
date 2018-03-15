#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Coord c, Dimensao d, float velocidade, int hp, int raioVisao, int tipo, Cor cor)
{	this->c = c;
	this->d = d;
	this->velocidade = velocidade;
	this->hp = hp;
	this->cor = cor;
	this->tipo = tipo;
	this->raioVisao = raioVisao;
	this->scoreWorth = hp;
}

Enemy::Enemy(Coord c,int tipo) {
	this->isActive = true;
	this->c = c;
	switch (tipo){
		case 1:
			this->d = Dimensao(25, 25);
			this->velocidade = 0.25;
			this->hp = 40;
			this->cor = Cor(1, 3.6, 0.2);
			this->tipo = tipo;
			this->raioVisao = 500;
			this->scoreWorth = this->hp;
			this->hpOriginal = this->hp;
		break;

		case 2:
			this->d = Dimensao(15, 15);
			this->velocidade = 1.2;
			this->hp = 30;
			this->cor = Cor(0,0.5 , 1);
			this->tipo = tipo;
			this->raioVisao = 500;
			this->scoreWorth = this->hp;
			this->hpOriginal = this->hp;
		break;

		case 3:
			this->d = Dimensao(30, 30);
			this->velocidade = 0.2;
			this->hp = 30;
			this->cor = Cor(1, 0 , 1);
			this->tipo = tipo;
			this->raioVisao = 300;
			this->scoreWorth = this->hp;
			this->hpOriginal = this->hp;
		break;

		case 4:
			this->d = Dimensao(30, 30);
			this->velocidade = 0.25;
			this->hp = 70;
			this->cor = Cor(0, 0 ,0.501961);
			this->tipo = tipo;
			this->raioVisao = 200;
			this->scoreWorth = this->hp;
			this->hpOriginal = this->hp;
		break;

		case 5:
			this->d = Dimensao(70, 70);
			this->velocidade = 0.20;
			this->hp = 300;
			this->cor = Cor(1, 0, 0.1);
			this->tipo = tipo;
			this->raioVisao = 300;
			this->scoreWorth = this->hp;
			this->hpOriginal = this->hp;
		break;
	}

}

Coord Enemy::followPlayer(Coord* coordJogador) {

	Coord novaCoordenada;
	if (pow(this->c.x - coordJogador->x, 2) + pow(this->c.y - coordJogador->y, 2) <= pow(raioVisao, 2)) {
		Coord vetor = Utilities::calculateUnitVector(&this->c, coordJogador);

		novaCoordenada.x = vetor.x * this->velocidade + this->c.x;
		novaCoordenada.y = vetor.y * this->velocidade + this->c.y;
	}

	return novaCoordenada;
}

void Enemy::move(Coord* c,bool podeMover) {
	if(c->x > 0 || c->y > 0){
		if (podeMover) {
			this->c = *c;
		}
	}
}

void Enemy::kill() {
	isActive = false;
}

void Enemy::display() {
	if (hp <= 0) {
		kill();
	}else{
		switch (tipo){
			case 1:
				glBegin(GL_QUADS);
				glColor3f(cor.r, cor.g, cor.b);
				glPushMatrix();
				glVertex2f(c.x, c.y);
				glVertex2f(c.x + d.largura, c.y);
				glVertex2f(c.x + d.largura, c.y + d.altura);
				glVertex2f(c.x, c.y + d.altura);
				glPopMatrix();
				glEnd();
			break;

			case 2:
				glColor3f(cor.r, cor.g, cor.b);
				glBegin(GL_TRIANGLES);
				glColor3f(cor.r, cor.g, cor.b);
				glVertex2f(c.x, c.y+d.altura);
				glVertex2f(Centro().x,Centro().y - (d.altura / 2));
				glVertex2f(c.x + d.largura,c.y+ d.altura);
				glEnd();
			break;

			case 3:
				glColor3f(cor.r, cor.g, cor.b);
				Utilities::drawCircle(Centro(), d.largura / 2, 6); //Desenha hexagono
			break;

			case 4:
				glColor3f(cor.r, cor.g, cor.b);
				Utilities::drawCircle(Centro(), d.largura / 2, 8); //Desenha octogono
			break;

			case 5:
				glColor3f(cor.r, cor.g, cor.b);
				Utilities::drawCircle(Centro(), d.largura /2, 50);//Desenha circulo
			break;
		}

		float healthPercentage = hp / hpOriginal;

		if (healthPercentage >= 0.6) {
			glColor3f(0, 1, 0);
			this->drawHPBar(healthPercentage);
		}
		else if (healthPercentage >= 0.3) {
			glColor3f(1, 1, 0);
			this->drawHPBar(healthPercentage);
		}
		else if (healthPercentage > 0) {
			glColor3f(1, 0, 0);
			this->drawHPBar(healthPercentage);
		}



		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(c.x, c.y + 5 + d.altura);
		glVertex2f(c.x + d.largura, c.y + 5 + d.altura);
		glVertex2f(c.x + d.largura, c.y + 11 + d.altura);
		glVertex2f(c.x, c.y + 11 + d.altura);
		glPopMatrix();
		glEnd();
	}
}

void Enemy::drawHPBar(float healthPercentage){
	if (healthPercentage > 0) {
		glBegin(GL_QUADS);
		glVertex2f(c.x, c.y + 5 + d.altura);
		glVertex2f(c.x + d.largura * healthPercentage, c.y + 5 + d.altura);
		glVertex2f(c.x + d.largura * healthPercentage, c.y + 11 + d.altura);
		glVertex2f(c.x, c.y + 11 + d.altura);
		glPopMatrix();
		glEnd();
	}
}

int Enemy::getScoreWorth() {
	return this->scoreWorth;
}

Enemy::~Enemy()
{
}
