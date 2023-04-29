/* 
 * File:   Admin.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "Admin.h"

using namespace std;

Admin::Admin(const string& adminName) : adminName(adminName) {}

void Admin::addItem(const string& itemName, const string& itemDescription,
                 float itemPrice, int itemQuantity) {
    int newItemID = items.size() + 1;
    Item newItem(newItemID, itemName, itemDescription, itemPrice, itemQuantity);
    items.push_back(newItem);
}
    
void Admin::editItem(int itemID, const string& newItemName, const string& newItemDescription, 
                  float newItemPrice, int newItemQuantity) {
    for (Item& item : items) {
        if (item.getItemID() == itemID) {
            item.setItemName(newItemName);
            item.setItemDescription(newItemDescription);
            item.setItemPrice(newItemPrice);
            item.setItemQuantity(newItemQuantity);
            break;
        }
    }
}

void Admin::removeItem(int itemID) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemID() == itemID) {
            items.erase(items.begin() + 1);
            break;
        }
    }
}

void Admin::displayItems() const {
    for (const Item& item : items) {
        cout << "ID: " << item.getItemID()
             << " Name:" << item.getItemName()
             << " Description" << item.getItemDescription()
             << " Price: $" << item.getItemPrice()
             << " Quantity" << item.getItemQuantity() << endl;
    }
}

vector<Item> Admin::getItems() const {
    return items;
}

void Admin::adminLogin(map<string, Admin>& admins) {
    // Log in as admin
    string adminName;
    cout << "Enter admin name: ";
    cin >> adminName;

    auto adminIter = admins.find(adminName);
    if (adminIter != admins.end()) {
        Admin& admin = adminIter->second;
    } else {
        cout << "Admin not found" << endl;
    }            
}