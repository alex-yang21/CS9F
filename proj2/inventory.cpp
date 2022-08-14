#include "inventory.h"
#include <iostream>
using namespace std;

// constructor
Inventory::Inventory() {
    vector<item> items(5);
}

void Inventory::Update(string itemName, int amount) {
    int numItems = items.size();
    bool found = false;
    for (int i=0; i < numItems; i++) {
        struct item currItem = items[i];
        if (currItem.itemName == itemName) {
            currItem.amount += amount;
            found = true;
        }
    }

    if (!found) {
        struct item newItem;
        newItem.itemName = itemName;
        newItem.amount = amount;
        items.push_back(newItem);
    }
}

void Inventory::ListByName() {
    // sort the inventory by name
    sort(items.begin(), items.end(), 
        [](item a, item b) {
            return a.itemName < b.itemName;
        }
    );

    PrintItems();
}

void Inventory::ListByQuantity() {
    // sort the inventory by quantity
    sort(items.begin(), items.end(), 
        [](item a, item b) {
            return a.amount < b.amount;
        }
    );

    PrintItems();
}

void Inventory::PrintItems() {
    for (item i:items) {
        cout << "Item name: " << i.itemName << " Amount: " << i.amount << endl;
    }
}