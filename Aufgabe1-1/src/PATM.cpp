/*
 * PATM.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: lars
 */

#include "PATM.h"
#include "CardInsertedException.h"
#include "NoCardInsertedException.h"
#include "InvarianceException.h"
#include "WithdrawalException.h"

PATM::PATM(double money){
	this->cardInserted=false;
	this->guthaben=money;
}

bool PATM::invariant(){
	if(this->guthaben<0)
		throw new InvarianceException();
}

void PATM::insertCard(){
	this->invariant();
	if(this->cardInserted)
		throw new CardInsertedException();

	this->cardInserted=true;

	if(!this->cardInserted)
		throw new NoCardInsertedException();
	this->invariant();
}

void PATM::withdrawCard(){
	this->invariant();
	if(!this->cardInserted)
		throw new NoCardInsertedException();

	this->cardInserted=false;

	if(this->cardInserted)
		throw new CardInsertedException();
	this->invariant();
}

void PATM::depositMoney(double money){
	this->invariant();
	if(!this->cardInserted)
		throw new NoCardInsertedException();

	this->guthaben+=money;

	if(!this->cardInserted)
		throw new NoCardInsertedException();
	this->invariant();
}

void PATM::withdrawMoney(double money){
	this->invariant();
	if(!this->cardInserted)
		throw new NoCardInsertedException();
	if(this->guthaben<money)
		throw new WithdrawalException();

	this->guthaben-=money;

	if(!this->cardInserted)
		throw new NoCardInsertedException();
	this->invariant();
}
