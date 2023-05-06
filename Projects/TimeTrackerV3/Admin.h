/* 
 * File:   Admin.h
 * Author: Andrew Spurling
 * Date:   4/30/23
 * 
 */

/* 
 * File:   Admin.h
 * Author: andrewspurling
 *
 * Created on April 30, 2023, 1:09 PM
 */

#ifndef ADMIN_H
#define ADMIN_H

#pragma once
#include "User.h"

using namespace std;

class Controller;

class Admin : public User {
public:
    Admin(const string& username, const string& password);
    void viewUserLoginTime(const User& user) const;
    void adminMenu(Controller* controller, Admin& admin);
};


#endif /* ADMIN_H */

