#ifndef GELDAUTOMAT_H_
#define GELDAUTOMAT_H_

#include <list>
#include <string>
#include <sstream>
using namespace std;

#include "Konto.h"

class Geldautomat {
public:
	Geldautomat();

	void geldAbheben(Konto *konto, double betrag );
	void geldEinzahlen(Konto *konto, double betrag);
	void kontoHinzufuegen(Konto* k);
	string zinsenAusdrucken();
	double getGesamtZinsen();

private:
	list<Konto*> konten;
	double gesamtZinsen;
	string verarbeiteZinsen();
};

#endif /* GELDAUTOMAT_H_ */
