/*
 * gpu.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef GPU_H_
#define GPU_H_

#include "component.h"
#include <string>

class Gpu : public Component {

public:


	Gpu();
	Gpu(std::string name, std::string brand, float price, float frequency, int length, float memory);

	virtual ~Gpu() {}

	std::string getBrand();
	float getFrequency();
	float getLength();
	int getVramMemory();

	void setBrand(std::string const&);
	void setFrequency(float);
	void setLength(float length);
	void setVramMemory(int memory);

	std::string toString();

	void accept(Visitor * v);

private:

	std::string brand;
	float frequency;
	float length;
	int memory;
};



#endif /* GPU_H_ */
