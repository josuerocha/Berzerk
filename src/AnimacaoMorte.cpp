#include "AnimacaoMorte.h"
AnimacaoMorte::AnimacaoMorte()
{
	this->isActive = true;
	this->morteCont = 1;
	this->cor = Cor(1.0f, 0.0f, 0.0f);
	vetorPontos.push_back(new Coord(c.x, c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 1, this->c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y - 1));
	vetorPontos.push_back(new Coord(this->c.x - 1, this->c.y));
}


AnimacaoMorte::~AnimacaoMorte()
{
}

void AnimacaoMorte::Display() {
	glBegin(GL_POLYGON);
	glColor3f(cor.r, cor.g, cor.b);
	for(Coord* ponto : vetorPontos) {
		glVertex2f(ponto->x * morteCont, ponto->y * morteCont);
	}
	if (morteCont < 1400) { morteCont+=5; }
	else { isActive = false; }
	glEnd();

	Utilities::DesenhaTexto("VOCE MORREU!", Coord(400, 300), Cor(1, 1, 1));
}

void AnimacaoMorte::Reset() {
	this->isActive = true;
	this->morteCont = 1;
}
