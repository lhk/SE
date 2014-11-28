/*
 * KontoAuszugText.h
 *
 *  Created on: Nov 27, 2014
 *      Author: lars
 */

#ifndef SRC_KONTOAUSZUGTEXT_H_
#define SRC_KONTOAUSZUGTEXT_H_

#include "KontoAuszug.h"

class KontoAuszugText: public KontoAuszug {
public:
	KontoAuszugText(Geldautomat *automat);
	virtual ~KontoAuszugText();
	virtual string headerString(Geldautomat *automat);
	virtual string zinsenString(Geldautomat *automat);
	virtual string footerString(Geldautomat *automat);
};

#endif /* SRC_KONTOAUSZUGTEXT_H_ */
