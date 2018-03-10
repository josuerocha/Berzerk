#include "Player.h"

Player::Player(){
	this->vidasBackup = 0;
	this->isActive = false;
}

Player::Player(Coord c, Dimensao d, int velocidade, float hp, Cor cor,int vidas, int tiros)
{	this->c = c;
	this->d = d;
	this->velocidade = velocidade;
	this->hp = hp;
	this->cor = cor;
	this->hpOriginal = hp;
	this->vidas = vidas;
	this->tirosEspeciais = tiros;
	this->isActive = true;
	this->isActiveBackup = false;

	this->cBackup = c;
	this->dBackup = d;
	this->velocidadeBackup = velocidade;
	this->hpBackup = hp;
	this->corBackup = cor;
	this->hpOriginalBackup = hp;
	this->vidasBackup = vidas;
	this->tirosEspeciaisBackup = tiros;
}

Player::~Player()
{
	
}

void Player::Kill() {
	isActive = false;
	vidas--;
}

void Player::Display() {
	if (isActive) {
		glBegin(GL_QUADS);
		glColor3f(cor.r, cor.g, cor.b);
		glPushMatrix();
		glVertex2f(c.x, c.y);
		glVertex2f(c.x + d.largura, c.y);
		glVertex2f(c.x + d.largura, c.y + d.altura);
		glVertex2f(c.x, c.y + d.altura);
		glEnd();

		Utilities::DesenhaTexto("RAVEN", Coord(30,14), Cor(0, 0, 1));

		float healthPercentage = hp / hpOriginal;
		if (healthPercentage > 1) {
			healthPercentage = 1;
		}

		if (healthPercentage >= 0.6) {
			glColor3f(0, 1, 0);
		}
		else if (healthPercentage >= 0.3) {
			glColor3f(1, 1, 0);
		}
		else if (healthPercentage > 0) {
			glColor3f(1, 0, 0);
		}
		if(healthPercentage > 0){
		glBegin(GL_QUADS);
		glVertex2f(150, 35);
		glVertex2f(230 * healthPercentage + 150, 35);
		glVertex2f(230 * healthPercentage + 150, 10);
		glVertex2f(150, 10);
		glPopMatrix();
		glEnd();
		}

		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(150, 35);
		glVertex2f(380, 35);
		glVertex2f(380, 10);
		glVertex2f(150, 10);
		glPopMatrix();
		glEnd();
	}
}

void Player::onMedikitCollectAction(float cura) {
	IncHP(cura);
}

int Player::getVidas() {
	return vidas;
}

void Player::Reset() {
	this->c = cBackup;
	this->d = dBackup;
	this->velocidade = velocidadeBackup;
	this->hp = hpBackup;
	this->cor = corBackup;
	this->hpOriginal = hpBackup;
	this->tirosEspeciais = tirosEspeciaisBackup;
}

void Player::ResetVidas() {
	this->vidas = vidasBackup;
}

void Player::decTirosEspeciais() {
	tirosEspeciais -= 1;

}

int Player::getTiros() {
	return tirosEspeciais;
}
