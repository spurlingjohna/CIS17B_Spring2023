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

            auto adminIter = admins.find(adminName);
            if (adminIter != admins.end()) {
                Admin& admin = adminIter->second;
            } else {
                cout << "Admin not found" << endl;
            }
            
            
        } else if (choice == 2) {
            // Log in as user
            string userName;
            cout << "Enter user name: ";
            cin >> userName;

            auto userIter = users.find(userName);
            if (userIter != users.end()) {
                User& user = userIter->second;
            } else {
                cout << "User not found" << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
