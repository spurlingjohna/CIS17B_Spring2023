/* 
 * File:   Admin.h
 * Author: Andrew Spurling
 *
 * Created on April 27, 2023, 7:39 PM
 */

#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include <"Item.h">

using namespace std;

class Admin {
public:
    Admin(const std::string& adminName);
    
    void addItem(const string& itemName, const string& itemDescription,
                 double itemPrice, int itemQuantity);
    
    void editItem(int itemID, const string& newItemName, const string&,
                  newItemDescription, double newItemPrice, int newItemQuantity);
    
    void removeItem(int itemID);
    
    void displayItems() const;
    
private:
    std::string name;
    std::vector<Item> items;
};


#endif /* ADMIN_H */

