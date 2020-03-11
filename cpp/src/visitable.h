/*
 * visitable.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef VISITABLE_H_
#define VISITABLE_H_

#include "visitor.h"

class Visitor;

class Visitable {

public:
	virtual ~Visitable() { }
	virtual void accept(Visitor * v) = 0;
};


#endif /* VISITABLE_H_ */
