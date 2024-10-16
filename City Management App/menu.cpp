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
	//for testing submenus - will use "Visitor patterns" in final version
}

/***/
void searchMenu() {

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