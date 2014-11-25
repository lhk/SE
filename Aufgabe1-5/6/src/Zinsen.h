/*
 * Zinsen.h
 *
 *  Created on: Nov 25, 2014
 *      Author: lars
 */

#ifndef SRC_ZINSEN_H_
#define SRC_ZINSEN_H_

class Zinsen {
public:
	Zinsen();
	virtual ~Zinsen();

	virtual double getRate()=0;
};

#endif /* SRC_ZINSEN_H_ */
