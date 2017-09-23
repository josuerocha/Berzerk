
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

int xponto = 100; int yponto = 300;
int xponto2 = 740; int yponto2 = 200;
int percorreLinha = 0;
int percorreColuna = 0;

int xpontoparedeEsq = 25; int ypontoparedeEsq = 50;
int ypontoparede2 = 550;
int xpontoparedeDirIn = 1040; int xpontoparedeDirFin = 740;

int matTela [26][50];
int vetCores[50];

int qtdLinhas = 26;
int qtdColunas = 50;
int linha = 0;
int coluna = 0;


void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}



void DesenhaFase() {

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
				glVertex2i(xpontoParedeAtualizado1, ypontoParedeAtualizado1);
	
				// Especifica que a cor corrente é azul
				glColor3f(vetCores[3], vetCores[4], vetCores[5]);
				glVertex2i(xpontoParedeAtualizado2, ypontoParedeAtualizado1);
				glVertex2i(xpontoParedeAtualizado2, ypontoParedeAtualizado2);


				glEnd();
				
			}
			else if (matTela[percorreLinha][percorreColuna] == 0) {
				xpontoParedeAtualizado2 = xpontoParedeAtualizado1 + 20;

			}
			/* Cria personagens */
			else if (matTela[percorreLinha][percorreColuna] == 2) {

			}
			/**/
			/* Cria inimigos */
			else if (matTela[percorreLinha][percorreColuna] == 3) {

			}
			/**/

			xpontoParedeAtualizado1 = xpontoParedeAtualizado2;
		}

		ypontoParedeAtualizado2 = ypontoParedeAtualizado2 + 20;
		ypontoParedeAtualizado1 = ypontoParedeAtualizado1 + 20;
		xpontoParedeAtualizado1 = 25;
		xpontoParedeAtualizado2 = 50;


	}

}
void Desenha2(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//	DesenhaPersonagem();
	DesenhaFase();


	glutSwapBuffers();
	glFlush;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
		gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f*h / w);
	else
		gluOrtho2D(0.0f, 800.0f*w / h, 0.0f, 600.0f);
}


void lerArquivo()
{
	char url[] = "fase1.txt";
	char ch;
	FILE *arq;

	int ich;
	int vetPosicao=0;

	arq = fopen(url, "r");
	if (arq == NULL) {
		printf("Erro, nao foi possivel abrir o arquivo\n");
	}
	else {
		while ((ch = fgetc(arq)) != EOF) {

			

			if (ch != '\n' && ch != '\t') {

			/*	if (linha == 0) {

					vetCores[vetPosicao] = ch - '0';
					
					//printf("%f", &vetCores[vetPosicao]);
					
					putchar(ch);

					vetPosicao++;
				}
				else {
				*/
				if (linha == 26) {
					vetCores[vetPosicao] = ch - '0';
					putchar(ch);
					vetPosicao++;

				}else{

					matTela[linha][coluna] = ch - '0';
	
				coluna++;
				}
			}
			if (ch == '\n') {
				printf("\n");
				linha++;
				coluna = 0;
			}
		}

		fclose(arq);
		//Desenha2();

	}

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(270, 80);

	glutCreateWindow("Fase");
	glutIdleFunc(Desenha2);
	// registra glut callbacks
	//glutKeyboardFunc(keyboardDown);
	//glutKeyboardUpFunc(keyboardUp);
	//glutSpecialFunc(keyboardSpecialDown);
	//glutSpecialUpFunc(keyboardSpecialUp);
	
	//glutMotionFunc(mouseMotion);
	glutDisplayFunc(Desenha2);
	glutReshapeFunc(AlteraTamanhoJanela);
	lerArquivo();

	//DesenhaTexto("TESTE");
	Inicializa();
	glutMainLoop();

	return 0;
}


