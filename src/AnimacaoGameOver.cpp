#include "AnimacaoGameOver.h"



AnimacaoGameOver::AnimacaoGameOver()
{
	this->isActive = true;
	this->efeitoCont = 1;
	this->cor = Cor(0.0f, 0.0f, 0.0f);
	vetorPontos.push_back(new Coord(c.x, c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 1, this->c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y - 1));
	vetorPontos.push_back(new Coord(this->c.x - 1, this->c.y));
}


AnimacaoGameOver::~AnimacaoGameOver()
{
}

void AnimacaoGameOver::Display() {
	glBegin(GL_POLYGON);
	glColor3f(cor.r, cor.g, cor.b);
	for each(Coord* ponto in vetorPontos) {
		glVertex2f(ponto->x * efeitoCont, ponto->y * efeitoCont);
	}
	glEnd();
	if (efeitoCont < 1400) { efeitoCont++; }
	else { isActive = false; }
	FuncoesExtra::DesenhaTexto("GAME OVER!", Coord(400, 300), Cor(1, 1, 1));
}

void AnimacaoGameOver::Reset() {
	efeitoCont = 1;
	isActive = true;
}