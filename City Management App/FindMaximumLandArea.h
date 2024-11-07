#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMaximumLandArea class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMaximumLandArea : public Visitor {
public:
	/** Default constructor */
	FindMaximumLandArea();
	/** Checks the specified city, replaces it as the maxAreaCity if its land area is greater than the current maxAreaCity.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the City with the maximum land area.
	* @return City with maximum land area
	*/
	City getMaxAreaCity();
private:
	/** Current maximum land area City */
	City maxAreaCity;
};

FindMaximumLandArea::FindMaximumLandArea() : Visitor() {
	maxAreaCity.setLandArea(-1);
}

void FindMaximumLandArea::visit(City& city) {
	if (city.getLandArea() > maxAreaCity.getLandArea())
		maxAreaCity = city;
}

City FindMaximumLandArea::getMaxAreaCity() {
	return maxAreaCity;
}