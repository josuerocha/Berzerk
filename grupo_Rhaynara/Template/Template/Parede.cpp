#include "Parede.h"



Parede::Parede()
{
}

Parede::Parede(Coord c,Dimensao d,Cor cor1, Cor cor2)
{
	this->c = c;
	this->d = d;
	this->cor1 = cor1;
	this->cor2 = cor2;
}


Parede::~Parede()
{
}

void Parede::Display() {

	glBegin(GL_QUADS);
	glColor3f(cor1.r, cor1.g, cor1.b);
	glVertex2i(c.x, c.y);
	glVertex2i(c.x, c.y + d.altura);

	glColor3f(cor2.r, cor2.g, cor2.b);

	glVertex2i(c.x + d.largura, c.y + d.altura);
	glVertex2i(c.x + d.largura, c.y);

	// Especifica que a cor corrente é azul
	glEnd();

}