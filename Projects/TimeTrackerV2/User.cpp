/* 
 * File:   User.cpp
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#include <iostream>
#include "User.h"
#include "Controller.h"

using namespace std;

User::User(const string& username, const string& password)
    : username(username), password(password) {}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

void User::login() {
    timeTracker.startTracking();
}

void User::logout() {
    timeTracker.stopTracking();
}

float User::getElapsedTime() const {
    return timeTracker.getElapsedTime();
}

void User::userMenu(Controller* controller, User& user) {
    int choice;
    bool quit = false;

    while (!quit) {
        cout << "\nUser Menu\n"
                  << "1. Display login time\n"
                  << "2. Logout\n"
                  << "3. Quit\n"
                  << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display login time
                controller->displayLoginTime(user.getUsername());
                break;
            case 2:
                // Logout
                user.logout();
                break;
            case 3:
                // Quit
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}