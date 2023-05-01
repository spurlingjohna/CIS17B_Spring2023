/* 
 * File:   User.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include <algorithm>
#include "User.h"

using namespace std;

User::User(const string& userName, const string& password, vector<Item>& items)
            : cart(), userName(userName), password(password), items(items) {};


void User::browseItems() {
    int itemChoice;
    do {
        cout << "Available Items:\n";
        for (const Item& item : items) {
            displayItem(item);
        }
        cout << "Enter item ID to view details, or 0 to exit: ";
        cin >> itemChoice;

        if (itemChoice != 0) {
            auto itemIter = find_if(items.begin(), items.end(), [&itemChoice](const Item& item) {
                return item.getItemID() == itemChoice;
            });

            if (itemIter != items.end()) {
                const Item& selectedItem = *itemIter;
                displayItem(selectedItem);

                cout << "Enter 1 to add to cart, or 0 to return to browsing: ";
                int addChoice;
                cin >> addChoice;
                if (addChoice == 1) {
                    cart.addItem(selectedItem);
                    cout << "Item added to cart.\n";
                }
            } else {
                cout << "Item not found.\n";
            }
        }
    } while (itemChoice != 0);
}

void User::displayItem(const Item& item) {
    cout << "ID: " << item.getItemID()
         << " Name: " << item.getItemName()
         << " Price: $" << item.getItemPrice() << endl;
}


void User::addToCart() {
    int itemID;

    cout << "Enter the item ID to add to the cart: ";
    cin >> itemID;

    for (const Item& item : items) {
        if (item.getItemID() == itemID) {
            cart.addItem(item);
            break;
        }
    }
}

void User::removeFromCart() {
    int itemID;

    cout << "Enter the item ID to remove from the cart: ";
    cin >> itemID;

    cart.removeItem(itemID);
}
void User::viewCart() const {
    cart.displayCartItems();
}

void User::placeOrder() {
    cart.emptyCart();
}

void User::userLogin(map<string, User>& users, const vector<Item>& items) {
    string userName;
    cout << "Enter user name: ";
    cin >> userName;

    auto userIter = users.find(userName);
    if (userIter != users.end()) {
        User& user = userIter->second;

        string password;
        cout << "Enter password: ";
        cin >> password;

        if (user.password == password) {
            cout << "User logged in successfully." << endl;
            int userChoice;

            do {
                userChoice = user.userMenu();
                switch (userChoice) {
                    case 1:
                        user.browseItems();
                        break;
                    case 2:
                        user.addToCart();
                        break;
                    case 3:
                        user.removeFromCart();
                        break;
                    case 4:
                        user.viewCart();
                        break;
                    case 5:
                        user.placeOrder();
                        break;
                    case 6:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice. Try again.\n";
                }
            } while (userChoice != 6);
        } else {
            cout << "Incorrect password." << endl;
        }
    } else {
        cout << "User not found" << endl;
    }
}

int User::userMenu() {
    int choice;
    cout << "\nUser Menu:\n"
         << "1. Browse items\n"
         << "2. Add item to cart\n"
         << "3. Remove item from cart\n"
         << "4. View cart\n"
         << "5. Place order\n"
         << "6. Logout\n";
    cin >> choice;
    return choice;
}