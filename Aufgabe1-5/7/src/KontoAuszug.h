/*
 * Statement.h
 *
 *  Created on: Nov 27, 2014
 *      Author: lars
 */

#ifndef SRC_KONTOAUSZUG_H_
#define SRC_KONTOAUSZUG_H_

#include <list>
#include <string>
#include <sstream>

#include "Geldautomat.h"

using namespace std;

class KontoAuszug {
public:
	KontoAuszug(Geldautomat *automat);
	virtual ~KontoAuszug();

	string value();
	virtual string headerString(Geldautomat *automat)=0;
	virtual string zinsenString(Geldautomat *automat)=0;
	virtual string footerString(Geldautomat *automat)=0;

private:
	Geldautomat* automat;
};

#endif /* SRC_KONTOAUSZUG_H_ */
