/*
 * evaluator.h
 *
 *  Created on: 9 gen 2020
 *      Author: loren
 */

#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "visitor.h"

class Evaluator : public Visitor {

public:
	Evaluator();
	virtual ~Evaluator();

	virtual void visit(Motherboard *);
	virtual void visit(Processor *);
	virtual void visit(Gpu *);
	virtual void visit(Case *);
};

#endif /* EVALUATOR_H_ */
