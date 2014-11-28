/*
 * KontoAuszugHTML.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: lars
 */

#include "KontoAuszugHTML.h"

KontoAuszugHTML::KontoAuszugHTML(Geldautomat &automat):KontoAuszug(automat) {
	// TODO Auto-generated constructor stub

}

KontoAuszugHTML::~KontoAuszugHTML() {
	// TODO Auto-generated destructor stub
}

string KontoAuszugHTML::headerString(Geldautomat & geldautomat){
	ostringstream result;
	result << "Zinsauszug" << endl;
	result << "---------------------" << endl;
	return result.str();
}

string KontoAuszugHTML::zinsenString(Geldautomat & geldautomat){
	ostringstream result;
	result << geldautomat.verarbeiteZinsen();
	return result.str();
}

string KontoAuszugHTML::footerString(Geldautomat &geldautomat){
	ostringstream result;
	result << "---------------------" << endl;
	result << "Gesamtzinsen: " << geldautomat.getGesamtZinsen() << endl;
	result << "---------------------" << endl;
	return result.str();
}
