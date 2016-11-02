#pragma once
#include "Estruturas.h"
#include <math.h>
#include <GL/glut.h>

class FuncoesExtra
{
public:
	FuncoesExtra();
	~FuncoesExtra();
	static void DesenhaTexto(char *string, Coord c, Cor cor);
	static void DesenhaTextoMouse(char * string, Coord mouse, Cor cor);
	static void DesenhaInstrucoesBloco(char * string, Coord c);
	static Coord CalculaVetorUnitario(Coord i, Coord f);
	static void DrawCircle(Coord c, float r, int segmentos);
};

