#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** SearchByFipsCode class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class SearchByFipsCode : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchFipsCode Fips code to search for
	*/
	SearchByFipsCode(string searchFipsCode);
	/** Checks the specified city, adds it as a match if its fips code matches the searchFipsCode.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the list of all matches.
	* @return List of matches
	*/
	vector<City> getMatchList();
private:
	/** Fips code to search by */
	string searchFipsCode;
	/** List of matches */
	vector<City> matchList;
};

SearchByFipsCode::SearchByFipsCode(string searchFipsCode) : Visitor() {
	this->searchFipsCode = searchFipsCode;
}

void SearchByFipsCode::visit(City& city) {
	if (city.getCountyFipsCode().compare(searchFipsCode) == 0)
		matchList.push_back(city);
}

vector<City> SearchByFipsCode::getMatchList() {
	return matchList;
}