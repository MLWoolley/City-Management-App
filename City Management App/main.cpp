#include "BinarySearchTree.h"
#include "City.h"
#include "menu.h"
#include "utilities.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/** City Management App allows the user to access, search and alter city data from the "USCities-100-1.csv" file. City information is stored as City objects in a Binary Search Tree.
* @author Madeleine Woolley
*/

//prototype methods
void buildTree(BinarySearchTree<City>& cityTree, string& filename);

int main() {
    BinarySearchTree<City> cityTree;
    string filename = "USCities-100-1.csv";
    buildTree(cityTree, filename);
    mainMenu(cityTree);
}

void buildTree(BinarySearchTree<City>& cityTree, string& filename) {
    ifstream infile(filename);
    util::checkFileOpen(infile, filename);

    string line = "";
    getline(infile, line); //skip headers
    while (getline(infile, line)) {
        City newCity(line);
        cityTree.insert(newCity);
    }
    infile.close();
}