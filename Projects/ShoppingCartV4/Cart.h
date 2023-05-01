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

using namespace std;

class Cart {
public:
    void addItem(const Item& item);
    void removeItem(int itemID);
    void displayCartItems() const;
    float calculateTotal() const;
    void emptyCart();
    
private:
    vector<Item> items;
};

#endif /* CART_H */

