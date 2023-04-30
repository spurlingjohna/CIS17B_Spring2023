/* 
 * File:   User.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "User.h"

using namespace std;

User::User(const string& userName, const string& password)
            : userName(userName), password(password) {}

void User::browseItems(const vector<Item>& items) {
    for (const Item& item : items) {
        cout << "ID: " << item.getItemID()
             << " Name: " << item.getItemID()
             << " Description: " << item.getItemDescription()
             << " Price: $" << item.getItemPrice()
             << " Quantity: " << item.getItemQuantity() << endl;
    }
}

void User::addToCart(int itemID, const vector<Item>& items) {
    for (const Item& item : items) {
        if (item.getItemID() == itemID) {
            cart.addItem(item);
            break;
        }
    }
}

void User::removeFromCart(int itemID) {
    cart.removeItem(itemID);
}

void User::viewCart() const {
    cart.displayCartItems();
}

void User::placeOrder() {
    cart.emptyCart();
}

void User::userLogin(map<string, User>& users) {
    // Log in as user
    string userName;
    cout << "Enter user name: ";
    cin >> userName;

    auto userIter = users.find(userName);
    if (userIter != users.end()) {
        User& user = userIter->second;
        
        string password;
        cout << "Enter password: " << endl;
        cin >> password;
        
        if (user.password == password) {
            cout << "User logged in successfully." << endl;
        } else {
            cout << "Incorrect password." << endl;
        }
    } else {
        cout << "User not found" << endl;
    }
}