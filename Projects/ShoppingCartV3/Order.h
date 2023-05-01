/* 
 * File:   Order.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Item.h"

class Order {
public:
    // Constructor with arguments
    Order(int orderID, const string& userID, const vector<Item>& items);

    // Getter functions for order properties
    int getOrderID() const;
    string getUserID() const;
    vector<Item> getOrderItems() const;
    float getOrderTotal() const;
    string getOrderStatus() const;

    // Setter function for order status
    void setOrderStatus(const string& newStatus);

private:
    // Private member variables
    int id;
    string userID;
    vector<Item> items;
    float total;
    string status;
};

#endif /* ORDER_H */
