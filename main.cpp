#include <iostream>
#include <string>
#include <map>
#include <list>
#include <array>
#include <fstream>    
#include <cstdlib>    
#include <ctime>
using namespace std; // copied from the pseudo


using InventoryList = std::array<std::list<std::string>, 3>;
using StoreNetwork = std::map<std::string, InventoryList>; // copied from pseudo
void loadInitialData(StoreNetwork& stores);

int main() {

}

void loadInitialData(StoreNetwork& stores) {
    ifstream inFile("initial_stock.txt");
    
    // read the file
    // cout if file empty error
    // cout if file not empty and read successfully
}
