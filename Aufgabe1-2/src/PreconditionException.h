#ifndef PRECONDITIONEXCEPTION_H_
#define PRECONDITIONEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class PreconditionException: public exception {
public:
	PreconditionException(string reason) {
		this->reason = reason;
	}

	virtual ~PreconditionException() throw () {
	}

	virtual const char* what() const throw () {
		return string("Precondition failed. Reason: ").append(this->reason).c_str();
	}

private:
	string reason;
};

#endif /* PRECONDITIONEXCEPTION_H_ */
