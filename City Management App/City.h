#pragma once
#include <iostream>
using namespace std;

/** City class declaration
* @author Madeleine Woolley
*/
class City {
private:
	/** City name */
	string cityName;
	/** State initials */
	string stateID;
	/** State name */
	string stateName;
	/** County FIPS code */
	string countyFipsCode;
	/** County name */
	string countyName;
	/** Population */
	int population; //INT_MAX = ~2B
	/** Land area */
	double landArea;
	/** Time zone */
	string timeZone;
	/** Column widths for City output */
	static const int colW[8];
	/** Total width of all columns */
	static const int totalWidth;
public:
	/** Default constructor */
	City();
	/** Overloaded constructor. Parses a line of city attributes.
	* @param line String to be parsed
	*/
	City(string line);

	/** City name accessor method */
	string getCityName() const;
	/** State initials accessor method */
	string getStateID() const;
	/** State name accessor method */
	string getStateName() const;
	/** County FIPS code accessor method */
	string getCountyFipsCode() const;
	/** County name accessor method */
	string getCountyName() const;
	/** Population accessor method */
	int getPopulation() const;
	/** Land area accessor method */
	double getLandArea() const;
	/** Time zone accessor method */
	string getTimeZone() const;

	/** City name mutator method */
	void setCityName(string cityName);
	/** State initials mutator method */
	void setStateID(string stateID);
	/** State name mutator method */
	void setStateName(string stateName);
	/** County FIPS code mutator method */
	void setCountyFipsCode(string countyFipsCode);
	/** City mutator method */
	void setCountyName(string countyName);
	/** City mutator method */
	void setPopulation(int population);
	/** City mutator method */
	void setLandArea(double landArea);
	/** City mutator method */
	void setTimeZone(string timeZone);

	/** Compares the values of two City objects.
	* @param c Object to compare with this one
	* @return True if cities are equal, false otherwise
	*/
	bool operator==(const City& c) const;
	/** Compares the values of two City objects.
	* @param c Object to compare with this one
	* @return True if cities are not equal, false otherwise
	*/
	bool operator!=(const City& c) const;
	/** Compares the populations of two City objects.
	* @param c Object to compare with this one
	* @return True if the first City's population is less than the second City's population, false otherwise
	*/
	bool operator<(const City& c) const;
	/** Compares the populations of two City objects.
	* @param c Object to compare with this one
	* @return True if the first City's population is greater than the second City's population, false otherwise
	*/
	bool operator>(const City& c) const;
	/** Increases/decreases the population of this City by the specified value.
	* @param addPop Value to increase the City's population by
	*/
	void operator+=(int addPop);
	/** Increases/decreases the land area of this City by the specified value. */
	void operator+=(double addArea);
	/** Writes the display information for the specified City to the specified output stream.
	* @param out Output stream to write City data display to
	* @param c City object to be displayed
	* @return Output stream
	*/
	friend ostream& operator<<(ostream& out, const City& c);
	/** Prompts the user to enter information about a City to be saved in the specified City object.
	* @param in Input stream to take City data input from
	* @param c City object to be updated
	* @return Input stream
	*/
	friend istream& operator>>(istream& in, City& c);
	
	/** Prints table headers for City output */
	static void printHeaders();
};