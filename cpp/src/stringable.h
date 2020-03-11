/*
 * stringable.h
 *
 *  Created on: 8 gen 2020
 *      Author: loren
 */

#ifndef STRINGABLE_H_
#define STRINGABLE_H_

#include <string>

class Stringable{
public:

	virtual ~Stringable() {}
	virtual std::string toString() = 0;

};



#endif /* STRINGABLE_H_ */
