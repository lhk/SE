/*
 * Statement.cpp
 *
 *  Created on: Nov 27, 2014
 *      Author: lars
 */

#include "KontoAuszug.h"

KontoAuszug::KontoAuszug(Geldautomat &automat): automat(automat) {
}

KontoAuszug::~KontoAuszug() {
}

string KontoAuszug::value(){
	ostringstream result;
	result << this->headerString(this->automat);
	result << this->zinsenString(this->automat);
	result << this->footerString(this->automat);
	return result.str();
}
