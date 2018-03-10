#include "Level.h"
using namespace std;

Level::Level(){

	this->contParedes = 0;
	this->coluna = 0;
	this->tipo = -1;
	this->qtdInimigos = 0;
}

Level::Level(int tipo) {
	system("pwd");
	qtdInimigos = 0;
	this->tipo = tipo;
	std::string url;

	if (tipo == 1){
		url = "models/level1.txt";
	}else if(tipo == 2){
		url = "models/level2.txt";
	}else if (tipo == 3){
		url = "models/level3.txt";
	}else if (tipo == 4){
		url = "models/level4.txt";
	}else if (tipo == 5){
		url = "models/level5.txt";
	}else{
		cout << "ERROR: invalid option: " << tipo << endl;
	}

	this->xponto = 100; this->yponto = 300;
	this->xponto2 = 740; this->yponto2 = 200;
	this->percorreLinha = 0;
	this->percorreColuna = 0;

	this->xpontoparedeEsq = 25; this->ypontoparedeEsq = 50;
	this->ypontoparede2 = 550;
	this->xpontoparedeDirIn = 1040; this->xpontoparedeDirFin = 740;

	this->qtdLinhas = 26;
	this->qtdColunas = 50;
	this->linha = 0;
	this->coluna = 0;

	LerArquivo(url);
	cout<<"LEVEL" << tipo << "mapped. Enemy count: " << this->qtdInimigos << endl;
}

Level::~Level()
{
}


void Level::LerArquivo(std::string url){
	char ch;
	int vetPosicao = 0;

	std::ifstream is(url);

	while (is.get(ch)) {
		if (isDigit(ch)) {

			if (linha == 26) {
				vetCores[vetPosicao] = ch - '0';
				vetPosicao++;
			}else {
				matTela[linha][coluna] = ch - '0';
				coluna++;
			}
		} else if (ch == '\n') {
			linha++;
			coluna = 0;
		}
	}


	MapeiaFase();
}

bool Level::isDigit( char c ){
   return ( '0' <= c && c <= '9' );
}

void Level::MapeiaFase() {
	qtdInimigos = 0;
	contParedes = 0;
	std::cout << "MAPEANDO FASE\n";
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	int xpontoParedeAtualizado1 = 25;
	int ypontoParedeAtualizado1 = 50;
	int xpontoParedeAtualizado2 = 50;
	int ypontoParedeAtualizado2 = 70;

	for (percorreLinha = 0; percorreLinha < qtdLinhas; percorreLinha++) {

		for (percorreColuna = 0; percorreColuna < qtdColunas; percorreColuna++) {


			if (matTela[percorreLinha][percorreColuna] == 1) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;

				glColor3f(vetCores[0], vetCores[1], vetCores[2]);
				glBegin(GL_QUADS);
				glVertex2i(xpontoParedeAtualizado1, ypontoParedeAtualizado2);

				//empilha para checar colisao mais tarde
				contParedes++;
				vetorParede.push_back(new Parede(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1),Dimensao(20,20),Cor(vetCores[0], vetCores[1], vetCores[2]),Cor(vetCores[3], vetCores[4], vetCores[5])));

				glVertex2i(xpontoParedeAtualizado1, ypontoParedeAtualizado1);

				// Especifica que a cor corrente � azul
				glColor3f(vetCores[3], vetCores[4], vetCores[5]);
				glVertex2i(xpontoParedeAtualizado2, ypontoParedeAtualizado1);
				glVertex2i(xpontoParedeAtualizado2, ypontoParedeAtualizado2);

				glEnd();

			}
			else if (matTela[percorreLinha][percorreColuna] == 0) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;

			}
			/* Cria Inimigo tipo 1 */
			else if (matTela[percorreLinha][percorreColuna] == 2) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorInimigos.push_back(new Enemy(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1), 1));
				qtdInimigos++;
			}
			/**/
			/* Cria inimigo tipo 2*/
			else if (matTela[percorreLinha][percorreColuna] == 3) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorInimigos.push_back(new Enemy(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1),2));
				qtdInimigos++;
			}
			else if (matTela[percorreLinha][percorreColuna] == 4) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorInimigos.push_back(new Enemy(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1), 3));
				qtdInimigos++;
			}
			else if (matTela[percorreLinha][percorreColuna] == 5) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorInimigos.push_back(new Enemy(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1), 4));
				qtdInimigos++;
			}
			else if (matTela[percorreLinha][percorreColuna] == 6) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorInimigos.push_back(new Enemy(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1), 5));
				qtdInimigos++;
			}
			else if (matTela[percorreLinha][percorreColuna] == 7) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				playerPosicao = Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1);
			}
			else if (matTela[percorreLinha][percorreColuna] == 8) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
				vetorColetaveis.push_back(new Medkit(Coord(xpontoParedeAtualizado1, ypontoParedeAtualizado1),Cor(1,0,0),Dimensao(10,10),true,40));
			}
			else {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;
			
			}
			xpontoParedeAtualizado1 = xpontoParedeAtualizado2;
		}
		ypontoParedeAtualizado2 = ypontoParedeAtualizado2 + 20;
		ypontoParedeAtualizado1 = ypontoParedeAtualizado1 + 20;
		xpontoParedeAtualizado1 = 25;
		xpontoParedeAtualizado2 = 50;
	}
}

Coord Level::getPlayerPosition(){
	return playerPosicao;
}

int Level::getQtdInimigos(){
	return qtdInimigos;
}

void Level::DecQtdInimigos(){
	qtdInimigos--;
}


void Level::DesenhaFase() {
	for(Parede* parede : vetorParede) {
		parede->Display();
	}
	
	//cout<<"MEU SACO " << this->qtdInimigos << " " << this->qtdColunas << " " << " " << this->qtdLinhas << endl;
}
