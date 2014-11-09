/*
 * PATM.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: lars
 */

#include "PATM.h"
#include "Assertion.h"

PATM::PATM(double money){
	this->cardInserted=false;
	this->guthaben=money;
}

bool PATM::invariant(){
	Assertion::require(this->guthaben>=0,"money should be within the acceptable interval");
}

void PATM::insertCard(){
	this->invariant();
	Assertion::require(this->cardInserted==false,"no card should be inserted right now");
	this->cardInserted=true;
	Assertion::ensure(this->cardInserted==true,"a card should be inserted right now");
	this->invariant();
}

void PATM::withdrawCard(){
	this->invariant();
	Assertion::require(this->cardInserted==true,"a card should be inserted right now");
	this->cardInserted=false;
	Assertion::ensure(this->cardInserted==false,"no card should be inserted right now");
	this->invariant();
}

void PATM::depositMoney(double money){
	this->invariant();
	Assertion::require(this->cardInserted==true,"there should be an EC card inserted right now");
	this->guthaben+=money;

	this->invariant();
	Assertion::ensure(this->cardInserted==true,"there should be an EC card inserted right now");
}

void PATM::withdrawMoney(double money){
	this->invariant();
	Assertion::require(this->cardInserted==true,"there should be an EC card inserted right now");
	Assertion::require(this->guthaben>=money,"shouldn't try to withdraw too much");

	this->guthaben-=money;
	this->invariant();
	Assertion::ensure(this->cardInserted==true,"there should be an EC card inserted right now");
}
