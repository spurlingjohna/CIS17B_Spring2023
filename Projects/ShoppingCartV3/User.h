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
#include <map>
#include "Cart.h"
#include "Item.h"

using namespace std;

class User {
public:
    User() : userName(""), password(""), items() {}   
    
    User(const string& userName, const string& password, vector<Item>& items);
    
    void browseItems();
    void addToCart();
    void removeFromCart();
    void viewCart() const;
    void placeOrder();
    static void userLogin(map<string, User>& users, const vector<Item>& items);
    void displayItem(const Item& item);
    int userMenu();
    
private:
    string name;
    Cart cart;
    string userName;
    string password;
    vector<Item> items;
};

#endif /* USER_H */

