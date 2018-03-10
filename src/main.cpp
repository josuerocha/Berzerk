
#include <Game.h>
#include <iostream>
#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
//--------------- Defini��es -----------------
Game tela;
// Teclado
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Defini��es de jogo
#define PROJECTILE_VELOCITY 10
#define MAX_PROJECTILES 30
#define MAX_ENEMIES_PER_SCREEN 10


// -------- Assinaturas de Fun��es -----------
void Timer(int value);
void Display();
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void keyboardDown(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboardSpecialDown(int key, int x, int y);
void keyboardSpecialUp(int key, int x, int y);

// --------------- Fun��es --------------------



int main(int argc, char **argv) {

	tela.setWindowValues();

	srand((unsigned int)time(NULL));

	// initialize and run program
	glutInit(&argc, argv);  // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(tela.window.width, tela.window.height); // set window size
	glutCreateWindow(tela.window.title); // create Window
	glutInitWindowPosition(500,500);
	glutDisplayFunc(Display); // register Display Function
	glutIdleFunc(Display); // register Idle Function

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(keyboardSpecialDown);
	glutSpecialUpFunc(keyboardSpecialUp);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);

	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(1000 / 45, Timer, 0);

	tela.Initialize();
	cout << tela.player.c.x << " " << tela.player.c.y;
	glutMainLoop(); // run GLUT mainloop

	return 0;
}

// Mapear teclas
void keyboardDown(unsigned char key, int x, int y) {
	tela.keyboardDown(key, x, y);
}

void keyboardUp(unsigned char key, int x, int y) {
	tela.keyboardUp(key, x, y);
}

//Mapear Teclas Especiais
void keyboardSpecialDown(int key, int x, int y) {
	cout << "Tecla especial pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
}

void keyboardSpecialUp(int key, int x, int y) {
	cout << "Tecla especial solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
}

//Mapear Eventos de Mouse
void mouseClick(int button, int state, int x, int y) {
	tela.mouseClick(button, state, x, y);
}

void mouseMotion(int x, int y) {
	tela.mouseMotion(x, y);
	
}

void Display() {
	tela.Display();
}

void Timer(int value) {
	tela.MovePlayer();
	tela.MoveProjectiles();
	tela.EnemiesShoot();
	glutPostRedisplay();
	glutTimerFunc(5, Timer, value);      /* 30 frames per second */
}


void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	tela.AlteraTamanhoJanela(w, h);
}
