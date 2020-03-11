/*
 * gpu.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */


#include "gpu.h"
#include "utilities.h"
#include <string>
#include <sstream>
#include <iostream>

class Utilities;

Gpu::Gpu() : Component(){
	this->brand = "NO_BRAND";
	this->frequency = 0;
	this->length = 0;
	this->memory = 0;
}

Gpu::Gpu(std::string name, std::string brand, float price, float frequency, int length, float memory) :	Component(name,price)
{
	this->brand = brand;
	this->frequency = frequency;
	this->length = length;
	this->memory = memory;
}

std::string Gpu::getBrand(){ return this->brand; }

float Gpu::getFrequency() { return this->frequency; }

float Gpu::getLength() { return this->length; }

int Gpu::getVramMemory() { return this->memory; }


void Gpu::setBrand(std::string const& brand) { this->brand = brand;}

void Gpu::setFrequency(float frequency) { this->frequency = frequency;}

void Gpu::setLength(float length) { this->length = length;}

void Gpu::setVramMemory(int memory) { this->memory = memory;}


std::string Gpu::toString(){

	std::string vram;
	vram = Utilities::stringify( Gpu::getVramMemory());


	return this->getName() + " - " + this->getBrand() + " " + vram + "GB VRAM";

}

void Gpu::accept(Visitor * v){ return v->visit(this); }

