#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** SearchByStateID class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class SearchByStateID : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchState State to search for
	*/
	SearchByStateID(string searchStateID);
	/** Checks the specified city, adds it as a match if its state ID matches the searchStateID.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the list of all matches.
	* @return List of matches
	*/
	vector<City> getMatchList();
private:
	/** State ID to search by */
	string searchStateID;
	/** List of matches */
	vector<City> matchList;
};

SearchByStateID::SearchByStateID(string searchStateID) : Visitor() {
	this->searchStateID = searchStateID;
}

void SearchByStateID::visit(City& city) {
	if (city.getStateID().compare(searchStateID) == 0)
		matchList.push_back(city);
}

vector<City> SearchByStateID::getMatchList() {
	return matchList;
}