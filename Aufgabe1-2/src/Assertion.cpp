#include "Assertion.h"

void Assertion::require(bool expr, string what) throw(PreconditionException) {
	if (!expr) {
		throw PreconditionException(what);
	}
}

void Assertion::ensure(bool expr, string what) throw(PostconditionException) {
	if (!expr) {
		throw PostconditionException(what);
	}
}
