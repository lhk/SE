#ifndef GELDAUTOMAT_H_
#define GELDAUTOMAT_H_

#include <list>
#include <string>
#include <sstream>

#include "Konto.h"

using namespace std;

class Geldautomat{
public:
	Geldautomat();

	void geldAbheben(Konto *konto, double betrag );
	void geldEinzahlen(Konto *konto, double betrag);
	void kontoHinzufuegen(Konto* k);
	string zinsenAusdrucken();
	string zinsenAusdruckenHTML();
	double getGesamtZinsen();
	const list<Konto*>& getKonten()const;
	string verarbeiteZinsen();

private:
	list<Konto*> konten;
	double gesamtZinsen;
	double getZinsen(Konto* aKonto);
};

#endif /* GELDAUTOMAT_H_ */
