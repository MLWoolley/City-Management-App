#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

/** ListAllCities class, implements Visitor Interface, uses City Class.
* @author Madeleine Woolley
*/

using namespace std;

class ListAllCities : public Visitor {
public:
	/** Default constructor	*/
	ListAllCities();
	/** Checks the specified city, adds it as a match if its fips code matches the searchFipsCode.
	* @param city City to add
	*/
	void visit(City city);
	/** Returns the list of all Cities.
	* @return List of Cities
	*/
	vector<City> getCityList();
private:
	/** List of Cities */
	vector<City> cityList;
};

inline ListAllCities::ListAllCities() : Visitor() {}

inline void ListAllCities::visit(City city) {
	cityList.push_back(city);
}

inline vector<City> ListAllCities::getCityList() {
	return cityList;
}