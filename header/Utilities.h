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

class Utilities
{
public:
	Utilities();
	~Utilities();
	static void drawText(char *string, Coord c, Cor cor);
	static void drawTextAtMouse(char * string, Coord mouse, Cor cor);
	static void drawInstructionBlock(char * string, Coord c);
	static Coord calculateUnitVector(Coord *a, Coord *b);
	static void drawCircle(Coord c, float r, int segmentos);
	static std::string to_string( int n );
	static bool checkCollision(BoundingBox *quadrado1, BoundingBox *quadrado2);
};

