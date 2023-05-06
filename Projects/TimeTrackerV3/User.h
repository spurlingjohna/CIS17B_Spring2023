/* 
 * File:   User.h
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

#ifndef USER_H
#define USER_H

#pragma once
#include <string>
#include "TimeTracker.h"
using namespace std;

class Controller;

class User {
public:
    User(const string& username, const string& password);
    virtual ~User() = default;

    string getUsername() const;
    string getPassword() const;

    void login();
    void logout();
    
    float getElapsedTime() const;
    
    void userMenu(Controller* controller, User& user);

protected:
    TimeTracker timeTracker;

private:
    string username;
    string password;
};

#endif /* USER_H */

