#include "AnimacaoPassouFase.h"


AnimacaoPassouFase::AnimacaoPassouFase(int numFase)
{
	this->isActive = true;
	this->animacaoCont = 1;
	this->cor = Cor(0.0f, 0.0f, 1.0f);
	vetorPontos.push_back(new Coord(c.x, c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x + 1, this->c.y));
	vetorPontos.push_back(new Coord(this->c.x + 0.5, this->c.y + 1));
	vetorPontos.push_back(new Coord(this->c.x - 0.5, this->c.y - 1));
	vetorPontos.push_back(new Coord(this->c.x - 1, this->c.y));
}


AnimacaoPassouFase::~AnimacaoPassouFase()
{
}

void AnimacaoPassouFase::setNumFase() {
}

void AnimacaoPassouFase::Reset() {
	this->isActive = true;
	this->animacaoCont = 1;
}

void AnimacaoPassouFase::Display(int numFase) {
	glBegin(GL_POLYGON);
	glColor3f(cor.r, cor.g, cor.b);
	for each(Coord* ponto in vetorPontos) {
		glVertex2f(ponto->x * animacaoCont, ponto->y * animacaoCont);
	}
	if (animacaoCont < 1400) { animacaoCont++; }
	else { isActive = false; }
	glEnd();
	FuncoesExtra::DesenhaTexto("PARABENS, VOCE PASSOU DE FASE!!!", Coord(400, 300), Cor(1, 1, 1));
	FuncoesExtra::DesenhaTexto("FASE", Coord(400, 250), Cor(1, 1, 1));

	std::string numFaseString = std::to_string(numFase);
	char numFaseChar[30];
	strcpy(numFaseChar, numFaseString.c_str());

	;
	if (numFase == 2) {
		FuncoesExtra::DesenhaTexto("II:", Coord(500, 250), Cor(1, 1, 1));
		FuncoesExtra::DesenhaTexto(" KAMINO", Coord(540, 250), Cor(1, 1, 1));
	}
	if (numFase == 3) {
		FuncoesExtra::DesenhaTexto("III:", Coord(500, 250), Cor(1, 1, 1));
		FuncoesExtra::DesenhaTexto(" SALEUCAMI", Coord(540, 250), Cor(1, 1, 1));
	}
	if (numFase == 4) {
		FuncoesExtra::DesenhaTexto("IV:", Coord(500, 250), Cor(1, 1, 1));
		FuncoesExtra::DesenhaTexto(" ALDERAAN", Coord(540, 250), Cor(1, 1, 1));
	}
	if (numFase == 5) {
		FuncoesExtra::DesenhaTexto("V:", Coord(500, 250), Cor(1, 1, 1));
		FuncoesExtra::DesenhaTexto(" HOTH", Coord(540, 250), Cor(1, 1, 1));
	}
}