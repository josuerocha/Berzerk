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
	double x, y;
	Coord() {
		this->x = 0;
		this->y = 0;
	};
	Coord(double x, double y) {
		this->x = x;
		this->y = y;
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
