#include "AnimacaoFinal.h"

AnimacaoFinal::AnimacaoFinal()
{
	contador = 0;
	isActive = true;
}

void AnimacaoFinal::Reset() {
	isActive = false;
	contador = 0;
}

AnimacaoFinal::~AnimacaoFinal()
{
}

void AnimacaoFinal::Display() {
	contador++;
	if (contador >= 1000) {
		isActive = false;
	}
	FuncoesExtra::DesenhaTexto("VOCE ZEROU O JOGO PARABENS!!!!!!!", Coord(450, 450), Cor(1, 1, 1));
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();               // Reset the model-view matrix

	glPushMatrix();                     // Save model-view matrix set
	int i;
	float translateX = -1.1f;
	//float translateX = -1.1f;

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;


	for (i = 0; i < 8; i++) {

		glPushMatrix();                     // Save model-view matrix setting
		glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
		glTranslatef(translateX, -0.2f, 0.0f);    // Translate

		if (i % 2 == 0) {
			r = 0.6f;
			g = 0.0f;
			b = 1.0f;
		}
		else {
			r = 0.0f;
			g = 1.0f;
			b = 1.0f;
		}

		glColor3f(r, g, b);
		glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
		glVertex2f(-0.1f, -0.1f);
		glVertex2f(0.1f, -0.1f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.1f, 0.1f);
		glVertex2f(-0.1f, 0.1f);
		glEnd();
		glPopMatrix();
		translateX = translateX + 0.3f;
	}


	glPushMatrix();                     // Save model-view matrix setting

										/*Texto*/

	i;
	translateX = -1.1f;
	//float translateX = -1.1f;

	r = 0.0f;
	g = 0.0f;
	b = 0.0f;


	for (i = 0; i < 8; i++) {

		glPushMatrix();                     // Save model-view matrix setting
		glTranslatef(translateX, -0.2f, 0.0f);    // Translate

		glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees

		if (i % 2 == 0) {
			r = 0.6f;
			g = 0.0f;
			b = 1.0f;
		}
		else {
			r = 0.0f;
			g = 1.0f;
			b = 1.0f;
		}

		glColor3f(r, g, b);
		glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
		glVertex2f(-0.1f, -0.1f);
		glVertex2f(0.1f, -0.1f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.1f, 0.1f);
		glVertex2f(-0.1f, 0.1f);
		glEnd();
		glPopMatrix();
		translateX = translateX + 0.3f;
	}

	glutSwapBuffers();

	angle += 2.0f;
	glFlush;
}

void AnimacaoFinal::Reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}