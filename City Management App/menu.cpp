#include <string>
#include <iomanip>
#include "menu.h"
#include "utilities.h"
#include "SearchByFipsCode.h"
#include "SearchByStateID.h"
#include "SearchByMinimumLandArea.h"
#include "ListAllCities.h"
#include "FindMaximumLandArea.h"
#include "FindMinimumLandArea.h"
#include "FindMaximumPopulation.h"
#include "FindMinimumPopulation.h"
#include "FindMaximumPopulationDensity.h"
#include "FindMinimumPopulationDensity.h"
#include "EditPopulation.h"
#include "EditLandArea.h"
#include "SearchByTimeZone.h"

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
			printResults(matchList);
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
			listCitiesByTimeZone(cityTree);
			break;
		case 4:
			listAllCitiesPostOrder(cityTree);
			break;
		default:
			break;
		};
		if (!backFlag)
			util::pressEnter();
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
			findMinimumLandArea(cityTree, resultCity);
			break;
		case 3:
			findMaximumPopulation(cityTree, resultCity);
			break;
		case 4:
			findMinimumPopulation(cityTree, resultCity);
			break;
		case 5:
			findMaximumPopulationDensity(cityTree, resultCity);
			break;
		case 6:
			findMinimumPopulationDensity(cityTree, resultCity);
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
		cout << "1. Edit population" << endl;
		cout << "2. Edit land area" << endl;
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
			editPopulation(cityTree);
			break;
		case 2:
			editLandArea(cityTree);
			break;
		default:
			break;
		};
		if (!backFlag)
			util::pressEnter();
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

void printResults(vector<City> & resultList) {
	cout << endl;
	util::printMenuLine('*', 18);
	cout << "* SEARCH RESULTS *" << endl;
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

void listCitiesByTimeZone(BinarySearchTree<City>& cityTree) {
	util::printMenuLine('*', 14);
	cout << "* TIME ZONES *" << endl;
	util::printMenuLine('*', 14);
	cout << "[E]ST | [C]ST | [M]ST | [P]ST" << endl;
	util::printMenuLine();
	cout << "Enter a time zone: " << flush;

	char input;
	cin >> input;
	string timeZone = "";
	timeZone += toupper(input);
	timeZone += "ST";
	cout << timeZone << endl;

	SearchByTimeZone visitor(timeZone);
	cityTree.inOrderTraverseVisitor(visitor);
	vector<City> matches = visitor.getMatchList();

	//print results
	int totalWidth = 41;
	int cityNameWidth = 16;
	int stateIDWidth = 8;
	int fipsCodeWidth = 9;
	cout << endl;
	util::printMenuLine(totalWidth);
	cout << setfill(' ') << left; //reset fill character
	cout << setw(cityNameWidth) << "City Name" << " | ";
	cout << setw(stateIDWidth) << "State ID" << " | ";
	cout << setw(fipsCodeWidth) << "Fips Code" << " |" << endl;
	util::printMenuLine(totalWidth);
	cout << setfill(' ') << left;
	for (City c : matches) {
		cout << setw(cityNameWidth) << c.getCityName() << " | ";
		cout << setw(stateIDWidth) << c.getStateID() << " | ";
		cout << setw(fipsCodeWidth) << c.getCountyFipsCode() << " |" << endl;
	}
	cout << endl;
}

void listAllCitiesPostOrder(BinarySearchTree<City>& cityTree) {
	cout << endl;
	City::printHeaders();
	cityTree.postOrderTraverse();
	cout << endl;
}

void findMaximumLandArea(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMaximumLandArea visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMaxAreaCity();
}

void findMinimumLandArea(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMinimumLandArea visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMinAreaCity();
}

void findMaximumPopulation(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMaximumPopulation visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMaxPopCity();
}

void findMinimumPopulation(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMinimumPopulation visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMinPopCity();
}

void findMaximumPopulationDensity(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMaximumPopulationDensity visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMaxPopDenCity();
}

void findMinimumPopulationDensity(BinarySearchTree<City>& cityTree, City& resultCity) {
	FindMinimumPopulationDensity visitor;
	cityTree.inOrderTraverseVisitor(visitor);
	resultCity = visitor.getMinPopDenCity();
}

void printCity(City& city) {
	util::printMenuLine();
	cout << city.getCityName() << ", " << city.getStateID() << endl;
	cout << "Population: " << util::intWithCommas(city.getPopulation()) << endl;
	cout << "Land Area: " << city.getLandArea() << " sq. mi." << endl;
	util::printMenuLine();
	util::pressEnter();
}

void editPopulation(BinarySearchTree<City>& cityTree) {
	string cityName = util::getStringLine("Enter a City name: ");
	int popVal = util::getInteger("Enter a value to change the population by: ");

	util::printMenuLine();
	EditPopulation visitor(cityName, popVal);
	cityTree.inOrderTraverseVisitor(visitor);
	if (!visitor.getSuccess())
		cout << "\"" << cityName << "\" not found. Please try again." << endl;
}

void editLandArea(BinarySearchTree<City>& cityTree) {
	string cityName = util::getStringLine("Enter a City name: ");
	double areaVal = util::getDouble("Enter a value to change the land area by: ");

	util::printMenuLine();
	EditLandArea visitor(cityName, areaVal);
	cityTree.inOrderTraverseVisitor(visitor);
	if (!visitor.getSuccess())
		cout << "\"" << cityName << "\" not found. Please try again." << endl;
}