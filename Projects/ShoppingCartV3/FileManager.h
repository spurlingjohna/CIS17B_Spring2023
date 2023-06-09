/* 
 * File:   FileManager.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <map>
#include <vector>
#include "Admin.h"
#include "User.h"
#include "Item.h"

using namespace std;

class FileManager {
public:
    // Read admin data from binary file and populate the provided map
    static void readAdmins(const string& filename, map<string, Admin>& admins);

    // Write admin data to binary file from the provided map
    static void writeAdmins(const string& filename, const map<string, Admin>& admins);

    // Read user data from binary file and populate the provided map
    static void readUsers(const string& filename, map<string, User>& users);

    // Write user data to binary file from the provided map
    static void writeUsers(const string& filename, const map<string, User>& users);

    // Read item data from binary file and populate the provided vector
    static void readItems(const string& filename, vector<Item>& items);

    // Write item data to binary file from the provided vector
    static void writeItems(const string& filename, const vector<Item>& items);
};

#endif // FILE_MANAGER_H
