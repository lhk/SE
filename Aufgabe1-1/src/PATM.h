/*
 * PATM.h
 *
 *  Created on: Nov 8, 2014
 *      Author: lars
 */

#ifndef SRC_PATM_H_
#define SRC_PATM_H_

class PATM {
public:
	static const int MAX_DEPOSIT = 1000;

	PATM(double money = 0);

	void insertCard();
	void withdrawCard();
	void depositMoney(double money);
	void withdrawMoney(double money);
	bool invariant();

private:
	double guthaben;
	bool cardInserted;
};

#endif /* SRC_PATM_H_ */
