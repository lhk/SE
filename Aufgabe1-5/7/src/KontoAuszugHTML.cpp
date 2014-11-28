/*
 * KontoAuszugHTML.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: lars
 */

#include "KontoAuszugHTML.h"

KontoAuszugHTML::KontoAuszugHTML(Geldautomat *automat):KontoAuszug(automat) {
	// TODO Auto-generated constructor stub

}

KontoAuszugHTML::~KontoAuszugHTML() {
	// TODO Auto-generated destructor stub
}

string KontoAuszugHTML::headerString(Geldautomat * geldautomat){
	ostringstream result;
	result << "<html>"<<endl;
	result << "<h1>Zinsauszug</h1>" << endl;
	result << "</hline>" << endl;
	return result.str();
}

string KontoAuszugHTML::zinsenString(Geldautomat * geldautomat){
	ostringstream result;
	result<<"<br>"<<endl;
	result << geldautomat->verarbeiteZinsen();
	result<< "</br>"<<endl;
	return result.str();
}

string KontoAuszugHTML::footerString(Geldautomat *geldautomat){
	ostringstream result;
	result << "</hline>" << endl;
	result << "<br>Gesamtzinsen: " << geldautomat->getGesamtZinsen()<<"</br>" << endl;
	result << "</hline>" << endl;
	result << "</html>" <<endl;
	return result.str();
}
