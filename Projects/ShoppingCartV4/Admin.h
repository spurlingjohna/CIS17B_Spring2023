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
#include "Item.h"

using namespace std;

class Admin {
public:
    Admin() : adminName(""), password(""), items() {}
    Admin(const string& adminName, const string& password, vector<Item>& items);
    
    void addItem();           
    
    void editItem();
    
    void removeItem();
    
    void displayItems() const;
    
    vector<Item> getItems() const;
    
    static void adminLogin(map<string, Admin>& admins, vector<Item>& items);
    
    int adminMenu();
    
private:
    string name;
    vector<Item> items;
    string adminName;
    string password;
};


#endif /* ADMIN_H */

