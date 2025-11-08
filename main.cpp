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
void printCurrentInventory(const StoreNetwork& stores);

int main() {
    StoreNetwork simulationStores;
    loadInitialData(simulationStores);//creating and calling the data structure
    printCurrentInventory(simulationStores);
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
        if (getline(ss, storeName, ',') && getline(ss, category, ',') && getline(ss, itemName, ',')) 
        {
            int categoryIndex = -1;
            if (category == "Juice") {
                categoryIndex = 0;
            }   
            else if (category == "Snacks") {
                categoryIndex = 1;
            } 
            else if (category == "Supply") {
                categoryIndex = 2;
            }

            if (categoryIndex != -1) {
                stores[storeName][categoryIndex].push_back(itemName);
                itemsLoaded++;
            }
        }
    }
    inFile.close();
    if (itemsLoaded > 0) {
        cout << itemsLoaded << " items read successfully" << endl;
    }

    // read the file
    // cout if file empty error
    // cout if file not empty and read successfully
}

void printCurrentInventory(const StoreNetwork& stores){
    if (stores.empty()) {
        cout << "Inventory is currently empty." << endl;// checking if the store is empty
        return;
    }

    const array<string, 3> categories = {"Juice", "Snacks", "Supply"};
    for (const auto& pair : stores){
        const InventoryList& inventory = pair.second;
        for (int i = 0; i < inventory.size(); ++i) {
            cout << "  " << left << categories[i] << ": ";
            const list<string>& items = inventory[i];
            string output;
            for (const string& item : items) {
                output += item + ", ";
                
            }
            cout << output.substr(0, output.length() - 2) << endl;
        }
    }
}
