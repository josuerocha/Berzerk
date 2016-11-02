#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
	emJogo = false;
	emTela = false;
	emMenu = false;
	emMenuPrincipal = false;

	inicia = false;
	opcao = false;

	iniciarMenuButton = false;
	opcaoMenuButton = false;
	desenharMenuButton = true;
	sairButton = false;
	clickAtivo = false;
}


MainMenu::~MainMenu()
{
}

void MainMenu::Run() {
	if (sairButton) {
		exit(0);
	}
	if (desenharMenuButton) {
		Display();
	}
	if (opcaoMenuButton) {
		OpcaoMenu();
	}
	if (iniciarMenuButton) {
		IniciarJogo();
	}
	
	PosicaoMenu();
}

void MainMenu::DesenhaTextoMenu(char *string, Coord c)
{
	//glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.00f, 0.00f, 0.00f);
	glPushMatrix();
	// Posição no universo onde o texto será colocado  
	glRasterPos2f(c.x, c.y);
	// glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
	glPopMatrix();
}

// escreve o texto da tela 
void MainMenu::DesenhaInstrucoes(char *string, Coord c)
{
	//glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(1.00f, 1.00f, 1.00f);
	glPushMatrix();
	// Posição no universo onde o texto será colocado  
	glRasterPos2f(c.x, c.y);
	// glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
	glPopMatrix();
}

//escreve o texto dos blocos
void MainMenu::DesenhaInstrucoesBloco(char *string, Coord c)
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

