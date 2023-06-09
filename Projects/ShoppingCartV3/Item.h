/* 
 * File:   Item.h
 * Author: Andrew Spurling
 * Date:   4/27/23
 * 
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    // Default constructor
    Item() : id(0), name(""), description(""), price(0.0), quantity(0) {}
    
    // Constructor with arguments
    Item(int itemID, const string& itemName, const string& itemDescription,
         float itemPrice, int itemQuantity);
    
    // Getter functions for item properties
    int getItemID() const;
    string getItemName() const;
    string getItemDescription() const;
    float getItemPrice() const;
    int getItemQuantity() const;
    
    // Setter functions for item properties
    void setItemName(const string& newName);
    void setItemDescription(const string& newDescription);
    void setItemPrice(float newPrice);
    void setItemQuantity(int newQuantity);
    
    // Read and write item data to a file
    void readItem(ifstream& inFile);
    void writeItem(ofstream& outFile) const;
    
private:
    // Private member variables
    int id;
    string name;
    string description;
    float price;
    int quantity;
};

#endif /* ITEM_H */


