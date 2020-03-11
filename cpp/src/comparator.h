/*
 * comparator.h
 *
 *  Created on: 9 gen 2020
 *      Author: loren
 */

#ifndef COMPARATOR_H_
#define COMPARATOR_H_

#include "motherboard.h"
#include "processor.h"
#include "case.h"
#include "gpu.h"

class Comparator {

public:
	Comparator();
	 virtual ~Comparator();

	 bool compare(Motherboard *, Processor *);
	 bool compare(Motherboard *, Case *);

	 bool compare(Processor *, Motherboard *);

	 bool compare(Case *, Motherboard * );
	 bool compare(Case *, Gpu * );

	 bool compare(Gpu *, Case *);

};

#endif /* COMPARATOR_H_ */
