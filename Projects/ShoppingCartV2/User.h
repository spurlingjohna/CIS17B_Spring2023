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

using namespace std;

class User {
public:
    User() : userName(""), password("") {}   
    User(const string& userName, const string& password);
    
    void browseItems(const vector<Item>& items);
    void addToCart(int itemID, const vector<Item>& items);
    void removeFromCart(int itemID);
    void viewCart() const;
    void placeOrder();
    static void userLogin(map<string, User>& users);
    
private:
    string name;
    Cart cart;
    string userName;
    string password;
};

#endif /* USER_H */

