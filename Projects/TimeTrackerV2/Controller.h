/* 
 * File:   Controller.h
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "User.h"
#include "Admin.h"

using namespace std;

class Controller {
public:
    void createUser(const string& username, const string& password, bool isAdmin = false);
    User* getUser(const string& username) const;
    void deleteUser(const string& username);
    void displayLoginTime(const string& username) const;
    void saveUserData();
    void loadUserData();

private:
    vector<unique_ptr<User>> users;
};

#endif /* CONTROLLER_H */

