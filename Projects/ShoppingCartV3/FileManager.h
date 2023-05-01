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
    static void readAdmins(const string& filename, map<string, Admin>& admins);
    static void writeAdmins(const string& filename, const map<string, Admin>& admins);

    static void readUsers(const string& filename, map<string, User>& users);
    static void writeUsers(const string& filename, const map<string, User>& users);

    static void readItems(const string& filename, vector<Item>& items);
    static void writeItems(const string& filename, const vector<Item>& items);
};

#endif // FILE_MANAGER_H