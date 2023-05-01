/* 
 * File:   Order.cpp
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#include "Order.h"

Order::Order(int orderID, const std::string& userID, const std::vector<Item>& items)
    : id(orderID), userID(userID), items(items), status("Pending") {
    total = 0.0;
    for (const Item& item : items) {
        total += item.getItemPrice();
    }
}

int Order::getOrderID() const {
    return id;
}

std::string Order::getUserID() const {
    return userID;
}

std::vector<Item> Order::getOrderItems() const {
    return items;
}

double Order::getOrderTotal() const {
    return total;
}

std::string Order::getOrderStatus() const {
    return status;
}

void Order::setOrderStatus(const std::string& newStatus) {
    status = newStatus;
}
