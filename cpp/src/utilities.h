#include <string>
#include <sstream>
#include <iostream>

#include "enum.h"

class Utilities {
public:

	static MoBoShape shapeSelector(std::string const& shape){

		if(shape.compare("ATX")) return ATX;
		if(shape.compare("mATX")) return mATX;
		if(shape.compare("microATX")) return microATX;
		return undefined;
	}

	template <typename T> static std::string stringify(T t){
		std::stringstream s;
		s << t;
		return s.str();
	}

	template <typename Base, typename T> static bool instanceof(T *ptr) {

	    return dynamic_cast<const Base*>(ptr) != nullptr;
	}

	static bool better(Component * c1, Component * c2){

		int v1 = c1->getValue();
		int v2 = c2->getValue();

		if(c1 > c2) return true;
		else if(v1 == v2){
			if(c1->getPrice() < c2->getPrice()) return true;
		}
		return false;
	}
};
