#include "Medkit.h"
Medkit::Medkit() {

}

Medkit::Medkit(Coord coord, Cor cor, Dimensao dim, bool status, int cura) {
	this->c = coord;
	this->cor = cor;
	this->d = dim;
	this->active = status;
	this->cura = cura;
}

float Medkit::getCura() {
	return cura;
}