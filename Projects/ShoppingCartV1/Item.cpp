/* 
 * File:   Item.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include "Item.h"

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
