#pragma once
#include "EfeitosVisuais.h"
class AnimacaoFinal :
	public EfeitosVisuais
{
public:
	GLfloat angle = 0.0f;
	int refreshMills = 30;
	int contador;
	bool isActive;


	AnimacaoFinal();
	void Reset();
	~AnimacaoFinal();
	void Display();
	void Reshape(GLsizei width, GLsizei height);
};

