#include "FuncoesExtra.h"


FuncoesExtra::FuncoesExtra()
{
}


FuncoesExtra::~FuncoesExtra()
{
}

void FuncoesExtra::DesenhaTexto(char *string, Coord c,Cor cor)
{
	//glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(cor.r, cor.g, cor.b);
	glPushMatrix();
	// Posi��o no universo onde o texto ser� colocado  
	glRasterPos2f(c.x, c.y);
	// glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
	glPopMatrix();
}

void FuncoesExtra::DesenhaTextoMouse(char *string, Coord mouse, Cor cor)
{
	glColor3f(cor.r, cor.g, cor.b);
	glPushMatrix();
	// Posi��o no universo onde o texto ser� colocado  
	glRasterPos2f(mouse.x, mouse.y);
	// glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);
	glPopMatrix();
}

void FuncoesExtra::DesenhaInstrucoesBloco(char *string, Coord c)
{
	//glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.00f, 0.00f, 0.00f);
	glPushMatrix();
	// Posi��o no universo onde o texto ser� colocado  
	glRasterPos2f(c.x, c.y);
	// glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
	glPopMatrix();
}

Coord FuncoesExtra::CalculaVetorUnitario(Coord i, Coord f) {
	Coord c = Coord(f.x - i.x, f.y - i.y);
	float modulo = sqrt(pow(c.x, 2) + pow(c.y, 2));
	c = Coord(c.x / modulo, c.y / modulo);
	return c;
}

void FuncoesExtra::DrawCircle(Coord c, float r, int segmentos)
{	
	glBegin(GL_POLYGON);
	for (int i = 0; i < segmentos; i++)
	{
		float teta = 2.0f * 3.1415926f * float(i) / float(segmentos);

		float x = r * cosf(teta);
		float y = r * sinf(teta);

		glVertex2f(x + c.x, y + c.y);

	}
	glEnd();
}

std::string FuncoesExtra::to_string( int n ){
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
}

bool FuncoesExtra::checkCollision(BoundingBox *quadrado1, BoundingBox *quadrado2) {
	int esquerda1, direita1, cima1, baixo1;
	int esquerda2, direita2, cima2, baixo2;
	esquerda1 = quadrado1->x;
	direita1 = quadrado1->x + quadrado1->largura;
	cima1 = quadrado1->y;
	baixo1 = quadrado1->y + quadrado1->altura;
	esquerda2 = quadrado2->x;
	direita2 = quadrado2->x + quadrado2->largura;
	 cima2 = quadrado2->y;
	 baixo2 = quadrado2->y + quadrado2->altura;
	if (esquerda1 > direita2){
		return false; // (n�o colis�o)
	}
	if (direita1 < esquerda2){
		return false; // (n�o colis�o)
	}
	if (cima1 > baixo2) {
		return false; // (n�o colis�o)
	}
	if (baixo1 < cima2){
		return false; // (n�o colis�o)
	}			  /*do contr�rio (COLIS�O)*/
	return true;
}
