#ifndef POSTCONDITIONEXCEPTION_H_
#define POSTCONDITIONEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class PostconditionException: public exception {
public:
	PostconditionException(string reason) {
		this->reason = reason;
	}

	virtual ~PostconditionException() throw () {
	}

	virtual const char* what() const throw () {
		return string("Postcondition failed. Reason: ").append(this->reason).c_str();
	}

private:
	string reason;
};

#endif /* POSTCONDITIONEXCEPTION_H_ */
