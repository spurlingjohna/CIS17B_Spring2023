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

// Function to display the main menu options
void displayMenu() {
    cout << "\nChoose an option:\n"
              << "1. Log in as admin\n"
              << "2. Log in as user\n"
              << "3. Exit\n";
}

int main() {
    // Initialize empty maps for admins and users, and an empty vector for items
    map<string, Admin> admins;
    map<string, User> users;
    vector<Item> items;
    
    // Read data from binary files using FileManager class
    FileManager::readAdmins("admins.bin", admins);
    FileManager::readUsers("users.bin", users);
    FileManager::readItems("items.bin", items);

    int choice;

    // Display main menu and prompt user to choose an option
    do {
        displayMenu();
        cin >> choice;

        // If user chooses to log in as admin, call adminLogin function of Admin class
        if (choice == 1) {
            Admin::adminLogin(admins, items);         
        } 
        // If user chooses to log in as user, call userLogin function of User class
        else if (choice == 2) {
            User::userLogin(users, items);
        }
    } while (choice != 3);
    
    // Save data to binary files using FileManager class
    FileManager::writeAdmins("admins.bin", admins);
    FileManager::writeUsers("users.bin", users);
    FileManager::writeItems("items.bin", items);
    
    return 0;
}