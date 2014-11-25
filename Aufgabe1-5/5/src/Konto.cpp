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

double Konto::getZinsen(){
		double r = 0;
		switch (this->getKontoArt()) {
		case Konto::SPARKONTO:
			r = 0.025 * this->getKontoGuthaben();
			break;
		case Konto::GIROKONTO:
			r = 0;
			break;
		case Konto::TAGESGELDKONTO:
			r = 0.01 * this->getKontoGuthaben();
			break;
		}
		return r;
}