void MainMenu::OpcaoMenu() {

	glPushMatrix();
	// define a cor verde para o desenho do retangulo
	glColor3f(0.66f, 0.66f, 0.66f);
	// desenha um retângulo

	//teclado A
	glBegin(GL_POLYGON);
	glVertex2f(700, 120);
	glVertex2f(700, 85);
	glVertex2f(750, 85);
	glVertex2f(750, 120);
	glEnd();

	//teclado D
	glBegin(GL_POLYGON);
	glVertex2f(848, 120);
	glVertex2f(848, 85);
	glVertex2f(898, 85);
	glVertex2f(898, 120);
	glEnd();

	//teclado W
	glBegin(GL_POLYGON);
	glVertex2f(773, 160);
	glVertex2f(773, 125);
	glVertex2f(823, 125);
	glVertex2f(823, 160);
	glEnd();

	//teclado S
	glBegin(GL_POLYGON);
	glVertex2f(773, 80);
	glVertex2f(773, 45);
	glVertex2f(823, 45);
	glVertex2f(823, 80);

	glEnd();


	//objetivo
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(450, 530);
	glVertex2f(450, 500);
	glVertex2f(570, 500);
	glVertex2f(570, 530);
	glEnd();

	//teclas de atalho
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(410, 420);
	glVertex2f(410, 390);
	glVertex2f(620, 390);
	glVertex2f(620, 420);
	glEnd();

	//backspace
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(32, 370);
	glVertex2f(32, 345);
	glVertex2f(170, 345);
	glVertex2f(170, 370);
	glEnd();

	//enter
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(94, 340);
	glVertex2f(94, 315);
	glVertex2f(170, 315);
	glVertex2f(170, 340);
	glEnd();

	//esc
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(113, 310);
	glVertex2f(113, 285);
	glVertex2f(170, 285);
	glVertex2f(170, 310);
	glEnd();

	//f
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(138, 280);
	glVertex2f(138, 255);
	glVertex2f(170, 255);
	glVertex2f(170, 280);
	glEnd();

	//o
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(138, 250);
	glVertex2f(138, 225);
	glVertex2f(170, 225);
	glVertex2f(170, 250);
	glEnd();

	//teclas de jogo
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(410, 220);
	glVertex2f(410, 190);
	glVertex2f(620, 190);
	glVertex2f(620, 220);
	glEnd();

	//mouse
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(220, 150);
	glVertex2f(220, 105);
	glVertex2f(170, 105);
	glVertex2f(170, 150);
	glEnd();

	//mouse esquerdo
	glColor3f(0.00f, 0.00f, 1.00f);
	glBegin(GL_POLYGON);
	glVertex2f(170, 150);
	glVertex2f(170, 130);
	glVertex2f(193.5, 130);
	glVertex2f(193.5, 150);
	glEnd();
	//mouse direito
	glColor3f(1.00f, 0.00f, 0.00f);
	glBegin(GL_POLYGON);
	glVertex2f(195, 150);
	glVertex2f(195, 130);
	glVertex2f(220, 130);
	glVertex2f(220, 150);
	glEnd();

	//descricao mouse esquerdo
	glColor3f(0.00f, 0.00f, 1.00f);
	glBegin(GL_POLYGON);
	glVertex2f(230, 150);
	glVertex2f(230, 130);
	glVertex2f(255, 130);
	glVertex2f(255, 150);
	glEnd();

	//descricao mouse esquerdo
	glColor3f(1.00f, 0.00f, 0.00f);
	glBegin(GL_POLYGON);
	glVertex2f(230, 125);
	glVertex2f(230, 105);
	glVertex2f(255, 105);
	glVertex2f(255, 125);
	glEnd();

	//voltar
	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(15, 540);
	glVertex2f(15, 565);
	glVertex2f(55, 565);
	glVertex2f(55, 540);
	glEnd();

	DesenhaInstrucoes("INSTRUCOES DE JOGO",Coord( 370, 550));
	DesenhaInstrucoesBloco("Objetivo", Coord(460, 510));
	DesenhaInstrucoes("Eliminar os inimigos invasores a cada fase que se segue.",Coord( 217, 470));
	DesenhaInstrucoes("As fases terminam quando nao restarem mais inimigos no campo de batalha.",Coord( 130, 440));
	DesenhaInstrucoesBloco("Teclas de Atalho",Coord( 423, 399));
	DesenhaInstrucoesBloco("Backspace:",Coord( 40, 352));
	DesenhaInstrucoes("Retorna para a tela anterior.",Coord( 180, 350));
	DesenhaInstrucoesBloco("Enter:",Coord( 102, 322));
	DesenhaInstrucoes("Inicia o jogo", Coord(180, 320));
	DesenhaInstrucoesBloco("Esc:",Coord( 120, 291));
	DesenhaInstrucoes("Sai do jogo",Coord( 180, 290));
	DesenhaInstrucoesBloco("F:",Coord( 147, 261));
	DesenhaInstrucoes("Alterna entre tela cheia e nao cheia", Coord(180, 261));
	DesenhaInstrucoesBloco("O:", Coord(142, 231));
	DesenhaInstrucoes("Entra na tela de opcoes", Coord(180, 230));
	DesenhaInstrucoesBloco("Teclas de Jogo",Coord( 427, 199));
	FuncoesExtra::DesenhaTextoMouse("1",Coord( 178, 138),Cor(1,1,1));
	FuncoesExtra::DesenhaTextoMouse("2",Coord( 202, 138), Cor(1, 1, 1));
	FuncoesExtra::DesenhaTextoMouse("1",Coord( 238, 137), Cor(1, 1, 1));
	FuncoesExtra::DesenhaTextoMouse("2", Coord(238, 112), Cor(1, 1, 1));
	DesenhaInstrucoes("Tiro 1",Coord( 262, 133));
	DesenhaInstrucoes("Tiro 2",Coord( 262, 106));

	DesenhaInstrucoesBloco("A",Coord( 716, 96));
	DesenhaInstrucoesBloco("W",Coord( 786, 137));
	DesenhaInstrucoesBloco("D",Coord( 864, 96));
	DesenhaInstrucoesBloco("S",Coord( 790, 56));


	DesenhaInstrucoes("Cima", Coord( 770, 165));
	DesenhaInstrucoes("Baixo", Coord(770, 25));
	DesenhaInstrucoes("Direita",Coord( 902, 96));
	DesenhaInstrucoes("Esquerda", Coord(592, 96));
	DesenhaInstrucoesBloco("<", Coord(25, 548));

	glPopMatrix();
}


