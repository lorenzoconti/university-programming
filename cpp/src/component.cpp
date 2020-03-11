/*
 * component.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#include "component.h"
#include <iostream>
#include <sstream>

using namespace std;

Component::Component() {
	name = "";
	price = 0;
	value = 0;
};

Component::Component(std::string const& name, float price){
	this ->name = name;
	this -> price = price;
	this -> value = 0;
}

Component::~Component(){ cout << "component destructor" << endl;}

std::string Component::getName(){
	return this->name;
}

float Component::getPrice(){
	return this->price;
}

void Component::setName(std::string const& name){ this->name = name;}

void Component::setPrice(float price){ this->price = price ;}

int Component::getValue(){ return this->value; }



