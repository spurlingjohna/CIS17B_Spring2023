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
    
    admins.insert(make_pair("Admin1", Admin("Admin1")));
    users.insert(make_pair("User1", User("User1")));

    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            // Log in as admin
            string adminName;
            cout << "Enter admin name: ";
            cin >> adminName;

            if (admins.find(adminName) != admins.end()) {
                Admin& admin = admins[adminName];
                
                // Admin can interact with the system here
                // For example, adding items, editing items, etc.
            } else {
                cout << "Admin not found.\n";
            }
        } else if (choice == 2) {
            // Log in as user
            string userName;
            cout << "Enter user name: ";
            cin >> userName;

            if (users.find(userName) != users.end()) {
                User& user = users[userName];
                
                // User can interact with the system here
                // For example, browsing items, adding items to the cart, etc.
            } else {
                cout << "User not found.\n";
            }
        }
    } while (choice != 3);

    return 0;
}
