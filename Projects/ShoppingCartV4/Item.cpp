/* 
 * File:   Item.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include "Item.h"
#include <fstream>
using namespace std;

Item::Item(int itemID, const string& itemName, const string& itemDescription,
            float itemPrice, int itemQuantity) 
        : id(itemID), name(itemName), description(itemDescription),
        price(itemPrice), quantity(itemQuantity) {}

int Item::getItemID() const {
    return id;
}

string Item::getItemName() const {
    return name;
}

string Item::getItemDescription() const {
    return description;
}

float Item::getItemPrice() const {
    return price;
}

int Item::getItemQuantity() const {
    return quantity;
}

void Item::setItemName(const string& newName) {
    name = newName;
}

void Item::setItemDescription(const string& newDescription) {
    description = newDescription;
}

void Item::setItemPrice(float newPrice) {
    price = newPrice;
}

void Item::setItemQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Item::readItem(ifstream& inFile) {
    inFile.read(reinterpret_cast<char*>(&id), sizeof(id));
    // Read string from the binary file
    size_t strSize;
    inFile.read(reinterpret_cast<char*>(&strSize), sizeof(strSize));
    char* buffer = new char[strSize + 1];
    inFile.read(buffer, strSize);
    buffer[strSize] = '\0';
    name = buffer;
    delete[] buffer;

    inFile.read(reinterpret_cast<char*>(&price), sizeof(price));
    inFile.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
}

void Item::writeItem(ofstream& outFile) const {
    outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
    // Write string to the binary file
    size_t strSize = name.size();
    outFile.write(reinterpret_cast<const char*>(&strSize), sizeof(strSize));
    outFile.write(name.c_str(), strSize);

    outFile.write(reinterpret_cast<const char*>(&price), sizeof(price));
    outFile.write(reinterpret_cast<const char*>(&quantity), sizeof(quantity));
}
