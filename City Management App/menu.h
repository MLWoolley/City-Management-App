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

/** Searches the specified BST for cities that match the user-specified state ID.
* @param cityTree BST of City objects to search
* @param matchList List of matches
*/
void searchByStateID(BinarySearchTree<City>& cityTree, vector<City>& matchList);

/** Searches the specified BST for cities that match the user-specified minimum land area.
* @param cityTree BST of City objects to search
* @param matchList List of matches
*/
void searchByMinimumLandArea(BinarySearchTree<City>& cityTree, vector<City>& matchList);

/** Prints the results stored in resultList.
* @param resultList List of results
* @param resultTitle Title for results
*/
void printResults(vector<City>& resultList, string resultTitle);

/** Prints all Cities in the specified BST using in-order traversal.
* @param cityTree BST of City objects to list
*/
void listAllCitiesInOrder(BinarySearchTree<City>& cityTree);

/** Prints all Cities in the specified BST, displaying only city name, population and land area.
* @param cityTree BST of City objects to list
*/
void listAllCitiesPopDensity(BinarySearchTree<City>& cityTree);

/** Prints all Cities in the specified BST, displaying only city name, population and land area.
* @param cityTree BST of City objects to list
*/
void listAllCitiesPopDensity(BinarySearchTree<City>& cityTree);

/** Prints all Cities in the specified BST using post-order traversal.
* @param cityTree BST of City objects to list
*/
void listAllCitiesPostOrder(BinarySearchTree<City>& cityTree);

/** Finds the City with the maximum land area.
* @param cityTree BST of City objects to search
* @param resultCity City with max land area
*/
void findMaximumLandArea(BinarySearchTree<City>& cityTree, City& resultCity);

/** Finds the City with the minimum land area.
* @param cityTree BST of City objects to search
* @param resultCity City with min land area
*/
void findMinimumLandArea(BinarySearchTree<City>& cityTree, City& resultCity);

/** Finds the City with the maximum population.
* @param cityTree BST of City objects to search
* @param resultCity City with max population
*/
void findMaximumPopulation(BinarySearchTree<City>& cityTree, City& resultCity);

/** Finds the City with the minimum population.
* @param cityTree BST of City objects to search
* @param resultCity City with min population
*/
void findMinimumPopulation(BinarySearchTree<City>& cityTree, City& resultCity);

/** Finds the City with the maximum population density.
* @param cityTree BST of City objects to search
* @param resultCity City with max population density
*/
void findMaximumPopulationDensity(BinarySearchTree<City>& cityTree, City& resultCity);

/** Prints the specified city's name, state, land area and population.
* @param city City to print
*/
void printCity(City& city);