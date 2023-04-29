/* 
 * File:   User.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "User.h"

using namespace std;

User::User(const string& userName) : userName(userName) {

}

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