/*
 * processor.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#include "processor.h"
#include <string>
#include <sstream>
#include <iostream>

Processor::Processor() : Component(){
	this->brand = "NO_BRAND";
	this->cache = 0;
	this->cores = 0;
	this->frequency = 0;
	this->socket = "NO_SOCKET";
}

Processor::Processor(std::string name, std::string brand, float price, std::string socket, float frequency, int cache, int cores) :	Component(name,price)
{
	this->brand = brand;
	this->cache = cache;
	this->cores = cores;
	this->frequency = frequency;
	this->socket = socket;
}

std::string Processor::getBrand(){ return this->brand; }

std::string Processor::getSocket(){ return this->socket;}

float Processor::getFrequency() { return this->frequency; }

int Processor::getCache() {return this->cache;}

int Processor::getCores() {return this->cores;}

void Processor::setBrand(std::string const& brand) { this->brand = brand;}

void Processor::setSocket(std::string const& socket) { this->socket = socket;}

void Processor::setFrequency(float frequency) { this->frequency = frequency;}

void Processor::setCache(int cache) { this->cache = cache;}

void Processor::seiCores(int cores) { this->cores = cores;}

std::string Processor::toString(){

	std::stringstream strstr;
	strstr << this->getCache();
	std::string str = strstr.str();

	return this->getName() + " - " + this->getBrand() + " socket: " + this->getSocket() + " " + str + "MB Cache";

}

void Processor::accept(Visitor * v){ return v->visit(this); }







