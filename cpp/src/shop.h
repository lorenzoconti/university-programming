/*
 * shop.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef SHOP_H_
#define SHOP_H_

#include <vector>
#include <list>
#include <iostream>
#include "component.h"

class Shop {

public:

	static Shop *getInstance ();

	~Shop(){
		std::cout << "the shop has been destroyed" << std::endl;
	};

	void addComponentToShop(Component *);
	void addComponentToShop(std::vector<Component *>);
	void addComponentToBuild(Component *);

	void showShopComponents();
	void showBuildComponents();

	Component * getComponent(std::string);	// by name
	Component * getComponent(int);			// by index

	Component * bestComponent();

private:

	Shop();

	static Shop *instance;

	std::vector<Component *> clist;
	std::vector<Component *> build;



};



#endif /* SHOP_H_ */
