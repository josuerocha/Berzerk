#include "Coletavel.h"
#include "Player.h"

Coletavel::Coletavel() {
	this->active = false;
}

Coletavel::Coletavel(Coord coord, Cor cor, Dimensao dim, bool status) {
	this->c = coord;
	this->cor = cor;
	this->d = dim;
	this->active = status;
}

void Coletavel::Display() {
	if (this->active) {
		glColor3f(cor.r, cor.g, cor.b);
		glBegin(GL_TRIANGLES);
		glPushMatrix();
		glVertex2f(c.x, c.y);
		glVertex2f(c.x + d.largura, c.y);
		glVertex2f(c.x + (d.largura) / 2, c.y + d.altura);
		glPopMatrix();
		glEnd();
	}
}

void Coletavel::Dispose() {
	this->active = false;
}


float Coletavel::getCura()
{
	return cura;
}
