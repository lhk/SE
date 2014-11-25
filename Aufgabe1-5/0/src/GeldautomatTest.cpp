#include "GeldautomatTest.h"

#include <string.h>
#include <sstream>
using namespace std;

GeldautomatTest::GeldautomatTest() :
		a(), k1(Konto::SPARKONTO), k2(Konto::GIROKONTO), k3(
				Konto::TAGESGELDKONTO) {
}

GeldautomatTest::~GeldautomatTest() {
}

cute::suite GeldautomatTest::makeSuite() {
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, zinsenAusdrucken1));
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, zinsenAusdrucken2));
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, zinsenAusdrucken3));
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, zinsenAusdrucken4));
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, zinsenAusdrucken5));
	s.push_back(CUTE_SMEMFUN(GeldautomatTest, geldFluss));
	return s;
}

void GeldautomatTest::zinsenAusdrucken1() {
	k1.setKontoGuthaben(200);
	a.kontoHinzufuegen(&k1);
	a.zinsenAusdrucken();
	ASSERT_EQUAL(5, a.getGesammtZinsen());

}

void GeldautomatTest::zinsenAusdrucken2() {
	k1.setKontoGuthaben(200);
	k2.setKontoGuthaben(100);
	a.kontoHinzufuegen(&k1);
	a.kontoHinzufuegen(&k2);
	a.zinsenAusdrucken();
	ASSERT_EQUAL(5, a.getGesammtZinsen());
}

void GeldautomatTest::zinsenAusdrucken3() {
	k1.setKontoGuthaben(200);
	k2.setKontoGuthaben(100);
	k3.setKontoGuthaben(400);
	a.kontoHinzufuegen(&k1);
	a.kontoHinzufuegen(&k2);
	a.kontoHinzufuegen(&k3);
	a.zinsenAusdrucken();
	ASSERT_EQUAL(9, a.getGesammtZinsen());
}

void GeldautomatTest::zinsenAusdrucken4() {
	a.zinsenAusdrucken();
	ASSERT_EQUAL(0, a.getGesammtZinsen());
}

void GeldautomatTest::zinsenAusdrucken5() {
	k1.setKontoGuthaben(200);
	k2.setKontoGuthaben(100);
	k3.setKontoGuthaben(400);
	a.kontoHinzufuegen(&k1);
	a.kontoHinzufuegen(&k2);
	a.kontoHinzufuegen(&k3);

	ostringstream result;
	result << "Zinsauszug" << endl;
	result << "---------------------" << endl;
	result << "Konto " << k1.getID() << " Zinsen: 5" << endl;
	result << "Konto " << k2.getID() << " Zinsen: 0" << endl;
	result << "Konto " << k3.getID() << " Zinsen: 4" << endl;
	result << "---------------------" << endl;
	result << "Gesamtzinsen: 9" << endl;
	result << "---------------------" << endl;

	ASSERT_EQUAL(a.zinsenAusdrucken(), result.str());
}

void GeldautomatTest::geldFluss() {
	k2.setKontoGuthaben(0);
	a.geldEinzahlen(&k2, 500);
	ASSERT_EQUAL(500, k2.getKontoGuthaben());
	a.geldAbheben(&k2, 500);
	ASSERT_EQUAL(0, k2.getKontoGuthaben());
}
