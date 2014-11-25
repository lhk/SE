#include "Geldautomat.h"

Geldautomat::Geldautomat() {
	this->gesamtZinsen = 0;
}

void Geldautomat::kontoHinzufuegen(Konto *k) {
	this->konten.push_back(k);
}
double Geldautomat::getZinsen(Konto* aKonto){
		double r = 0;
		switch (aKonto->getKontoArt()) {
		case Konto::SPARKONTO:
			r = 0.025 * aKonto->getKontoGuthaben();
			break;
		case Konto::GIROKONTO:
			r = 0;
			break;
		case Konto::TAGESGELDKONTO:
			r = 0.01 * aKonto->getKontoGuthaben();
			break;
		}
		return r;
}
string Geldautomat::verarbeiteZinsen(){
	ostringstream result;

	list<Konto*>::const_iterator iterator = this->konten.begin();
	while (iterator != this->konten.end()) {
		Konto *each = *iterator;
		double r=getZinsen(each);
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
