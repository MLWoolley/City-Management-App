#include "City.h"
#include <iomanip>
#include <sstream>
#include <string>
#include "utilities.h"

/** City class definition.
* @author Madeleine Woolley
* @see City.h for class declaration
*/

const int City::colW[8] = { 16, 8, 20, 9, 20, 10, 6, 9 };
const int City::totalWidth = colW[0] + colW[1] + colW[2] + colW[3] + colW[4]
+ colW[5] + colW[6] + colW[7] + 7 * 3; //all column widths plus all vertical spacers (numCols-1)

City::City() {
	cityName = "";
	stateID = "";
	stateName = "";
	countyFipsCode = "";
	countyName = "";
	population = 0;
	landArea = 0;
	timeZone = "";
}

City::City(string line) {
	istringstream iss(line);
	string temp = "";
	getline(iss, cityName, ',');
	getline(iss, stateID, ',');
	getline(iss, stateName, ',');
	getline(iss, countyFipsCode, ',');
	getline(iss, countyName, ',');
	getline(iss, temp, ',');
	population = stoi(temp);
	getline(iss, temp, ',');
	landArea = stod(temp);
	getline(iss, timeZone);
}

string City::getCityName() const {
	return cityName;
}
string City::getStateID() const {
	return stateID;
}
string City::getStateName() const {
	return stateName;
}
string City::getCountyFipsCode() const {
	return countyFipsCode;
}
string City::getCountyName() const {
	return countyName;
}
int City::getPopulation() const {
	return population;
}
double City::getLandArea() const {
	return landArea;
}
string City::getTimeZone() const {
	return timeZone;
}

void City::setCityName(string cityName) {
	this->cityName = cityName;
}
void City::setStateID(string stateID) {
	this->stateID = stateID;
}
void City::setStateName(string stateName) {
	this->stateName = stateName;
}
void City::setCountyFipsCode(string countyFipsCode) {
	this->countyFipsCode = countyFipsCode;
}
void City::setCountyName(string countyName) {
	this->countyName = countyName;
}
void City::setPopulation(int population) {
	this->population = population;
}
void City::setLandArea(double landArea) {
	this->landArea = landArea;
}
void City::setTimeZone(string timeZone) {
	this->timeZone = timeZone;
}

bool City::operator==(const City& c) const {
	if (cityName.compare(c.cityName) == 0 &&
		stateID.compare(c.stateID) == 0 &&
		stateName.compare(c.stateName) == 0 &&
		countyFipsCode.compare(c.countyFipsCode) == 0 &&
		countyName.compare(c.countyName) == 0 &&
		population == c.population &&
		landArea == c.landArea &&
		timeZone.compare(c.timeZone) == 0) {
		return true;
	}
	return false;
}
bool City::operator!=(const City& c) const {
	if (cityName.compare(c.cityName) == 0 &&
		stateID.compare(c.stateID) == 0 &&
		stateName.compare(c.stateName) == 0 &&
		countyFipsCode.compare(c.countyFipsCode) == 0 &&
		countyName.compare(c.countyName) == 0 &&
		population == c.population &&
		landArea == c.landArea &&
		timeZone.compare(c.timeZone) == 0) {
		return false;
	}
	return true;
}
bool City::operator<(const City& c) const {
	return population < c.population;
}
bool City::operator>(const City& c) const {
	return population > c.population;
}
void City::operator+=(int addPop) {
	population += addPop;
	if (population < 0) population = 0; //reset to 0 if now negative
}
void City::operator+=(double addArea) {
	landArea += addArea;
	if (landArea < 0) landArea = 0; //reset to 0 if now negative
}
ostream& operator<<(ostream& out, const City& c) {
	out << setfill(' ') << left; //reset fill character
	out << setw(City::colW[0]) << c.cityName << " | ";
	out << setw(City::colW[1]) << c.stateID << " | ";
	out << setw(City::colW[2]) << c.stateName << " | ";
	out << setw(City::colW[3]) << c.countyFipsCode << " | ";
	out << setw(City::colW[4]) << c.countyName << " | ";
	//cout << setw(colW[5]) << c.population << " | "; //testing
	out << setw(City::colW[5]) << right << util::intWithCommas(c.population) << " | ";
	out << setw(City::colW[6]) << left << /*fixed << setprecision(2) */ c.landArea << " | ";
	out << setw(City::colW[7]) << c.timeZone << endl;
	return out;
}
istream& operator>>(istream& in, City& c) {
	//may want some input checking
	//Error checking for time zone? Probably not - time zones could be 4 characters, e.g. AKST, or they could not end ST, etc.
	//Maybe check stateID, but only so much as checking/forcing it to 2 characters and checking they are letters. Definitely use util::toUpper
	c.cityName = util::getStringLine("Enter the City's name: ");
	c.stateID = util::getStringLine("Enter the City's State ID (e.g. AK): ");
	c.stateName = util::getStringLine("Enter the State's name: ");
	c.stateName = util::toUpper(c.stateName.substr(0, 2)); //fix input to 2 uppercase chars
	int fipsCode = util::getInteger("Enter the City's County FIPS Code: ", 1001, 56045);
	//lowest FIPS code is 01001, highest is 56045
	c.countyFipsCode = (fipsCode < 10000) ? "0" : ""; //pad 0 as necessary
	c.countyFipsCode += to_string(fipsCode);
	c.countyName = util::getStringLine("Enter the County's name: ");
	c.population = util::getInteger("Enter the City's population: ", 0, INT_MAX);
	c.landArea = util::getDouble("Enter the City's Land Area (in Sq miles): ", 0, 10000);
	c.timeZone = util::getStringLine("Enter the City's Time Zone (e.g. EST): ");
	return in;
}

void City::printHeaders() {
	util::printMenuLine(totalWidth);

	cout << setfill(' ') << left; //reset fill character
	cout << setw(colW[0]) << "City Name" << " | ";
	cout << setw(colW[1]) << "State ID" << " | ";
	cout << setw(colW[2]) << "State Name" << " | ";
	cout << setw(colW[3]) << "FIPS Code" << " | ";
	cout << setw(colW[4]) << "County Name" << " | ";
	cout << setw(colW[5]) << "Population" << " | ";
	cout << setw(colW[6]) << "Sq mi" << " | ";
	cout << setw(colW[7]) << "Time Zone" << endl;

	util::printMenuLine(totalWidth);
}