#include "Score.h"

Score::Score()
{
	int pontuacao = 0;
	int accuracy = 1;
	int numTiros = 0;
	int hits = 0;
}


Score::~Score()
{
}

void Score::IncTiros(int incTiros) {
	this->numTiros += incTiros;
	if (numTiros != 0) { this->accuracy = hits / numTiros; }
	std::cout << "NUM TIROS " << this->numTiros << "\n";
}

void Score::DecTiros(int decTiros) {
	this->numTiros -= decTiros;
	if (numTiros != 0) { this->accuracy = hits / numTiros; }
}

void Score::IncPontuacao(int incPontuacao) {
	this->pontuacao += incPontuacao;
}

void Score::DecPontuacao(int decPontuacao) {
	this->pontuacao -= decPontuacao;
}

void Score::IncHits(int incHits) {
	this->hits += incHits;
	std::cout << "NUM HITS " << this->hits << "\n";
	if (numTiros != 0) { this->accuracy = hits / numTiros;}
}

void Score::Display(int vidas) {
	
	std::string pontuacaoString = std::to_string(pontuacao);
	char pontuacaoVetor[30];
	strcpy(pontuacaoVetor, pontuacaoString.c_str());
	FuncoesExtra::DesenhaTexto("SCORE: ",Coord(800,15),Cor(0,0,1));
	FuncoesExtra::DesenhaTexto(pontuacaoVetor, Coord(950, 15), Cor(1, 1, 1));

	std::ostringstream out;
	out << std::setprecision(3) << accuracy * 100;
	std::string accuracyString = out.str();
	char accuracyChar[30];
	strcpy(accuracyChar, accuracyString.c_str());
	FuncoesExtra::DesenhaTexto("ACCURACY: ", Coord(490, 15), Cor(0, 0, 1));
	FuncoesExtra::DesenhaTexto(accuracyChar, Coord(690, 15), Cor(1, 1, 1));
	FuncoesExtra::DesenhaTexto("%", Coord(725, 15), Cor(1, 1, 1));
	glColor3f(1, 0, 0);
	if (vidas == 3){
	FuncoesExtra::DrawCircle(Coord(400,25),10,6);
	FuncoesExtra::DrawCircle(Coord(430, 25), 10, 6);
	FuncoesExtra::DrawCircle(Coord(460, 25), 10, 6);
	}
	else if (vidas == 2) {
	FuncoesExtra::DrawCircle(Coord(400, 25), 10, 6);
	FuncoesExtra::DrawCircle(Coord(430, 25), 10, 6);
	}
	else if (vidas == 1) {
	FuncoesExtra::DrawCircle(Coord(400, 25), 10, 6);
	}
}

void Score::Reset() {
	int pontuacao = 0;
	int accuracy = 1;
	int numTiros = 0;
	int hits = 0;
}