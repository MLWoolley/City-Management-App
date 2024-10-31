#include "menu.h"
#include "utilities.h"
#include "SearchByFipsCode.h"

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
			//search by state
			//when a state is found in the structure, the program will list the name of all cities in that state, their fips codes and their county (may need to handle multiple matches)
			break;
		case 3:
			//search by minimum land area
			//the function will request a minimum land area from the user and display all qualifying cities (can just print all info)
			break;
		default:
			break;
		};

		if (!backFlag)
			printMatches(matchList);
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
			//list all cities
			//traverses the list (inorder) and prints the City at each Node.
			break;
		case 2:
			//list all cities by pop density
			//same as option 1; lists only city name, population and land area
			break;
		case 3:
			//list all cities by time zone
			//display a list of all valid time zones, allow for user entry - display the city name, state and zip code
			break;
		case 4:
			//list tree in post order traversal order, print each Node's City
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

		City myCity; //stores selected city for display

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			//get max land area
			//Find the city with the largest land area
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
			//display the city name, state ID, land area and population
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
	
	string testCode = "39153";
	SearchByFipsCode sbfc(testCode);
	cityTree.inOrderTraverse(sbfc);
	matchList = sbfc.getMatchList();
}



void printMatches(vector<City> & matchList) {
	cout << endl;
	util::printMenuLine('*', 18);
	cout << "* SEARCH RESULTS *" << endl;
	util::printMenuLine('*', 18);
	City::printHeaders();
	for (City match : matchList) {
		cout << match;
	}
	cout << endl;
	util::printMenuLine('=', 20);
	cout << "No. of matches: " << matchList.size() << endl;
	util::printMenuLine('=', 20);
	util::pressEnter();
}