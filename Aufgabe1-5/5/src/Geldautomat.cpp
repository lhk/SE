#include "Geldautomat.h"

Geldautomat::Geldautomat() {
	this->gesamtZinsen = 0;
}

void Geldautomat::kontoHinzufuegen(Konto *k) {
	this->konten.push_back(k);
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

string Geldautomat::zinsenAusdrucken() {
	ostringstream result;
	result << "Zinsauszug" << endl;
	result << "---------------------" << endl;

	result<<verarbeiteZinsen();

	result << "---------------------" << endl;
	result << "Gesamtzinsen: " << gesamtZinsen << endl;
	result << "---------------------" << endl;

	return result.str();
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
