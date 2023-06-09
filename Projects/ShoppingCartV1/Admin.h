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
#include "Item.h"

using namespace std;

class Admin {
public:
    Admin();
    Admin(const string& adminName);
    
    void addItem(const string& itemName, const string& itemDescription,
                 float itemPrice, int itemQuantity);
    
    void editItem(int itemID, const string& newItemName, const string& 
                  newItemDescription, float newItemPrice, int newItemQuantity);
    
    void removeItem(int itemID);
    
    void displayItems() const;
    
    vector<Item> getItems() const;
    
private:
    string name;
    vector<Item> items;
};


#endif /* ADMIN_H */

