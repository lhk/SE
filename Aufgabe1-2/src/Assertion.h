#ifndef ASSERTION_H_
#define ASSERTION_H_

#include <string>
using namespace std;

#include "PreconditionException.h"
#include "PostconditionException.h"

class Assertion {
public:
	static void require(bool expr, string what) throw(PreconditionException);
	static void ensure(bool expr, string what) throw(PostconditionException);
};

#endif /* ASSERTION_H_ */
