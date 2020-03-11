/*
 * case.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#include "case.h"

#include "enum.h"
#include "utilities.h"
#include <string>
#include <sstream>
#include <iostream>

class Utilities;

Case::Case() : Component(){
	this->brand = "NO_BRAND";
	this->shape = undefined;
	this->fans = 0;
	this->max_gpu_length =0;
}

Case::Case(std::string name, std::string brand, float price, std::string shape, int fans, int max_gpu_length) :	Component(name,price)
{
	this->brand = brand;
	this->shape = Utilities::shapeSelector(shape);
	this->fans = fans;
	this->max_gpu_length = max_gpu_length;
}

std::string Case::getBrand(){ return this->brand; }

int Case::getLenghtConstraints(){ return this->max_gpu_length;}

int Case::getNumberOfFans() { return this->fans; }

MoBoShape Case::getShape(){ return this->shape;}

void Case::setBrand(std::string const& brand) { this->brand = brand;}

void Case::setShape(std::string const& shape){ this->shape = Utilities::shapeSelector(shape);};

std::string Case::toString(){

	std::stringstream strstr;
	strstr << this-> getPrice();
	std::string str = strstr.str();

	return this->getName() + " - " + this->getBrand() + " " + str + " €";

}

void Case::accept(Visitor * v){ return v->visit(this); }



