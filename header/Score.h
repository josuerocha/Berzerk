#pragma once

//CUSTOM INCLUDES
#include "FuncoesExtra.h"

//STANDARD INCLUDES
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>

class Score
{
	int pontuacao;
	float accuracy;
	float numTiros;
	float hits;
public:
	Score();
	~Score();
	void IncTiros(int numTiros);
	void DecTiros(int numTiros);
	void IncPontuacao(int pontuacao);
	void DecPontuacao(int pontuacao);
	void IncHits(int hits);
	void Display(int vidas);
	void Display();
	void Reset();
};

