#include "menu.h"
#include "utilities.h"
#include "SearchByFipsCode.h"
#include <string>
#include "SearchByStateID.h"
#include "SearchByMinimumLandArea.h"
#include "ListAllCities.h"
#include <iomanip>
#include "FindMaximumLandArea.h"

using namespace std;

void mainMenu(BinarySearchTree<City>& cityTree) {
	bool exitFlag = false;

	while (!exitFlag) {
		cout << "MAIN MENU" << endl;
		util::printMenuLine();
		cout << "1. Search" << endl;
		cout << "2. Generate reports" << endl;
		cout << "3. Maximums and minimums" << endl;
		cout << "4. Edit city data" << endl;
		cout << "0. Exit" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 4);
		util::printMenuLine();

		switch (choice) {
		case 0:
			cout << "Program terminating..." << endl;
			exitFlag = true;
			break;
		case 1:
			searchMenu(cityTree);
			break;
		case 2:
			reportMenu(cityTree);
			break;
		case 3:
			maxMinMenu(cityTree);
			break;
		case 4:
			editMenu(cityTree);
			break;
		default:
			break; //invalid input already checked
		};
		util::printMenuLine();
		util::pressEnter();
	}
}

void searchMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;
	vector<City> matchList;

	while (!backFlag) {
		util::printMenuLine();
		cout << "SEARCH MENU" << endl;
		util::printMenuLine();
		cout << "1. Search by county FIPS code" << endl;
		cout << "2. Search by state" << endl;
		cout << "3. Search by minimum land area" << endl;  
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 3);
		util::printMenuLine();

		//Clear list of matches
		matchList.clear();

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			searchByFipsCode(cityTree, matchList);
			break;
		case 2:
			searchByStateID(cityTree, matchList);
			break;
		case 3:
			searchByMinimumLandArea(cityTree, matchList);
			break;
		default:
			break;
		};

		if (!backFlag)
			printResults(matchList, "SEARCH RESULTS");
	}
}

void reportMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		util::printMenuLine();
		cout << "GENERATE REPORTS MENU" << endl;
		util::printMenuLine();
		cout << "1. List all cities" << endl;
		cout << "2. List all cities and their population density" << endl;
		cout << "3. List all cities by time zone" << endl;
		cout << "4. List all cities by post order traversal" << endl;
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 4);
		util::printMenuLine();

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			listAllCitiesInOrder(cityTree);
			break;
		case 2:
			listAllCitiesPopDensity(cityTree);
			break;
		case 3:
			//list all cities by time zone
			//display a list of all valid time zones, allow for user entry - display the city name, state and zip code
			break;
		case 4:
			listAllCitiesPostOrder(cityTree);
			break;
		default:
			break;
		};
	}
}

void maxMinMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		util::printMenuLine();
		cout << "MINIMUMS AND MAXIMUMS MENU" << endl;
		util::printMenuLine();
		cout << "1. Maximum land area" << endl;
		cout << "2. Minimum land area" << endl;
		cout << "3. Maximum population" << endl;
		cout << "4. Minimum population" << endl;
		cout << "5. Maximum population density" << endl;
		cout << "6. Minimum population density" << endl;
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 6);
		util::printMenuLine();

		City resultCity;

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			findMaximumLandArea(cityTree, resultCity);
			break;
		case 2:
			//get min land area
			//Find the city with the smallest land area
			break;
		case 3:
			//get max population
			//Find the city with the largest population
			break;
		case 4:
			//get min population
			//Find the city with the smallest population
			break;
		case 5:
			//get max population density
			//Find the city with the largest population density
			break;
		case 6:
			//get min population density
			//Find the city with the smallest population density
			break;
		default:
			break;
		};
		if (!backFlag) {
			printCity(resultCity);
		}
	}
}

void editMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		util::printMenuLine();
		cout << "EDIT MENU" << endl;
		util::printMenuLine();
		cout << "1. Edit population" << endl; //
		cout << "2. Edit land area" << endl; //
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 2);
		util::printMenuLine();

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			//edit population
			//let the user enter a city name and a value to change the population by, then change that City's population
			break;
		case 2:
			//edit land area
			//let the user enter a city name and a value to change the land area by, then change that City's land area
			//should city have a += operator that takes a double? It would allow me to use the += operator to alter both attributes concurrently...
			break;
		default:
			break;
		};
	}
}

