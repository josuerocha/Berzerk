#include "Projetil.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

Projetil::Projetil(int xa, int ya, int xf, int yf, int alc, int d)
{
Projetil::xatual = xa;
Projetil::yatual = ya;
Projetil::xfinal = xf;
Projetil::yfinal = yf;
Projetil::alcance = alc;
Projetil::dano = d;

}

Projetil::~Projetil()
{
Projetil::xatual = 0;
Projetil::yatual = 0;
Projetil::xfinal = 0;
Projetil::yfinal = 0;
Projetil::alcance = 0;
Projetil::dano = 0;
}


