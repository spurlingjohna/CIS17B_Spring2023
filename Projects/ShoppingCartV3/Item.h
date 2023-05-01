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
    Item() : id(0), name(""), description(""), price(0.0), quantity(0) {}
    Item(int itemID, const string& itemName, const string& itemDescription,
            float itemPrice, int itemQuantity);
    
    int getItemID() const;
    string getItemName() const;
    string getItemDescription() const;
    float getItemPrice() const;
    int getItemQuantity() const;
    void setItemName(const string& newName);
    void setItemDescription(const string& newDescription);
    void setItemPrice(float newPprice);
    void setItemQuantity(int newQuantity);
    void readItem(ifstream& inFile);
    void writeItem(ofstream& outFile) const;
    
    
private:
    int id;
    string name;
    string description;
    float price;
    int quantity;
};
        
     

#endif /* ITEM_H */

