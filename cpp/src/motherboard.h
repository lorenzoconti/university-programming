/*
 * motherboard.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef MOTHERBOARD_H_
#define MOTHERBOARD_H_

#include "component.h"
#include "enum.h"

class Motherboard : public virtual Component {

public:

	Motherboard();
	Motherboard(std::string name, std::string brand, float price, std::string socket, std::string shape, bool wifi);

	virtual ~Motherboard() {}

	std::string getBrand();
	std::string getSocket();
	MoBoShape getShape();
	bool hasWifi();

	void setBrand(std::string const&);
	void setSocket(std::string const&);
	void setShape(std::string const&);
	void setWifi(bool);

	std::string toString();

	virtual void accept(Visitor * v);

private:

	std::string brand;
	std::string socket;
	MoBoShape shape;
	bool wifi;
};


#endif /* MOTHERBOARD_H_ */
