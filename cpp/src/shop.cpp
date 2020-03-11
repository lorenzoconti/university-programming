/*
 * shop.cpp
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#include "shop.h"
#include "utilities.h"
#include "motherboard.h"
#include "processor.h"
#include "case.h"
#include "gpu.h"
#include <iostream>

using namespace std;

Shop * Shop::instance = NULL;

Shop::Shop(){}

Shop * Shop::getInstance(){
	return instance ? instance : (instance = new Shop());
}

void Shop::addComponentToShop(Component * c){
	if(c != NULL) clist.push_back(c);
}

void Shop::addComponentToShop(std::vector<Component *> list){

	std::vector<Component *>::iterator i;
	for(i = list.begin(); i < list.end(); i++){
		clist.push_back(*i);
	}

}

void Shop::addComponentToBuild(Component *c){
	if(c != NULL) build.push_back(c);
}

void Shop::showShopComponents(){

	std::vector<Component *> mobos;
	std::vector<Component *> cpus;
	std::vector<Component *> cases;
	std::vector<Component *> gpus;

	std::vector<Component *>::iterator i;

	// dividing components for category

	for(i = clist.begin(); i < clist.end(); i++){
		Utilities::instanceof<Motherboard>(*i) ? mobos.push_back(*i) : void();
		Utilities::instanceof<Processor>(*i) ? cpus.push_back(*i) : void();
		Utilities::instanceof<Case>(*i) ? cases.push_back(*i) : void();
		Utilities::instanceof<Gpu>(*i) ? gpus.push_back(*i) : void();
	}

	std::string p = "******************************************************";

	cout << "\n" << p << "\n   WELCOME TO CPP COMPONENTS SHOP\n" << p << endl;

	cout << "\nAVAILABLE MOTHERBOARDS: " << endl;
	for(i = mobos.begin(); i < mobos.end(); i++) { cout << (*i)->toString() << endl; }

	cout << "\nAVAILABLE PROCESSORS: " << endl;
	for(i = cpus.begin(); i < cpus.end(); i++) { cout << (*i)->toString() << endl; }

	cout << "\nAVAILABLE CASES: " << endl;
	for(i = cases.begin(); i < cases.end(); i++) { cout << (*i)->toString() << endl; }

	cout << "\nAVAILABLE GRAPHIC VIDEO CARDS: " << endl;
	for(i = gpus.begin(); i < gpus.end(); i++) { cout << (*i)->toString() << endl; }

	delete &mobos;
	delete &cpus;
	delete &gpus;
	delete &cases;

}

void Shop::showBuildComponents(){

	if(build.empty()) cout << "Your build is empty! Select some components from the shop." << endl;

	cout << "\nTHIS IS YOUR BUILD" << endl;

	std::vector<Component *>::iterator i;
	for(i = build.begin(); i < build.end(); i++){ cout << (*i)->toString() << endl;	}
}

//TODO

Component * Shop::getComponent(std::string){ // by name
	return NULL;
}

Component * Shop::getComponent(int){	// by index
	return NULL;
}

Component * Shop::bestComponent(){
	return NULL;
}


