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
	// Posição no universo onde o texto será colocado  
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
	// Posição no universo onde o texto será colocado  
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
	// Posição no universo onde o texto será colocado  
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