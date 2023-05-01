/* 
 * File:   Controller.cpp
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#include "Controller.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <memory>

using namespace std;

void Controller::createUser(const string& username, const string& password, bool isAdmin) {
    if (isAdmin) {
        users.emplace_back(new Admin(username, password));
    } else {
        users.emplace_back(new User(username, password));
    }
}

User* Controller::getUser(const string& username) const {
    auto userIt = find_if(users.begin(), users.end(),
        [&username](const unique_ptr<User>& user) { return user->getUsername() == username; });

    if (userIt != users.end()) {
        return userIt->get();
    }

    return nullptr;
}

void Controller::deleteUser(const string& username) {
    auto userIt = find_if(users.begin(), users.end(),
        [&username](const unique_ptr<User>& user) { return user->getUsername() == username; });

    if (userIt != users.end()) {
        users.erase(userIt);
    }
}

void Controller::displayLoginTime(const std::string& username) const {
    User* user = getUser(username);
    if (user) {
        Admin* admin = dynamic_cast<Admin*>(user);
        if (admin) {
            admin->viewUserLoginTime(*user);
        } else {
            std::cout << "Only admins can view login time.\n";
        }
    } else {
        std::cout << "User not found.\n";
    }
}