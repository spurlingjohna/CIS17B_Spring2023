/* 
 * File:   User.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Cart.h"

using namespace std;

class User {
public:
    User();
    User(const string& userName);
    
    void browseItems(const vector<Item>& items);
    void addToCart(int itemID, const vector<Item>& items);
    void removeFromCart(int itemID);
    void viewCart() const;
    void placeOrder();
    
private:
    string name;
    Cart cart;
};

#endif /* USER_H */

