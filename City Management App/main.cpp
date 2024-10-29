#include <iostream>
#include "BinarySearchTree.h"
#include "City.h"
#include "menu.h"

using namespace std;

/** Program description
* @author Madeleine Woolley
*/

//prototype methods


int main()
{
    BinarySearchTree<City> cityTree;
    //write csv file data to cityTree by passing lines to City constructor
    mainMenu(cityTree);
}
