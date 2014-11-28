/*
 * GiroZinsen.h
 *
 *  Created on: Nov 25, 2014
 *      Author: lars
 */

#ifndef SRC_GIROZINSEN_H_
#define SRC_GIROZINSEN_H_

#include "Zinsen.h"

class GiroZinsen: public Zinsen {
public:
	GiroZinsen();
	virtual ~GiroZinsen();

	double getRate();
};

#endif /* SRC_GIROZINSEN_H_ */
