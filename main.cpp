#include <iostream>
#include <string>
#include <map>
#include <list>
#include <array>
#include <fstream>    
#include <cstdlib>    
#include <ctime>
#include <sstream>
using namespace std; // copied from the pseudo


using InventoryList = std::array<std::list<std::string>, 3>;
using StoreNetwork = std::map<std::string, InventoryList>; // copied from pseudo
void loadInitialData(StoreNetwork& stores);

int main() {
    StoreNetwork simulationStores;
    loadInitialData(simulationStores);//creating and calling the data structure
    if (simulationStores.count("StoreA")){
        cout << "loaded nicely" << endl;
        const auto& juiceList = simulationStores["StoreA"][0];
        if (juiceList.empty()) {
            cout << "  (List is empty)" << endl;
        } 
        else {
            for (const string& item : juiceList) {
                cout << item << endl;
            }
        }
    }
    return 0;
}

void loadInitialData(StoreNetwork& stores) {
    ifstream inFile("initial_stock.txt");
    string line;
    string storeName, category, itemName;
    int itemsLoaded = 0;
    //item will be in the format of store name, category, item name
    while (getline(inFile, line)) {
        stringstream ss(line);

    }
    // read the file
    // cout if file empty error
    // cout if file not empty and read successfully
}
