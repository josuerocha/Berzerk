#include "AnimacaoInicial.h"
using namespace std;

AnimacaoInicial::AnimacaoInicial()
{
	x1 = 50;
	yaa = -8;
	py = 330;
	x2 = 50;
	y2 = -35;
	x3 = 50;
	y3 = -62;
	x4 = 50;
	y4 = -139;
	x5 = 50;
	y5 = -166;
	x6 = 50;
	y6 = -193;
	x7 = 50;
	y7 = -270;
	x8 = 50;
	y8 = -297;
	x9 = 50;
	y9 = -324;
	x10 = 50;
	y10 = -401;
	x11 = 50;
	y11 = -428;
	x12 = 50;
	y12 = -455;

	fps = 1000 / 45;
	tempomaximo = 10000;
	tempo = 0;
	tempoapresentacao = 0;
	tempoTotal = 14000;
	emAnimacao = true;
}

AnimacaoInicial::~AnimacaoInicial() {
}

bool AnimacaoInicial::Run() {
	if (emAnimacao) {
		tempo = tempo + fps;
		if (tempo > 100) {
			tempo = 0;
			py = py + 10;
			yaa = yaa + 10;
			y2 = y2 + 10;
			y3 = y3 + 10;
			y4 = y4 + 10;
			y5 = y5 + 10;
			y6 = y6 + 10;
			y7 = y7 + 10;
			y8 = y8 + 10;
			y9 = y9 + 10;
			y10 = y10 + 10;
			y11 = y11 + 10;
			y12 = y12 + 10;
		}

		char *texto = "BERZERK - CIVIL WAR";
		EscreveSubida("BERZERK - CIVIL WAR", 340, 0.9);

		tempoapresentacao += fps;
		if (tempoapresentacao > tempoTotal) {
			return true;
		}
		else { return false; }

	}
}

void AnimacaoInicial::EscreveSubida(char *string, int px, int velocidade) {
		char *aux = string;
		char *aux2 = "Estamos em um periodo de guerra civil. ";
		char *aux3 = "Partindo de uma base secreta, berzerkianos rebeldes atacam e conquistam ";
		char *aux4 = "sua primeira vitoria contra o perverso Imperio Robotico. ";
		char *aux5 = "Durante a batalha, espioes berzerkianos rebeldes conseguem roubar os";
		char *aux6 = "planos secretos da arma decisiva do Imperio, a BERZERKUTOR,";
		char *aux7 = "uma arma muito potente e com um  poder de destruicao muito grande.";
		char *aux8 = "Perseguida pelos robos agentes do Imperio Robotico, a guerreia Raven,";
		char *aux9 = "apressou-se em voltar para a estacao dos berzerkianos, protegendo as ";
		char *aux10 = "informações roubadas e utilizando-as em favor dos berzerkianos. ";
		char *aux11 = "Agora a guerreira berzerkiana tem como missao, derrubar o Imperio ";
		char *aux12 = "Robotico, que tanto mal e desordem ja causou, para salvar o seu povo e";
		char *aux13 = "restaurar a paz e a liberdade em seu planeta .... ";


		int cont = 0;
		glClearColor(0.0, 0.0, 0.0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.00f, 1.00f, 1.00f);
		glPushMatrix();
		glRasterPos2f(px, py);

		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		int m = 0;
		int n = 0;
		int o = 0;
		int p = 0;
		int q = 0;
		int r = 0;
		int s = 0;
		int t = 0;
		int u = 0;

		while (aux[i] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux[i++]);
		}

		glRasterPos2f(x1, yaa);
		while (aux2[j] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux2[j++]);
		}
		glRasterPos2f(x2, y2);
		while (aux3[k] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux3[k++]);
		}
		glRasterPos2f(x3, y3);
		while (aux4[l] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux4[l++]);
		}
		glRasterPos2f(x4, y4);
		while (aux5[m] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux5[m++]);
		}
		glRasterPos2f(x5, y5);
		while (aux6[n] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux6[n++]);
		}
		glRasterPos2f(x6, y6);
		while (aux7[o] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux7[o++]);
		}
		glRasterPos2f(x7, y7);
		while (aux8[p] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux8[p++]);
		}
		glRasterPos2f(x8, y8);
		while (aux9[q] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux9[q++]);
		}
		glRasterPos2f(x9, y9);
		while (aux10[r] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux10[r++]);
		}
		glRasterPos2f(x10, y10);
		while (aux11[s] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux11[s++]);
		}
		glRasterPos2f(x11, y11);
		while (aux12[t] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux12[t++]);
		}
		glRasterPos2f(x12, y12);
		while (aux13[u] != '\0') {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aux13[u++]);
		}

		cont++;

		glPopMatrix();
		glutPostRedisplay();
		glFlush();
	}
