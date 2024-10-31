#pragma once
#include "BinarySearchTree.h"
#include "City.h"
#include <vector>

/** Calls the main menu recursively until the user exits the program.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void mainMenu(BinarySearchTree<City>& cityTree);

/** Calls the search sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void searchMenu(BinarySearchTree<City>& cityTree);

/** Calls the generate reports sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void reportMenu(BinarySearchTree<City>& cityTree);

/** Calls the maximums and minimums sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void maxMinMenu(BinarySearchTree<City>& cityTree);

/** Calls the editing sub menu and performs the user-specified operation on cityTree.
* @param cityTree Binary Search Tree of City objects to be used for operations
*/
void editMenu(BinarySearchTree<City>& cityTree);

/** Searches the specified BST for cities that match the user-specified county FIPS code.
* @param cityTree BST of City objects to search
* @param matchList List of matches
*/
void searchByFipsCode(BinarySearchTree<City>& cityTree, vector<City>& matchList);

/** Prints the matches for a search in matchList.
* @param matchList List of matches
*/
void printMatches(vector<City>& matchList);