#include "Explosao.h"
using namespace std;


Explosao::Explosao(Coord c, string tamanho)
{
	if (tamanho == "pequena") { limite = 10; }
	if (tamanho == "media") { limite = 25; }
	if (tamanho == "grande") { limite = 50; }

	this->size = 1;
	this->decrementa = false;
	this->c = c;
	this->cor = cor;
	this->isActive = true;
}
Explosao::~Explosao()
{
}

void Explosao::Display() {
		glColor3f(1, 1, 0);
		FuncoesExtra::DrawCircle(c, size*1.9, 5);

		glColor3f(1, 0.647059, 0);
		FuncoesExtra::DrawCircle(c, size*1.6, 5);


		glColor3f(1, 0.54902, 0);
		FuncoesExtra::DrawCircle(c, size*1.3, 5);

		glColor3f(1, 0, 0);
		FuncoesExtra::DrawCircle(c, size, 5);
		if(decrementa){
			size -= SPEED;
		}
		else {
			size += SPEED;
		}
	if(size>= limite){
		decrementa = true;
	}
	else if (size <= 0) {
		isActive = false;
	}

}
