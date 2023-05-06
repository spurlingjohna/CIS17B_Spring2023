/* 
 * File:   main.cpp
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#include <iostream>
#include <string>
#include "Controller.h"
#include "User.h"
#include "Admin.h"
#include <thread>
#include <chrono>

using namespace std;

void adminMenu(Controller* controller, Admin& admin);
void userMenu(Controller* controller, User& user);

int main() {
    Controller controller;

    // Load user data from file
    controller.loadUserData();

    string username;
    string password;
    int choice;
    bool quit = false;

    while (!quit) {
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    // Existing login process
                    cout << "Enter your username: ";
                    cin >> username;

                    cout << "Enter your password: ";
                    cin >> password;

                    User* user = controller.getUser(username);

                    if (user && user->getPassword() == password) {
                        user->login();

                        Admin* admin = dynamic_cast<Admin*>(user);
                        if (admin) {
                            admin->adminMenu(&controller, *admin);
                        } else {
                            user->userMenu(&controller, *user);
                        }
                    } else {
                        cout << "Invalid username or password.\n";
                    }
                }
                break;
            case 2:
                {
                    // Registration process
                    bool isAdmin;

                    cout << "Enter a new username: ";
                    cin >> username;

                    cout << "Enter a new password: ";
                    cin >> password;

                    cout << "Is admin? (1 for yes, 0 for no): ";
                    cin >> isAdmin;

                    controller.createUser(username, password, isAdmin);
                    controller.saveUserData(); // Save user data after registration
                    cout << "User registered successfully.\n";
                }
                break;
            case 3:
                // Exit
                quit = true;
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
