#ifndef NOCARDINSERTEDEXCEPTION_
#define NOCARDINSERTEDEXCEPTION_

#include <exception>
using namespace std;

class NoCardInsertedException: public exception {
public:
	virtual const char* what() const throw () {
		return "There is no card inserted.";
	}
};

#endif /* CARDINSERTEDEXCEPTION_ */
