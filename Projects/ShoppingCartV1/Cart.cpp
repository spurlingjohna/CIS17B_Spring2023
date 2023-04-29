/* 
 * File:   Cart.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "Cart.h"

void Cart::addItem(const Item& item) {
    items.push_back(item);
}

void Cart::removeItem(int itemID) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemID() == itemID) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void Cart::displayCartItems() const {
    for (const Item& item : items) {
        cout << "ID: " << item.getItemID()
                  << " Name: " << item.getItemName()
                  << " Description: " << item.getItemDescription()
                  << " Price: $" << item.getItemPrice()
                  << " Quantity: " << item.getItemQuantity() << endl;
    }
}

float Cart::calculateTotal() const {
    double total = 0.0;
    for (const Item& item : items) {
        total += item.getItemPrice();
    }
    return total;
}

void Cart::emptyCart() {
    items.clear();
}
