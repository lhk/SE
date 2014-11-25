#ifndef KONTO_H_
#define KONTO_H_

class Konto {
public:
	static const int SPARKONTO = 1;
	static const int GIROKONTO = 2;
	static const int TAGESGELDKONTO = 3;

	Konto(int typ);

	int getKontoArt() const;
	void setKontoGuthaben(double guthaben);
	double getKontoGuthaben() const;
	void setID(int id);
	int getID() const;
	double getZinsen();

private:
	int kontoArt;
	double kontoGuthaben;
	int id;
};

#endif /* KONTO_H_ */
