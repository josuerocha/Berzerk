#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#pragma once
#define M_PI 3.14159
//------------- Estruturas de Dados -----------

typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

struct BoundingBox {
	float x;
	float y;
	float largura;
	float altura;
	BoundingBox(float x, float y, float largura, float altura) {
		this->x = x;
		this->y = y;
		this->largura = largura;
		this->altura = altura;
	}
};

typedef struct Coord {
	float x, y;
	Coord() {};
	Coord(float x1, float y1) {
		x = x1;
		y = y1;
	}
} Coord;

typedef struct Dimensao {
	float largura, altura;
	Dimensao() {};
	Dimensao(float altura, float largura) {
		this->largura = largura;
		this->altura = altura;
	}
} Dimensao;

typedef struct Cor {
	float r, g,b;
	Cor() {};
	Cor(float r, float g, float b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
} Cor;

#endif