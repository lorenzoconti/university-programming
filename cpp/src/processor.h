/*
 * processor.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <string>
#include "component.h"

class Processor : public virtual Component {

public:

	Processor();
	Processor(std::string name, std::string brand, float price, std::string socket, float frequency, int cache, int cores);

	virtual ~Processor() {}

	std::string getBrand();
	std::string getSocket();
	float getFrequency();
	int getCache();
	int getCores();

	void setBrand(std::string const&);
	void setSocket(std::string const&);
	void setFrequency(float);
	void setCache(int);
	void seiCores(int);

	std::string toString();

	virtual void accept(Visitor * v);


private:

	std::string brand;
	std::string socket;
	float frequency;
	int cache;
	int cores;
};



#endif /* PROCESSOR_H_ */
