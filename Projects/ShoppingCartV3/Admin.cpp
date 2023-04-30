/* 
 * File:   Admin.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "Admin.h"

using namespace std;

Admin::Admin(const string& adminName, const string& password, vector<Item>& items)
            : adminName(adminName), password(password), items(items) {}

void Admin::addItem() {
    string itemName, itemDescription;
    float itemPrice;
    int itemQuantity, itemID;
    //vector<Item>& items;

    cout << "Enter item name: \n";
    cin.ignore();
    getline(cin, itemName);
    
    cout << "Enter item ID: \n";
    cin >> itemID;
    
    cout << "Enter item description: \n";
    cin.ignore();
    getline(cin, itemDescription);
    
    cout << "Enter the price: \n";
    cin >> itemPrice;
    
    cout << "Enter quantity: ";
    cin >> itemQuantity;
    
    int newItemID = items.size() + 1;
    Item newItem(itemID, itemName, itemDescription, itemPrice, itemQuantity);
    items.push_back(newItem);
}

void Admin::editItem() {
    int itemID;
    string newItemName, newItemDescription;
    float newItemPrice;
    int newItemQuantity;

    cout << "Enter the item ID to edit: ";
    cin >> itemID;

    cout << "Enter the new item name: ";
    cin.ignore();
    getline(cin, newItemName);

    cout << "Enter the new item description: ";
    getline(cin, newItemDescription);

    cout << "Enter the new price: ";
    cin >> newItemPrice;

    cout << "Enter the new quantity: ";
    cin >> newItemQuantity;

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

void Admin::removeItem() {
    int itemID;

    cout << "Enter the item ID to remove: ";
    cin >> itemID;

    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemID() == itemID) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void Admin::displayItems() const {
    if (items.size() == 0) {
        cout << "The inventory is empty\n";
    }
    for (const Item& item : items) {
        cout << "ID: " << item.getItemID()
             << "\nName: " << item.getItemName()
             << " \nDescription: "<< item.getItemDescription()
             << "\nPrice: $" << item.getItemPrice()
             << "\nQuantity: " << item.getItemQuantity() << endl;
    }
}

vector<Item> Admin::getItems() const {
    return items;
}

void Admin::adminLogin(map<string, Admin>& admins, vector<Item>& items) {
    // Log in as admin
    string adminName;
    cout << "Enter admin name: ";
    cin >> adminName;

    auto adminIter = admins.find(adminName);
    if (adminIter != admins.end()) {
        Admin& admin = adminIter->second;
//        admin.setItems(items);
        
        string password;
        cout << "Enter password: ";
        cin >> password;
        
        if (admin.password == password) {
            cout << "Admin logged in successfully." << endl;   
            int adminChoice;
            
            do {
                adminChoice = admin.adminMenu();
                switch (adminChoice) {
                    case 1:
                        admin.displayItems();
                        break;
                    case 2:
                        admin.addItem();
                        break;
                    case 3:
                        admin.editItem();
                        break;
                    case 4:
                        admin.removeItem();
                        break;
                    case 5:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice. Try again.\n";
                }
            } while (adminChoice != 5);
        } else {
            cout << "Incorrect password." << endl;
        }
    } else {
        cout << "Admin not found" << endl;
    }
}
int Admin::adminMenu() {
    int choice;
    cout << "\nAdmin Menu:\n"
         << "1. Display inventory\n"
         << "2. Add item to inventory\n"
         << "3. Edit item\n"
         << "4. Remove item from inventory\n"
         << "5. Logout\n";
    cin >> choice;
    return choice;
}