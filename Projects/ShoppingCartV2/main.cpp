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
    vector<Item> items;
    
    admins.insert(make_pair("Admin1", Admin("Admin1", "password", items)));
    users.insert(make_pair("User1", User("User1", "user1password", items)));

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

    return 0;
}
