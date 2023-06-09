/* 
 * File:   Cart.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include "Cart.h"

// Adds the given item to the cart by pushing it to the end of the vector
void Cart::addItem(const Item& item) {
    items.push_back(item);
}

// Removes an item from the cart based on its ID by searching for it in the vector and erasing it
void Cart::removeItem(int itemID) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getItemID() == itemID) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

// Displays all items in the cart by iterating through the vector and printing the details of each item
void Cart::displayCartItems() const {
    for (const Item& item : items) {
        std::cout << "ID: " << item.getItemID()
                  << " Name: " << item.getItemName()
                  << " Description: " << item.getItemDescription()
                  << " Price: $" << item.getItemPrice()
                  << " Quantity: " << item.getItemQuantity() << std::endl;
    }
}

// Calculates the total cost of all items in the cart by iterating through the vector and summing their prices
float Cart::calculateTotal() const {
    double total = 0.0;
    for (const Item& item : items) {
        total += item.getItemPrice();
    }
    return total;
}

// Removes all items from the cart by clearing the vector
void Cart::emptyCart() {
    items.clear();
}
