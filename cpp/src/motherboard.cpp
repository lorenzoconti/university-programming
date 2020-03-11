/*
 * motherboard.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#include "motherboard.h"
#include "enum.h"
#include "utilities.h"
#include <string>
#include <sstream>
#include <iostream>

Motherboard::Motherboard() : Component(){
	this->brand = "NO_BRAND";
	this->socket = "NO_SOCKET";
	this->shape = undefined;
	this->wifi = false;
}

Motherboard::Motherboard(std::string name, std::string brand, float price, std::string socket, std::string shape, bool wifi) :	Component(name,price)
{
	this->brand = brand;
	this->socket = socket;
	this->shape = Utilities::shapeSelector(shape);
	this->wifi = wifi;
}

std::string Motherboard::getBrand(){ return this->brand; }

std::string Motherboard::getSocket(){ return this->socket;}

MoBoShape Motherboard::getShape(){ return this->shape;}

bool Motherboard::hasWifi() { return this->wifi; }

void Motherboard::setBrand(std::string const& brand) { this->brand = brand;}

void Motherboard::setSocket(std::string const& socket) { this->socket = socket;}

void Motherboard::setWifi(bool choice) { this->wifi = choice; }

void Motherboard::setShape(std::string const& shape){ this->shape = Utilities::shapeSelector(shape);};

std::string Motherboard::toString(){

	std::stringstream strstr;
	strstr << this-> getPrice();
	std::string str = strstr.str();

	return this->getName() + " - " + this->getBrand() + " socket: " + this->getSocket() + " " + str + " €";

}

void Motherboard::accept(Visitor * v){ return v->visit(this); }







