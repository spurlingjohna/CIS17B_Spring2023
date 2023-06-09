/* 
 * File:   Cart.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef CART_H
#define CART_H

#include <vector>
#include "Item.h"

class Cart {
public:
    // Add an item to the cart
    void addItem(const Item& item);
    
    // Remove an item from the cart
    void removeItem(int itemID);
    
    // Display all items in the cart
    void displayCartItems() const;
    
    // Calculate the total cost of all items in the cart
    float calculateTotal() const;
    
    // Empty the cart of all items
    void emptyCart();
    
private:
    // Private member variable
    vector<Item> items;
};

#endif /* CART_H */
