#include "Konto.h"

#include <stdlib.h>

Konto::Konto(int typ) {
	this->kontoArt = typ;
	this->kontoGuthaben = 0;
	this->id = rand() % 8999 + 1000;
}

double Konto::getKontoGuthaben() const {
	return this->kontoGuthaben;
}
void Konto::setKontoGuthaben(double guthaben) {
	this->kontoGuthaben = guthaben;
}

int Konto::getKontoArt() const {
	return this->kontoArt;
}

void Konto::setID(int id) {
	this->id = id;
}

int Konto::getID() const {
	return this->id;
}
