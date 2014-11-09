//============================================================================
// Name        : Aufgabe1-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PATM.h"
using namespace std;

int main() {
	PATM myAtm;
	myAtm.insertCard();
	myAtm.depositMoney(10);
	myAtm.withdrawMoney(5);
	myAtm.withdrawCard();
	cout<<"finished";
	return 0;
}
