#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>
#include "utilities.h"

/** EditLandArea class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class EditLandArea : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchCityName City name to search by
	* @param areaVal Value to change land area by
	*/
	EditLandArea(string searchCityName, double areaVal);
	/** Checks the current city, if the city is the being searched for then its land area is changed by areaVal.
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
	/** Value to change land area by */
	double areaVal;
	/** Success status of land area edit */
	bool success;
};

EditLandArea::EditLandArea(string searchCityName, double areaVal) : Visitor() {
	this->searchCityName = searchCityName;
	this->areaVal = areaVal;
	success = false;
}

void EditLandArea::visit(City& city) {
	if (city.getCityName().compare(searchCityName) == 0) {
		cout << city.getCityName() << endl;
		cout << "Old land area: " << city.getLandArea() << " sq mi" << endl;
		city += areaVal;
		cout << "New land area: " << city.getLandArea() << " sq mi" << endl;
		util::printMenuLine();
		success = true;
	}
}

bool EditLandArea::getSuccess() {
	return success;
}