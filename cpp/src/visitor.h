/*
 * visitor.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef VISITOR_H_
#define VISITOR_H_

class Motherboard;
class Processor;
class Case;
class Gpu;

class Visitor {

public:
	virtual void visit(Motherboard *) = 0;
	virtual void visit(Processor *) = 0;
	virtual void visit(Case *) = 0;
	virtual void visit(Gpu *) = 0;

	virtual ~Visitor(){};
};


#endif /* VISITOR_H_ */
