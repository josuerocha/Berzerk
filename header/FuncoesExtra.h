#pragma once

//CUSTOM INCLUDES
#include "Estruturas.h"

//GL INCLUDES
#include <GL/glut.h>

//STANDARD INCLUDES
#include <math.h>
#include <sstream>
#include <string>
#include <iostream>

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
	static std::string to_string(int num);
};

