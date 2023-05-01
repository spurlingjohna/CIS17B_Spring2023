/* 
 * File:   Admin.cpp
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#include <iostream>
#include "Admin.h"
#include "Controller.h"

using namespace std;

Admin::Admin(const string& username, const string& password)
    : User(username, password) {}

void Admin::viewUserLoginTime(const User& user) const {
    cout << "User " << user.getUsername() << " has been logged in for "
         << user.getElapsedTime() << " seconds.\n";
}

void Admin::adminMenu(Controller* controller, Admin& admin) {
    int choice;
    bool quit = false;

    while (!quit) {
        cout << "\nAdmin Menu\n"
                  << "1. Display login time\n"
                  << "2. Display login time for another user\n"
                  << "3. Logout\n"
                  << "4. Quit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Display login time
                controller->displayLoginTime(admin.getUsername());
                break;
            case 2:
                {
                    // Display login time for another user
                    string targetUsername;
                    cout << "Enter the username of the user to view login time: ";
                    cin >> targetUsername;
                    admin.viewUserLoginTime(*controller->getUser(targetUsername));
                }
                break;
            case 3:
                // Logout
                admin.logout();
                break;
            case 4:
                // Quit
                quit = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}