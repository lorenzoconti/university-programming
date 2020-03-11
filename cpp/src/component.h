/*
 * component.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "visitable.h"
#include "stringable.h"

#include <string>

class Component : public Visitable, public Stringable {

public:

	friend class Evaluator;

	~Component();

	std::string getName();
	float getPrice();

	void setName(std::string const&);
	void setPrice(float);

	int getValue();

	std::string toString() = 0;

	virtual void accept(Visitor * v) = 0;

protected:

	Component();
	Component(std::string const&, float);

private:

	float price;
	std::string name;
	int value;

};





#endif /* COMPONENT_H_ */
