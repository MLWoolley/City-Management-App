#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** SearchByMinimumLandArea class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class SearchByMinimumLandArea : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchMinimumLandArea Minimum land area to search by
	*/
	SearchByMinimumLandArea(double searchMinimumLandArea);
	/** Checks the specified city, adds it as a match if its land area is greater than or equal to searchMinimumLandArea.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the list of all matches.
	* @return List of matches
	*/
	vector<City> getMatchList();
private:
	/** Minimum land area to search by */
	double searchMinimumLandArea;
	/** List of matches */
	vector<City> matchList;
};

SearchByMinimumLandArea::SearchByMinimumLandArea(double searchMinimumLandArea) : Visitor() {
	this->searchMinimumLandArea = searchMinimumLandArea;
}

void SearchByMinimumLandArea::visit(City& city) {
	if (city.getLandArea() >= searchMinimumLandArea)
		matchList.push_back(city);
}

vector<City> SearchByMinimumLandArea::getMatchList() {
	return matchList;
}