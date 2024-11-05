#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>
#include "utilities.h"

/** EditPopulation class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class EditPopulation : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchCityName City name to search by
	* @param popVal Value to change population by 
	*/
	EditPopulation(string searchCityName, int popVal);
	/** Checks the current city, if the city is the being searched for then its population is changed by popVal.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the list of all matches.
	* @return List of matches
	*/
	bool getSuccess();
private:
	/** City name to search by */
	string searchCityName;
	/** Value to change population by */
	int popVal;
	/** Success status of population edit */
	bool success;
};

inline EditPopulation::EditPopulation(string searchCityName, int popVal) : Visitor() {
	this->searchCityName = searchCityName;
	this->popVal = popVal;
	success = false;
}

inline void EditPopulation::visit(City& city) {
	if (city.getCityName().compare(searchCityName) == 0) {
		cout << city.getCityName() << endl;
		cout << "Old population: " << util::intWithCommas(city.getPopulation()) << endl;
		city += popVal;
		cout << "New population: " << util::intWithCommas(city.getPopulation()) << endl;
		util::printMenuLine();
		success = true;
	}
}

inline bool EditPopulation::getSuccess() {
	return success;
}