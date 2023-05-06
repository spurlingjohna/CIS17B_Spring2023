/* 
 * File:   Admin.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include <map>
#include "Item.h"  // header file for Item class

using namespace std;

class Admin {
public:
    // Default constructor
    Admin() : adminName(""), password(""), items() {}
    // Constructor with arguments
    Admin(const string& adminName, const string& password, vector<Item>& items);
    
    // Functions to manage inventory
    void addItem();           
    void editItem();
    void removeItem();
    void displayItems() const;
    vector<Item> getItems() const;
    
    // Static function to log in admin
    static void adminLogin(map<string, Admin>& admins, vector<Item>& items);
    
    // Function to display admin menu and prompt user to choose an option
    int adminMenu();
    
private:
    // Private member variables
    vector<Item> items;
    string adminName;
    string password;
};

#endif /* ADMIN_H */