void searchByFipsCode(BinarySearchTree<City>& cityTree, vector<City>& matchList) {
	string searchFipsCode;
	int fipsCode = util::getInteger("Enter the City's County FIPS Code: ", 1001, 56045);
	//lowest FIPS code is 01001, highest is 56045
	searchFipsCode = (fipsCode < 10000) ? "0" : ""; //pad 0 as necessary
	searchFipsCode += to_string(fipsCode);

	SearchByFipsCode visitor(searchFipsCode);
	cityTree.inOrderTraverseVisitor(visitor);
	matchList = visitor.getMatchList();
}

void searchByStateID(BinarySearchTree<City>& cityTree, vector<City>& matchList) {
	string searchStateID = util::getStringLine("Enter the City's State Initials: ");
	searchStateID = util::toUpper(searchStateID.substr(0, 2));

	SearchByStateID visitor(searchStateID);
	cityTree.inOrderTraverseVisitor(visitor);
	matchList = visitor.getMatchList();
}

void searchByMinimumLandArea(BinarySearchTree<City>& cityTree, vector<City>& matchList) {
	double searchMinimumArea = util::getDouble("Enter a minimum land area for Cities: ", 0, INT_MAX); //just eliminate negative values

	SearchByMinimumLandArea visitor(searchMinimumArea);
	cityTree.inOrderTraverseVisitor(visitor);
	matchList = visitor.getMatchList();
}

void printResults(vector<City> & resultList, string resultTitle) {
	cout << endl;
	util::printMenuLine('*', 18);
	cout << "* " << resultTitle << " *" << endl;
	util::printMenuLine('*', 18);

	int listSize = resultList.size();
	if (listSize > 0) { //print table if at least 1 match
		cout << endl;
		City::printHeaders();
		for (City result : resultList) {
			cout << result;
		}
	}

	cout << endl;
	util::printMenuLine('=', 20);
	string resultString = (listSize == 1) ? " result." : " results.";
	cout << listSize << resultString << endl;
	util::printMenuLine('=', 20);
	util::pressEnter();
}

void listAllCitiesInOrder(BinarySearchTree<City>& cityTree) {
	cout << endl;
	City::printHeaders();
	cityTree.inOrderTraverse();
	cout << endl;
	util::pressEnter();
}

void listAllCitiesPopDensity(BinarySearchTree<City>& cityTree) {
	ListAllCities visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	vector<City> cityList = visitor.getCityList();

	//print results
	int totalWidth = 40;
	int cityNameWidth = 16;
	int populationWidth = 10;
	int landAreaWidth = 6;
	cout << endl;
	util::printMenuLine(totalWidth);
	cout << setfill(' ') << left; //reset fill character
	cout << setw(cityNameWidth) << "City Name" << " | ";
	cout << setw(populationWidth) << "Population" << " | ";
	cout << setw(landAreaWidth) << "Sq mi" << " |" << endl;
	util::printMenuLine(totalWidth);
	cout << setfill(' ') << left;
	for (City c : cityList) {
		cout << setw(cityNameWidth) << c.getCityName() << " | ";
		cout << setw(populationWidth) << right << util::intWithCommas(c.getPopulation()) << " | ";
		cout << setw(landAreaWidth) << left << c.getLandArea() << " |" << endl;
	}
	cout << endl;
}

void listAllCitiesPostOrder(BinarySearchTree<City>& cityTree) {
	cout << endl;
	City::printHeaders();
	cityTree.postOrderTraverse();
	cout << endl;
	util::pressEnter();
}

void findMaximumLandArea(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMaximumLandArea visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMaxAreaCity();
}





void printCity(City& city) {
	util::printMenuLine();
	cout << city.getCityName() << ", " << city.getStateID() << endl;
	cout << "Population: " << util::intWithCommas(city.getPopulation()) << endl;
	cout << "Land Area: " << city.getLandArea() << " sq. mi." << endl;
	util::printMenuLine();
	util::pressEnter();
}

//for editing visitor patterns, must have an attribute bool success that is set to true if the City is successfully found and its value changed, and then a getSuccess method to return whether the operation has been successful. visit method should check if the city name matches the search parameter, and then change that city's population/land area by the specified amount.