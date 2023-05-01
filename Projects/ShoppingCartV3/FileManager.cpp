/* 
 * File:   FileManager.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

// FileManager.cpp
#include <fstream>
#include "FileManager.h"

void FileManager::readAdmins(const string& filename, map<string, Admin>& admins) {
    ifstream inFile(filename, ios::binary);

    if (!inFile) return;

    // Read admins from the binary file
    // Implement the read process based on the Admin class structure
}

void FileManager::writeAdmins(const string& filename, const map<string, Admin>& admins) {
    ofstream outFile(filename, ios::binary);

    // Write admins to the binary file
    // Implement the write process based on the Admin class structure
}

void FileManager::readUsers(const string& filename, map<string, User>& users) {
    ifstream inFile(filename, ios::binary);

    if (!inFile) return;

    // Read users from the binary file
    // Implement the read process based on the User class structure
}

void FileManager::writeUsers(const string& filename, const map<string, User>& users) {
    ofstream outFile(filename, ios::binary);

    // Write users to the binary file
    // Implement the write process based on the User class structure
}

void FileManager::readItems(const string& filename, vector<Item>& items) {
    ifstream inFile(filename, ios::binary);

    if (!inFile) return;

    Item item;
    while (inFile.peek() != EOF) {
        item.readItem(inFile);
        items.push_back(item);
    }
}

void FileManager::writeItems(const string& filename, const vector<Item>& items) {
    ofstream outFile(filename, ios::binary);

    for (const Item& item : items) {
        item.writeItem(outFile);
    }
}