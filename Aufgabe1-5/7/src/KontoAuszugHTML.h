/*
 * KontoAuszugHTML.h
 *
 *  Created on: Nov 28, 2014
 *      Author: lars
 */

#ifndef SRC_KONTOAUSZUGHTML_H_
#define SRC_KONTOAUSZUGHTML_H_

#include "KontoAuszug.h"

class KontoAuszugHTML: public KontoAuszug {
public:
	KontoAuszugHTML(Geldautomat *automat);
	virtual ~KontoAuszugHTML();

	virtual string headerString(Geldautomat *automat);
	virtual string zinsenString(Geldautomat *automat);
	virtual string footerString(Geldautomat *automat);
};

#endif /* SRC_KONTOAUSZUGHTML_H_ */
