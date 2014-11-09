#ifndef INVARIANCEEXCEPTION_H_
#define INVARIANCEEXCEPTION_H_

#include <exception>
using namespace std;

class InvarianceException: public exception {
public:
	virtual const char* what() const throw () {
		return "The balance is too low";
	}
};

#endif /* NOCOININSERTEDEXCEPTION_H_ */
