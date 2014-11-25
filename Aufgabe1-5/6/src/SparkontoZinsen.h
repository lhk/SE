/*
 * SparkontoZinsen.h
 *
 *  Created on: Nov 25, 2014
 *      Author: lars
 */

#ifndef SRC_SPARKONTOZINSEN_H_
#define SRC_SPARKONTOZINSEN_H_

#include "Zinsen.h"

class SparkontoZinsen: public Zinsen {
public:
	SparkontoZinsen();
	virtual ~SparkontoZinsen();

	double getRate();
};

#endif /* SRC_SPARKONTOZINSEN_H_ */
