//============================================================================
// Name        : info3-cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "component.h"
#include "shop.h"
#include "evaluator.h"
#include "comparator.h"

int main() {

	Processor * c1 = new Processor("i7 9700K", "Intel", 370.0, "1151", 4.4, 9, 12 );

	Processor * c2 = new Processor("i7 9600F", "Intel", 350.0, "1151", 3.9, 8, 10 );

	Motherboard * c3 = new Motherboard("x570 Pro", "Asus", 270.0, "AM4", "ATX", false);

	Case * c4 = new Case("h510i","NZXT", 110.0, "ATX", 5, 32);

	Gpu * c5 = new Gpu("RTX 2060 Super", "Gigabyte", 499.00, 14000, 28, 8);

	Shop * shop = Shop::getInstance();

	shop->addComponentToShop(c1);
	shop->addComponentToShop({c2,c3,c4,c5});

	shop->showShopComponents();

	Comparator comparator;		// ALTERNATIVE VISITOR

	if(comparator.compare(c3,c4)) std::cout << "compatibili" << std::endl;
	if(comparator.compare(c1,c3)) std::cout << "compatibili" << std::endl;

	Evaluator * e = new Evaluator();

	c2->accept(e);
	std::cout << c2->getValue();

	return 0;
}
