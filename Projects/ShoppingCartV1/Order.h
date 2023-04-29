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
    Order(int orderID, const std::string& userID, const std::vector<Item>& items);

    int getOrderID() const;
    std::string getUserID() const;
    std::vector<Item> getOrderItems() const;
    double getOrderTotal() const;
    std::string getOrderStatus() const;

    void setOrderStatus(const std::string& newStatus);

private:
    int id;
    std::string userID;
    std::vector<Item> items;
    double total;
    std::string status;
};

#endif // ORDER_H
