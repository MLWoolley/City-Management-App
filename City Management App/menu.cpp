#include <iostream>
#include "menu.h"
#include "utilities.h"

using namespace std;

void mainMenu(BinarySearchTree<City>& cityTree) {
	bool exitFlag = false;

	while (!exitFlag) {
		cout << "MAIN MENU" << endl;
		util::printMenuLine();
		cout << "1. Search" << endl; //launch search submenu
		cout << "2. Generate reports" << endl; //launch reports submenu
		cout << "3. Maximums and minimums" << endl; //launch maxMin submenu
		cout << "4. Edit city data" << endl; //launch edit submenu
		cout << "0. Exit" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 4);
		util::printMenuLine();

		//for testing submenus - will use "Visitor patterns" in final version
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

/** Calls the search sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void searchMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		cout << "SEARCH MENU" << endl;
		util::printMenuLine();
		cout << "1. Search by county FIPS code" << endl; //when a fips code is found in the structure, the program will display that the city was found and display all of the information about that city (needs to handle multiple matches - some counties (1 fips code per county) have multiple cities, e.g. NY county (36061) and LA county (06037))
		cout << "2. Search by state" << endl; //when a state is found in the structure, the program will list the name of all cities in that state, their fips codes and their county (may need to handle multiple matches)
		cout << "3. Search by minimum land area" << endl; //the function will request a minimum land area from the user and display all qualifying cities (can just print all info)  
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 3);
		util::printMenuLine();

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			//search by county fips code
			break;
		case 2:
			//search by state
			break;
		case 3:
			//search by minimum land area
			break;
		default:
			break;
		};
	}
}

/** Calls the generate reports sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void reportMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		cout << "GENERATE REPORTS MENU" << endl;
		util::printMenuLine();
		cout << "1. List all cities" << endl; //
		cout << "2. List all cities and their population density" << endl; //
		cout << "3. List all cities by time zone" << endl; //
		cout << "4. List all cities by post order traversal" << endl; //
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
			break;
		case 2:
			//list all cities by pop density
			break;
		case 3:
			//list all cities by time zone
			break;
		case 4:
			//list tree in post order traversal order
			break;
		default:
			break;
		};
	}
}

/** Calls the maximums and minimums sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void maxMinMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
		cout << "MINIMUMS AND MAXIMUMS MENU" << endl;
		util::printMenuLine();
		cout << "1. Maximum land area" << endl; //
		cout << "2. Minimum land area" << endl; //
		cout << "3. Maximum population" << endl; //
		cout << "4. Minimum population" << endl; //
		cout << "5. Maximum population density" << endl; //
		cout << "6. Minimum population density" << endl; //
		cout << "0. Back" << endl;
		util::printMenuLine();

		int choice = util::getInteger("Enter a menu choice: ", 0, 6);
		util::printMenuLine();

		switch (choice) {
		case 0:
			cout << "Returning to main menu..." << endl;
			backFlag = true;
			break;
		case 1:
			//list all cities
			break;
		case 2:
			//list all cities by pop density
			break;
		case 3:
			//list all cities by time zone
			break;
		case 4:
			//list tree in post order traversal order
			break;
		default:
			break;
		};
	}
}

/** Calls the editing sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void editMenu(BinarySearchTree<City>& cityTree) {
	bool backFlag = false;

	while (!backFlag) {
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
			break;
		case 2:
			//edit land area
			break;
		default:
			break;
		};
	}
}