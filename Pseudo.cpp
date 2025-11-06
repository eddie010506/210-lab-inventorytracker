//Including necessary headers
//Wire Frame for headers
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <array>
#include <fstream>    
#include <cstdlib>    
#include <ctime>
using namespace std;
// these seems to be needed for now

// defining the complex data structure
using InventoryList = std::array<std::list<std::string>, 3>;
using StoreNetwork = std::map<std::string, InventoryList>; //

// Define function: loadInitialData
// Parameters: reference to StoreNetwork map
// Open external file ("initial_stock.txt")
// If file not open, print error and exit
// Loop through at least 100 lines of the file
// Read store_name, category_type, item_name
// Based on category_type ("Juice", "Snacks", "Supply"):
// Insert item_name into the correct list for the correct store name.
// Close file



