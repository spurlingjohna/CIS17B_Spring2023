/* 
 * File:   Order.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include "Order.h"

// Constructor initializes order ID, user ID, items, and status
Order::Order(int orderID, const string& userID, const vector<Item>& items)
    : id(orderID), userID(userID), items(items), status("Pending") {
    // Calculate total price of items in the order
    total = 0.0;
    for (const Item& item : items) {
        total += item.getItemPrice();
    }
}

// Returns the order ID
int Order::getOrderID() const {
    return id;
}

// Returns the user ID
string Order::getUserID() const {
    return userID;
}

// Returns a vector of items in the order
vector<Item> Order::getOrderItems() const {
    return items;
}

// Returns the total price of the order
float Order::getOrderTotal() const {
    return total;
}

// Returns the status of the order
string Order::getOrderStatus() const {
    return status;
}

// Sets the status of the order to the specified string
void Order::setOrderStatus(const string& newStatus) {
    status = newStatus;
}
