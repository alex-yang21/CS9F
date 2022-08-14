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
    for (int i = 0; i < numItems; i++) {
        if (items[i].itemName.compare(itemName) == 0) {
            items[i].amount = amount;
            found = true;
            cout << "found existing item" << endl;
        }
    }

    if (!found) {
        struct item newItem;
        newItem.itemName = itemName;
        newItem.amount = amount;
        items.push_back(newItem);
    }
}

bool compareNames(item a, item b) {
    return a.itemName < b.itemName;
}

bool compareQuantities(item a, item b) {
    return a.amount < b.amount;
}


void Inventory::ListByName() {
    // sort the inventory by name
    sort(items.begin(), items.end(), compareNames);
    PrintItems();
}

void Inventory::ListByQuantity() {
    // sort the inventory by quantity
    sort(items.begin(), items.end(), compareQuantities);
    PrintItems();
}

void Inventory::PrintItems() {
    for (item i:items) {
        cout << "Item name: " << i.itemName << " Amount: " << i.amount << endl;
    }
}