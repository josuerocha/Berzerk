#include "Personagem.h"

Personagem::Personagem(){}

Personagem::Personagem(Coord c, Dimensao d, int velocidade, int hp, Cor cor)
{
	Personagem::c = c;
	Personagem::d = d;
	Personagem::velocidade = velocidade;
	Personagem::hp = hp;
	Personagem::cor = cor;
}

Personagem::~Personagem()
{
}

void Personagem::IncX(int value, bool podeMover) {
	if (podeMover) {
			c = Coord(c.x + value, c.y);
		}
}


void Personagem::IncY(int value,bool podeMover) {
	if (podeMover) {
			c = Coord(c.x, c.y + value);
		}
}

void Personagem::IncHP(float value) {
	hp += value;
}

void Personagem::DecHP(float value) {
	hp -= value;
	if (hp <= 0) {
		Kill();
	}
}

Coord Personagem::Centro() {
	return Coord(c.x + d.largura / 2, c.y + d.altura / 2);
}

Coord Personagem::getC() {
	return c;
}

void Personagem::setC(Coord c) {
	this->c = c;
}

Dimensao Personagem::getD() {
	return d;
}

void Personagem::setD(Dimensao d) {
	this->d = d;
}

void Personagem::Display() {
	if (hp <= 0) { Kill(); }
	if(isActive){
	glBegin(GL_QUADS);
	glColor3f(cor.r, cor.g, cor.b);
	glPushMatrix();
	glVertex2f(c.x,c.y);
	glVertex2f(c.x + d.largura, c.y);
	glVertex2f(c.x + d.largura, c.y + d.altura);
	glVertex2f(c.x, c.y + d.altura);
	glPopMatrix();
	glEnd();
	}
}

void Personagem::Rotaciona(float teta) {

}

void Personagem::Kill() {
	isActive = false;
}

bool Personagem::getIsActive() {
	return isActive;
}

int Personagem::getHP() {
	return this->hp;
}