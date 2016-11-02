#ifndef Tela_h
#define Tela_h

#include <iostream>
#include <GL/glut.h>
#include "Projectile.h"
#include "FuncoesExtra.h"
#include "Estruturas.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "Level.h"
#include "EfeitosVisuais.h"
#include "Explosao.h"
#include "AnimacaoInicial.h"
#include "MainMenu.h"
#include "Score.h"
#include "Medkit.h"
#include "AnimacaoMorte.h"
#include "AnimacaoPassouFase.h"
#include "AnimacaoGameOver.h"
#include "AnimacaoFinal.h"

#define PROJECTILE_VELOCITY 10
#define MAX_PROJECTILES 30
#define MAX_ENEMIES_PER_SCREEN 10

// Teclado
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define CAPSUP 'W'
#define CAPSDOWN 'S'
#define CAPSLEFT 'A'
#define CAPSRIGHT 'D'

/*classe abstrata para a implementacao das Telas*/
class Tela
{
public:
	//variaveis de controle
	bool animacaoFinalFlag;
	int contadorTempo = 0;
	int faseAtual;
	Coord mouse;
	bool keyBuffer[6]; //Respectivamente up, down, left, right, click, rightclick
	int shoot;
	bool fullscreen;
	bool isPlaying;
	bool animacaoMorte;
	bool passouDeFase;

	//Pontuacao
	Score score;

    //Personagens
	std::vector <Projectile*> vetorProjeteisAmigos;
	std::vector <Projectile*> vetorProjeteisInimigos;
	std::vector <EfeitosVisuais*> vetorEfeitosVisuais;
	Player player;

	//Animacoes
	AnimacaoInicial animacaoInicial;
	AnimacaoMorte* efeitoMorte;
	AnimacaoPassouFase* efeitoPassouFase;
	AnimacaoGameOver* efeitoGameOver;
	AnimacaoFinal animacaoFinal;

	Level fase;
	MainMenu* menu;

	glutWindow janela;

	Tela();
	~Tela();

	void Logica();
	void MoveProjectiles();
	void MoveFriendlyProjectiles();
	void MoveEnemyProjectiles();
	void Initialize();
	void AlteraTamanhoJanela(GLsizei w, GLsizei h);
	void ChecaColisaoInimigosParedes();
	void ChecaColisaoInimigosParedesInimigos();
	bool ChecarColisoesParedes(int variacaox,int variacaoy);
	void ChecarColisoes();
	void ChecarColisoesProjeteisInimigos();
	void ChecarColisoesProjeteisAmigos();
	void ChecarColisoesInimigos();
	void EnemiesShoot();
	void DisplayVisualEfects();
	void ChecaColisaoProjeteisParedes();
	void DisplayColetaveis();
	void ChecarColisoesColetaveis();
	void Display();
	void DisplayCharacters();
	void setWindowValues();
	void DisplayProjectiles();
	void DisplayEnemyProjectiles();
	void CheckMapBoundaries();
	void MovePlayer();
	void keyboardDown(unsigned char key, int x, int y);
	void mouseMotion(int x, int y);
	void keyboardUp(unsigned char key, int x, int y);
	void mouseClick(int button, int state, int x, int y);
	bool ChecaColisao(BoundingBox * quadrado1, BoundingBox * quadrado2);
	void DisplayEnemies();
};

#endif