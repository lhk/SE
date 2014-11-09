#ifndef WITHDRAWALEXCEPTION_H_
#define WITHDRAWALEXCEPTION_H_

#include <exception>
using namespace std;

class WithdrawalException: public exception {
public:
	virtual const char* what() const throw () {
		return "The withdrawal cannot be executed";
	}
};

#endif /* CARDINSERTEDEXCEPTION_ */
