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

    // Create sample users and admin
    controller.createUser("user1", "password1");
    controller.createUser("admin1", "password1", true);

    string username;
    string password;

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

    return 0;
}


