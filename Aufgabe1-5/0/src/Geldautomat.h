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
	double getGesammtZinsen();

private:
	list<Konto*> konten;
	double gesammtZinsen;
};

#endif /* GELDAUTOMAT_H_ */
