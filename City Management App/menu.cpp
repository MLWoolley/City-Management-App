#include <iostream>
#include "menu.h"
#include "utilities.h"

using namespace std;

/***/
void mainMenu() { //note this will have to take a binary tree of city objects as a referenced parameter
	cout << "MAIN MENU" << endl;
	printMenuLine();
	cout << "1. Search" << endl; //launch search submenu
	cout << "2. Generate reports" << endl; //launch reports submenu
	cout << "3. Maximums and minimums" << endl; //launch maxMin submenu
	cout << "4. Edit city data" << endl; //launch edit submenu
	cout << "0. Exit" << endl;
	printMenuLine();

	int choice = getInteger("Enter a menu choice: ", 0, 4);
	printMenuLine();

	//for testing submenus - will use "Visitor patterns" in final version
	switch (choice) {
	case 0:
		cout << "Program terminating..." << endl;
		exit(0);
	case 1:
		searchMenu();
		break;
	case 2:
		reportMenu();
		break;
	case 3:
		maxMinMenu();
		break;
	case 4:
		editMenu();
		break;
	default:
		break; //invalid input already checked
	}
	printMenuLine();
	pressEnter();
}

/***/
void searchMenu() {
	cout << "SEARCH MENU" << endl;
	printMenuLine();
	cout << "1. Search by zip code" << endl; //when a zip code is found in the structure, the program will display that the city was found and display all of the information about that city (needs to handle multiple matches - some counties (1 zip code per county) have multiple cities, e.g. NYC (36061) and LA (06037))
	cout << "2. Search by state" << endl; //when a state is found in the structure, the program will list the name of all cities in that state, their zip codes and their county (may need to handle multiple matches)
	cout << "3. Search by minimum land area" << endl; //the function will request a minimum land area from the user and display all qualifying cities (can just print all info)  
	cout << "0. Back" << endl;
	printMenuLine();

	int choice = getInteger("Enter a menu choice: ", 0, 3);
	printMenuLine();

	cout << "Menu choice: " << choice << endl; //for testing. Will use visitor patterns to implement this in final version
}

/***/
void reportMenu() {

}

/***/
void maxMinMenu() {

}

/***/
void editMenu() {

}