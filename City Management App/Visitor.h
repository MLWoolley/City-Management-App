#pragma once
#include "City.h"

/** Visitor Interface, uses City class.
* @author Madeleine Woolley
*/

class Visitor {
public:
	/** Default constructor */
	Visitor();

	/** Visitor method upon a City object */
	virtual void visit(City& city) = 0;
};

inline Visitor::Visitor() {}