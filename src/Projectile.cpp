#include "Projectile.h"

Projectile::Projectile()
{
	c = Coord(0, 0);
	vetor = Coord(0, 0);
	alcance = 0;
	velocity = 0;
	dano = 0;
	this->active = true;
}

Projectile::Projectile(Coord c, Coord vetor, Dimensao d, int alcance, int dano, float velocity, bool active,Cor cor)
{
	this->c = c;
	this->vetor = vetor;
	this->d = d;
	this->alcance = alcance;
	this->velocity = velocity;
	this->dano = dano;
	this->active = active;
	this->cor = cor;
}


Projectile::~Projectile(){
}


Coord Projectile::getC() {
	return c;
}

void Projectile::setC(Coord c) {
	this->c = c;
}

Coord Projectile::getVetor() {
	return vetor;
}

void Projectile::setVetor(Coord c) {
	this->vetor = vetor;
}

float Projectile::getVelocity() {
	return velocity;
}

void Projectile::setVelocity(float velocity) {
	this->velocity = velocity;
}


bool Projectile::isActive() {
	return this->active;
}

void Projectile::Activate() {
	this->active = true;
}

void Projectile::Deactivate() {
	this->active = false;
}

int Projectile::getDano() {
	return dano;
}

void Projectile::setDano(int dano) {
	this->dano = dano;
}

int Projectile::getAlcance() {
	return alcance;
}

void Projectile::setAlcance(int alcance) {
	this->alcance = alcance;
}

void Projectile::Display() {
			glBegin(GL_QUADS);
			glPushMatrix();
			glColor3f(cor.r, cor.g, cor.b);			
			glVertex2f(c.x, c.y);
			glVertex2f(c.x + d.largura, c.y);
			glVertex2f(c.x + d.largura, c.y + d.altura);
			glVertex2f(c.x, c.y + d.altura);			
			glPopMatrix();
			glEnd();
}
