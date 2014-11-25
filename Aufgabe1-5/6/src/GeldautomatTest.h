#ifndef GELDAUTOMATTEST_H_
#define GELDAUTOMATTEST_H_

#include "cute.h"
#include "Geldautomat.h"

class GeldautomatTest {
public:
	/* setUp */
	GeldautomatTest();
	/* tearDown */
	virtual ~GeldautomatTest();
	/* creating a suite */
	static cute::suite makeSuite();

private:
	Geldautomat a;
	Konto k1, k2, k3;

private:
	void zinsenAusdrucken1();
	void zinsenAusdrucken2();
	void zinsenAusdrucken3();
	void zinsenAusdrucken4();
	void zinsenAusdrucken5();
	void geldFluss();
};

#endif /* CUSTOMERTEST_H_ */
