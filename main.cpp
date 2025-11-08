#include <iostream>
#include <string>
#include <map>
#include <list>
#include <array>
#include <fstream>    
#include <cstdlib>    
#include <ctime>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std; // copied from the pseudo


using InventoryList = std::array<std::list<std::string>, 3>;
using StoreNetwork = std::map<std::string, InventoryList>; // copied from pseudo
void loadInitialData(StoreNetwork& stores);
void printCurrentInventory(const StoreNetwork& stores);
void simulateDay(StoreNetwork& stores);
void simulateComplexDay(StoreNetwork& stores);

string getRandomStore(const StoreNetwork& stores) {// function to get a random shop
    if (stores.empty()) return "";
    
    vector<string> storeNames;
    for (const auto& pair : stores) {
        storeNames.push_back(pair.first);
    }
    return storeNames[rand() % storeNames.size()];
}

int main() {
    srand(time(0));
    StoreNetwork simulationStores;
    loadInitialData(simulationStores);//creating and calling the data structure
    printCurrentInventory(simulationStores);
    simulateDay(simulationStores);
    printCurrentInventory(simulationStores);// checking if the sold item is gone
    simulateComplexDay(simulationStores);
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
    for (const auto& pair : stores) {
        cout << "Store: " << pair.first << endl;// putting the code inside the loop to print all the stores


        const array<string, 3> categories = {"Juice", "Snacks", "Supply"};
        
        const InventoryList& inventory = pair.second;
        for (int i = 0; i < inventory.size(); ++i) {
            cout << "  " << left << categories[i] << ": ";
            const list<string>& items = inventory[i];

            map<string, int> itemCounts;
            for (const string& item : items) {
                itemCounts[item]++; // making output cleaner
            }

            string output;
            for (const auto& countPair : itemCounts) {
                output += countPair.first + "[" + to_string(countPair.second) + "], ";
            }
            cout << output.substr(0, output.length() - 2) << endl;
        }
    }
            
        

}

void simulateDay(StoreNetwork& stores) {
    if (stores.empty()) return;

    //getting a random store
    string store = getRandomStore(stores);
    
    //getting a random category
    int category = rand() % 3;


    for (int event = 0; event < 5; ++event) { 
        if (!stores[store][category].empty()) {// checking if that one is empty
            list<string>& itemsList = stores[store][category];
            int listSize = itemsList.size();
            int randIndex = rand() % listSize;
            auto it = itemsList.begin();

            advance(it, randIndex);

            string itemSold = *it;
            itemsList.erase(it);
            
            cout << itemSold << " sold from " << store << (array<string,3>{"Juice","Snacks","Supply"})[category]  << endl;
            
        
        }
    }
}

void simulateComplexDay(StoreNetwork& stores) {
    if (stores.empty()) return;

    //getting a random store
    string store = getRandomStore(stores);
    
    //getting a random category
    int category = rand() % 3;
    const array<string, 3> categories = {"Juice", "Snacks", "Supply"};
    int eventType = rand() % 2;
    list<string>& itemsList = stores[store][category];

    if (eventType == 0) {// burglary that takes half of a certain item



        map<string, int> itemCounts;
        for (const string& item : itemsList) {
            itemCounts[item]++;
        }

        // pick a random item to steal from the map
        vector<string> availableItems;
        for(const auto& pair : itemCounts) {
            availableItems.push_back(pair.first);
        }

        if (availableItems.empty()) {
            return; // nothing to steal, so exit the function
        }// moved it up front to not let 0 division happen
        string itemToSteal = availableItems[rand() % availableItems.size()];
        
        int currentStock = itemCounts[itemToSteal];
        int itemsToSteal = currentStock / 2;


        auto it = itemsList.begin();
        int itemsStolen = 0;
        while (it != itemsList.end()) {
            if (*it == itemToSteal && itemsStolen < itemsToSteal) {
                it = itemsList.erase(it); 
                itemsStolen++;
            } else {
                ++it; 
            }
        }
        cout << "  BURGLARY! " << itemsStolen << " units of " << itemToSteal << " were stolen!" << endl;
        

    }
    else {// random things expire
        int numToExpire = (rand() % 2) + 1;
        
        for (int i = 0; i < numToExpire && !itemsList.empty(); ++i) {

            int listSize = itemsList.size();
            int randIndex = rand() % listSize;
            auto it = itemsList.begin();
            advance(it, randIndex);
            
            string expiredItem = *it;
            itemsList.erase(it);

            cout << "  EXPIRED: 1 unit of " << expiredItem << " expired." << endl;
        }
    }


}
