/*
 * KontoAuszugText.cpp
 *
 *  Created on: Nov 27, 2014
 *      Author: lars
 */

#include "KontoAuszugText.h"

KontoAuszugText::KontoAuszugText(Geldautomat &automat):KontoAuszug(automat) {
	// TODO Auto-generated constructor stub

}

KontoAuszugText::~KontoAuszugText() {
	// TODO Auto-generated destructor stub
}

string KontoAuszugText::headerString(Geldautomat & geldautomat){
	ostringstream result;
	result << "Zinsauszug" << endl;
	result << "---------------------" << endl;
	return result.str();
}

string KontoAuszugText::zinsenString(Geldautomat & geldautomat){
	ostringstream result;
	result << geldautomat.verarbeiteZinsen();
	return result.str();
}

string KontoAuszugText::footerString(Geldautomat &geldautomat){
	ostringstream result;
	result << "---------------------" << endl;
	result << "Gesamtzinsen: " << geldautomat.getGesamtZinsen() << endl;
	result << "---------------------" << endl;
	return result.str();
}
