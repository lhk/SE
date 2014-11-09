#ifndef CARDINSERTEDEXCEPTION_H_
#define CARDINSERTEDEXCEPTION_H_

#include <exception>
using namespace std;

class CardInsertedException: public exception {
public:
	virtual const char* what() const throw () {
		return "There is a card inserted.";
	}
};

#endif /* CARDINSERTEDEXCEPTION_ */
