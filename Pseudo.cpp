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
//loadInitialData wire frame

void loadInitialData(StoreNetwork& stores) {
    // read the file
    // cout if file empty error
    // cout if file not empty and read successfully
}

// Define function: printCurrentInventory
// Parameters: constant reference to StoreNetwork map
// printCurrentInventory wire frame
void printCurrentInventory(const StoreNetwork& stores) {
    // printing code
    // display neatly the ui
    // if the store is not empty print the first one
}

// Define function: simulateDay
// Parameters: reference to StoreNetwork map
// simulateDay wireframe
void simulateDay(StoreNetwork& stores) {
    // there will be a loop for this to have 5 normal events a day
    // select a random store
    // select a random item
    // select a random normal event
    // update the inventory
}

// Define function: simulateComplexDay
// Parameters: reference to StoreNetwork map
// simulateComplexDay wireframe
void simulateComplexDay(StoreNetwork& stores) {
    // happens randomly may not happen or happen 10% chance, but will be called every time
    // select a random store
    // select a random item
    // select a random complex event(Theft, disaster, shortage overflow)
    // update the inventory
}

// Define main function
// Initialize random seed 