/* ---------------- MENU INICIAR  JOGO ----------------------*/
void MainMenu::IniciarJogo() {

	glPushMatrix();
	emMenu = false;
	emMenuPrincipal = false;
	glPopMatrix();
}


void MainMenu::Display() {
	// limpa a tela com a cor branca
	glClearColor(0.0, 0.0, 0.0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	// define a cor verde para o desenho do retangulo
	glColor3f(0.66f, 0.66f, 0.66f);
	// desenha um retângulo
	glBegin(GL_POLYGON);
	glVertex2f(350, 450);
	glVertex2f(350, 400);
	glVertex2f(700, 400);
	glVertex2f(700, 450);
	glEnd();

	//glColor3f(1.0f, 1.00f, 1.00f);

	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(350, 370);
	glVertex2f(350, 320);
	glVertex2f(700, 320);
	glVertex2f(700, 370);
	glEnd();

	glColor3f(0.66f, 0.66f, 0.66f);
	glBegin(GL_POLYGON);
	glVertex2f(350, 290);
	glVertex2f(350, 240);
	glVertex2f(700, 240);
	glVertex2f(700, 290);
	glEnd();


	DesenhaTextoMenu("INICIAR", Coord(452, 418));
	DesenhaTextoMenu("OPCOES", Coord(452, 338));
	DesenhaTextoMenu("SAIR", Coord(480, 255));


	glPopMatrix();
}

// chama as funções de acordo com a posição do clique  - iniciar, opções ou sair.
void MainMenu::OpcaoClick(int op) {
	if (op == 1) {
		iniciarMenuButton = true;
		opcaoMenuButton = false;
		desenharMenuButton = false;
		emMenu = false;
	}
	if (op == 2) {
		opcaoMenuButton = true;
		iniciarMenuButton = false;
		desenharMenuButton = false;
		emMenu = false;
	}
	if (op == 3) {
		exit(0);
	}
	if (op == 4) {
		desenharMenuButton = true;
		opcaoMenuButton = false;
		iniciarMenuButton = false;
		emMenu = true;
	}
}

// verifica qual opção do menu foi selecionada - iniciar, opções ou sair.
void MainMenu::PosicaoMenu() {
	if(clickAtivo){
	//INICIAR	
		if ((mouse.x >= 350) && (mouse.x <= 700)) {
			if ((mouse.y >= 400) && (mouse.y <= 450)) {
				if (!opcao) {
					inicia = true;
					opcao = false;
					OpcaoClick(1);
					cout << "Inicia: " << inicia << endl;
					cout << "Opcao: " << opcao << endl;
					cout << "emMenu: " << emMenu << endl;
				}
			}
		}
		//OPÇÕES
		if ((mouse.x >= 350) && (mouse.x <= 700)) {
			if ((mouse.y >= 320) && (mouse.y <= 370)) {
				if (!inicia) {
					opcao = true;
					inicia = false;
					emMenu = false;
					OpcaoClick(2);
					cout << "Inicia: " << inicia << endl;
					cout << "Opcao: " << opcao << endl;
					cout << "emMenu: " << emMenu << endl;

				}
			}
		}

		//SAIR
		if ((mouse.x >= 350) && (mouse.x <= 700)) {
			if ((mouse.y >= 240) && (mouse.y <= 290)) {
				if (!inicia && !opcao) {
					OpcaoClick(3);
				}
			}
		}
		//VOLTAR
		if ((mouse.x >= 15) && (mouse.x <= 55)) {
			if ((mouse.y >= 540) && (mouse.y <= 565)) {
				if (opcao) {
					opcao = false;
					inicia = false;
					emMenu = true;
					OpcaoClick(4);
					cout << "Inicia: " << inicia << endl;
					cout << "Opcao: " << opcao << endl;
					cout << "emMenu: " << emMenu << endl;
				}
			}
		}
	clickAtivo = false;
	}
}
