#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMinimumLandArea class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMinimumLandArea : public Visitor {
public:
	/** Default constructor */
	FindMinimumLandArea();
	/** Checks the specified city, replaces it as the minAreaCity if its land area is less than the current minAreaCity.
	* @param city City to check
	*/
	void visit(City city);
	/** Returns the City with the minimum land area.
	* @return City with minimum land area
	*/
	City getMinAreaCity();
private:
	/** Current minimum land area City */
	City minAreaCity;
};

inline FindMinimumLandArea::FindMinimumLandArea() : Visitor() {
	minAreaCity.setLandArea(-1);
}

inline void FindMinimumLandArea::visit(City city) {
	if (minAreaCity.getLandArea() == -1) //set to first city regardless of land area
		minAreaCity = city;
	else if (city.getLandArea() < minAreaCity.getLandArea())
		minAreaCity = city;
}

inline City FindMinimumLandArea::getMinAreaCity() {
	return minAreaCity;
}