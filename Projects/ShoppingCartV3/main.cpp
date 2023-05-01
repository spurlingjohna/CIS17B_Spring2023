/* 
 * File:   main.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include <iostream>
#include <map>
#include "Admin.h"
#include "User.h"
#include "FileManager.h"

using namespace std;

void displayMenu() {
    cout << "\nChoose an option:\n"
              << "1. Log in as admin\n"
              << "2. Log in as user\n"
              << "3. Exit\n";
}

int main() {
    map<string, Admin> admins;
    map<string, User> users;
    vector<Item> items;
    
    // Read data from binary files
    FileManager::readAdmins("admins.bin", admins);
    FileManager::readUsers("users.bin", users);
    FileManager::readItems("items.bin", items);

    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            Admin::adminLogin(admins, items);         
        } else if (choice == 2) {
            User::userLogin(users, items);
        }
    } while (choice != 3);
    
    // Save data to binary files
    FileManager::writeAdmins("admins.bin", admins);
    FileManager::writeUsers("users.bin", users);
    FileManager::writeItems("items.bin", items);
    
        

    return 0;
}
