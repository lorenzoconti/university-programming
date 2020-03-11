/*
 * comparator.cpp
 *
 *  Created on: 9 gen 2020
 *      Author: loren
 */

#include "comparator.h"

Comparator::Comparator() {}

Comparator::~Comparator() {}

 bool Comparator::compare(Motherboard * m, Processor *p){
	 return m->getSocket().compare(p->getSocket());
 }

 bool Comparator::compare(Motherboard * m, Case * c){
	 return m->getShape() == c->getShape();
 }

 bool Comparator::compare(Processor * p, Motherboard * m){
	 return compare(m,p);
 }

 bool Comparator::compare(Case * c , Motherboard * m ){
	 return compare(m,c);
 }
 bool Comparator::compare(Case * c, Gpu * g){
	 return c->getLenghtConstraints() >= g->getLength();
 }

 bool Comparator::compare(Gpu * g , Case * c){
	 return compare(c,g);
 }
