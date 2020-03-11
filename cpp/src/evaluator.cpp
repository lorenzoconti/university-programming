/*
 * evaluator.cpp
 *
 *  Created on: 9 gen 2020
 *      Author: loren
 */

#include "evaluator.h"

#include "motherboard.h"
#include "processor.h"
#include "case.h"
#include "gpu.h"


Evaluator::Evaluator() {}

Evaluator::~Evaluator() {}

 void Evaluator::visit(Motherboard * m){ m->value = 400 - m->hasWifi()*50 - m->getPrice(); }

 void Evaluator::visit(Processor * p){ p->value = p->getCache()*20 + p->getCores()*20 + (p->getFrequency()+5)*20 - p->getPrice();}

 void Evaluator::visit(Gpu * g ){ g->value = g->getFrequency()/1000 + g->getVramMemory()*50 - g->getPrice();}

 void Evaluator::visit(Case * c){ c->value = c->getNumberOfFans()*50 - c->getPrice();}

