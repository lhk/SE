/*
 * TagesgeldZinsen.h
 *
 *  Created on: Nov 25, 2014
 *      Author: lars
 */

#ifndef SRC_TAGESGELDZINSEN_H_
#define SRC_TAGESGELDZINSEN_H_

#include "Zinsen.h"

class TagesgeldZinsen: public Zinsen {
public:
	TagesgeldZinsen();
	virtual ~TagesgeldZinsen();

	double getRate();
};

#endif /* SRC_TAGESGELDZINSEN_H_ */
