#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMinimumPopulationDensity class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMinimumPopulationDensity : public Visitor {
public:
	/** Default constructor */
	FindMinimumPopulationDensity();
	/** Checks the specified city, replaces it as the minPopDenCity if its population is greater than the current minPopDenCity.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the City with the minimum population density.
	* @return City with minimum population density
	*/
	City getMinPopDenCity();
private:
	/** Current minimum population density City */
	City minPopDenCity;
	/** Calculates the specified City's population density, i.e. population / land area.
	* @param c City to use in calculation
	* @return Population density of City
	*/
	double calcPopulationDensity(const City& c) const;
};

inline FindMinimumPopulationDensity::FindMinimumPopulationDensity() : Visitor() {
	minPopDenCity.setPopulation(-1);
	minPopDenCity.setLandArea(1); //so pop/area = -1
}

inline void FindMinimumPopulationDensity::visit(City& city) {
	if (calcPopulationDensity(minPopDenCity) == -1) //set to first city regardless of population
		minPopDenCity = city;
	if (calcPopulationDensity(city) < calcPopulationDensity(minPopDenCity))
		minPopDenCity = city;
}

inline City FindMinimumPopulationDensity::getMinPopDenCity() {
	return minPopDenCity;
}

inline double FindMinimumPopulationDensity::calcPopulationDensity(const City& c) const {
	return c.getPopulation() / c.getLandArea();
}