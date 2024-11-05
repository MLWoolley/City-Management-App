#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** FindMaximumPopulation class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class FindMaximumPopulation : public Visitor {
public:
	/** Default constructor */
	FindMaximumPopulation();
	/** Checks the specified city, replaces it as the maxPopCity if its population is greater than the current maxPopCity.
	* @param city City to check
	*/
	void visit(City city);
	/** Returns the City with the maximum population.
	* @return City with maximum population
	*/
	City getMaxPopCity();
private:
	/** Current maximum population City */
	City maxPopCity;
};

inline FindMaximumPopulation::FindMaximumPopulation() : Visitor() {
	maxPopCity.setPopulation(-1);
}

inline void FindMaximumPopulation::visit(City city) {
	if (city.getPopulation() > maxPopCity.getPopulation())
		maxPopCity = city;
}

inline City FindMaximumPopulation::getMaxPopCity() {
	return maxPopCity;
}