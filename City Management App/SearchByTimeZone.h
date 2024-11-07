#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** SearchByTimeZone class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class SearchByTimeZone : public Visitor {
public:
	/** Overloaded constructor.
	* @param searchTimeZone Time zone to search for
	*/
	SearchByTimeZone(string searchTimeZone);
	/** Checks the specified city, adds it as a match if its time zone matches the searchTimeZone.
	* @param city City to check
	*/
	void visit(City& city);
	/** Returns the list of all matches.
	* @return List of matches
	*/
	vector<City> getMatchList();
private:
	/** Time zone to search by */
	string searchTimeZone;
	/** List of matches */
	vector<City> matchList;
};

SearchByTimeZone::SearchByTimeZone(string searchTimeZone) : Visitor() {
	this->searchTimeZone = searchTimeZone;
}

void SearchByTimeZone::visit(City& city) {
	if (city.getTimeZone().compare(searchTimeZone) == 0)
		matchList.push_back(city);
}

vector<City> SearchByTimeZone::getMatchList() {
	return matchList;
}