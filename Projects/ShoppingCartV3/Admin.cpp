/* 
 * File:   Admin.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "Admin.h"

using namespace std;

// Admin constructor that initializes an Admin object
// Takes in the adminName, password, and a vector of items
Admin::Admin(const string& adminName, const string& password, vector<Item>& items)
            : adminName(adminName), password(password), items(items) {}

// Function to add a new item to the inventory
void Admin::addItem() {
    string itemName, itemDescription;
    float itemPrice;
    int itemQuantity, itemID;

    // Prompt user for item details
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
    
    // Add new item to inventory
    int newItemID = items.size() + 1;
    Item newItem(itemID, itemName, itemDescription, itemPrice, itemQuantity);
    items.push_back(newItem);
}

// Function to edit an existing item in the inventory
void Admin::editItem() {
    int itemID;
    string newItemName, newItemDescription;
    float newItemPrice;
    int newItemQuantity;

    // Prompt user for item details to edit
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
    
    // Update item details
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

// Function to remove item
void Admin::removeItem() {
    int itemID;

    // Prompt user for item ID to remove
    cout << "Enter the item ID to remove: ";
    cin >> itemID;

    // Remove item from inventory
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemID() == itemID) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

// Display all items in inventory
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

// Get all items in inventory
vector<Item> Admin::getItems() const {
    return items;
}

// Function for Admin to login
void Admin::adminLogin(map<string, Admin>& admins, vector<Item>& items) {
    // Log in as admin
    string adminName;
    cout << "Enter admin name: ";
    cin >> adminName;

    auto adminIter = admins.find(adminName);
    if (adminIter != admins.end()) {
        Admin& admin = adminIter->second;
        
        string password;
        cout << "Enter password: ";
        cin >> password;
        
        // Check if password is correct
        if (admin.password == password) {
            cout << "Admin logged in successfully." << endl;   
            int adminChoice;
            
            // Display admin menu and perform chosen action
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

// Display admin menu options
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