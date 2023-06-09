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

class User {
public:
    // Default constructor
    User() : userName(""), password(""), items() {}
    
    // Constructor with arguments
    User(const string& userName, const string& password, vector<Item>& items);
    
    // Functions for browsing items and managing the shopping cart
    void browseItems();
    void addToCart();
    void removeFromCart();
    void viewCart() const;
    void placeOrder();
    
    // Static function to log in a user
    static void userLogin(std::map<string, User>& users, const vector<Item>& items);
    
    // Function to display item details
    void displayItem(const Item& item);
    
    // Function to display the user menu and prompt the user to choose an option
    int userMenu();
    
private:
    // Private member variables
    string name;
    Cart cart;
    string userName;
    string password;
    vector<Item> items;
};

#endif /* USER_H */

