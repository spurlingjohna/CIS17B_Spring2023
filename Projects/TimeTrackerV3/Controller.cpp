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
#include <fstream>
#include <stdexcept>

using namespace std;


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
            cout << "Only admins can view login time.\n";
        }
    } else {
        cout << "User not found.\n";
    }
}

void Controller::saveUserData() {
    ofstream out("userdata.bin", ios::binary);
    
    if (!out) {
        throw runtime_error("Unable to open file for writing.");
    }
    
    for (const auto& user : users) {
        // Save username and password as C-strings to preserve the null terminator
        out.write(user->getUsername().c_str(), user->getUsername().length() + 1);
        out.write(user->getPassword().c_str(), user->getPassword().length() + 1);

        // Save isAdmin flag as a boolean
        bool isAdmin = dynamic_cast<Admin*>(user.get()) != nullptr;
        out.write(reinterpret_cast<const char*>(&isAdmin), sizeof(isAdmin));
    }

    out.close();
}

void Controller::loadUserData() {
    ifstream in("userdata.bin", ios::binary);

    if (!in) {
        return;  // It's okay if the file doesn't exist yet; just continue without loading data
    }

    while (!in.eof()) {
        string username, password;
        bool isAdmin;

        // Read username and password as C-strings
        getline(in, username, '\0');
        getline(in, password, '\0');

        // Break the loop if we've reached the end of the file
        if (in.eof()) break;

        // Read isAdmin flag as a boolean
        in.read(reinterpret_cast<char*>(&isAdmin), sizeof(isAdmin));

        // Create the user
        createUser(username, password, isAdmin);
    }

    in.close();
}

void Controller::createUser(const string& username, const string& password, bool isAdmin) {
    if (isAdmin) {
        users.emplace_back(new Admin(username, password));
    } else {
        users.emplace_back(new User(username, password));
    }

    // Save user data after creating a new user
    saveUserData();
}
