#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMinimumPopulation class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMinimumPopulation : public Visitor {
public:
	/** Default constructor */
	FindMinimumPopulation();
	/** Checks the specified city, replaces it as the minPopCity if its population is less than the current minPopCity.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the City with the minimum population.
	* @return City with minimum population
	*/
	City getMinPopCity();
private:
	/** Current minimum population City */
	City minPopCity;
};

FindMinimumPopulation::FindMinimumPopulation() : Visitor() {
	minPopCity.setPopulation(-1);
}

void FindMinimumPopulation::visit(City& city) {
	if (minPopCity.getPopulation() == -1) //set to first city regardless of population
		minPopCity = city;
	else if (city.getPopulation() < minPopCity.getLandArea())
		minPopCity = city;
}

City FindMinimumPopulation::getMinPopCity() {
	return minPopCity;
}