#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMaximumPopulationDensity class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMaximumPopulationDensity : public Visitor {
public:
	/** Default constructor */
	FindMaximumPopulationDensity();
	/** Checks the specified city, replaces it as the maxPopDenCity if its population is greater than the current maxPopDenCity.
	* @param city City to check
	*/
	void visit(City city);
	/** Returns the City with the maximum population density.
	* @return City with maximum population density
	*/
	City getMaxPopDenCity();
private:
	/** Current maximum population density City */
	City maxPopDenCity;
	/** Calculates the specified City's population density, i.e. population / land area.
	* @param c City to use in calculation
	* @return Population density of City
	*/
	double calcPopulationDensity(const City& c) const;
};

inline FindMaximumPopulationDensity::FindMaximumPopulationDensity() : Visitor() {
	maxPopDenCity.setPopulation(-1);
	maxPopDenCity.setLandArea(1); //so pop/area = -1
}

inline void FindMaximumPopulationDensity::visit(City city) {
	if (calcPopulationDensity(city) > calcPopulationDensity(maxPopDenCity))
		maxPopDenCity = city;
}

inline City FindMaximumPopulationDensity::getMaxPopDenCity() {
	return maxPopDenCity;
}

inline double FindMaximumPopulationDensity::calcPopulationDensity(const City& c) const {
	return c.getPopulation() / c.getLandArea();
}