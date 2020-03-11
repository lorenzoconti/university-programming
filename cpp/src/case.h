/*
 * case.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef CASE_H_
#define CASE_H_

#include "component.h"
#include "enum.h"

class Case : public virtual Component {

public:

	Case();
	Case(std::string name, std::string brand, float price, std::string shape, int fans, int max_gpu_length);

	~Case() {}

	std::string getBrand();
	MoBoShape getShape();
	int getNumberOfFans();
	int getLenghtConstraints();

	void setBrand(std::string const&);
	void setShape(std::string const&);
	void setNumberOfFans(int);
	void setLengthConstraints(int);

	std::string toString();

	virtual void accept(Visitor * v);

private:

	std::string brand;
	MoBoShape shape;
	int fans;
	int max_gpu_length;
};





#endif /* CASE_H_ */
