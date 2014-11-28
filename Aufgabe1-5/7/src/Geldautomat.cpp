#include "Geldautomat.h"
#include "KontoAuszugHTML.h"
#include "KontoAuszugText.h"


Geldautomat::Geldautomat() {
	this->gesamtZinsen = 0;
}

void Geldautomat::kontoHinzufuegen(Konto *k) {
	this->konten.push_back(k);
}
const list<Konto*>& Geldautomat::getKonten() const{
	return this->konten;
}


string Geldautomat::verarbeiteZinsen(){
	ostringstream result;

	list<Konto*>::const_iterator iterator = this->konten.begin();
	while (iterator != this->konten.end()) {
		Konto *each = *iterator;
		double r=each->getZinsen();
		result << "Konto " << each->getID() << " Zinsen: " << r << endl;
		gesamtZinsen = gesamtZinsen + r;

		iterator++;
	}

	return result.str();
}

string Geldautomat::zinsenAusdrucken(){
	return KontoAuszugText(this).value();
}

string Geldautomat::zinsenAusdruckenHTML(){
	return KontoAuszugHTML(this).value();
}


void Geldautomat:: geldAbheben(Konto *konto, double betrag ){
	konto->setKontoGuthaben(((konto->getKontoGuthaben())-betrag));
}

void Geldautomat:: geldEinzahlen(Konto *konto, double betrag){
	konto->setKontoGuthaben(((konto->getKontoGuthaben())+betrag));
}

double Geldautomat::getGesamtZinsen() {
	return this->gesamtZinsen;
}
