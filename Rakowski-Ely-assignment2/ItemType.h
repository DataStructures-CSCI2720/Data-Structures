#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>

using namespace std;

enum class Comparison {GREATER, LESS, EQUAL};   // Comparison values

class ItemType {

    private:
        int value;                              // value

    public:
        ItemType();                             // default constructor

        Comparison compareTo(ItemType item);    // compares two ItemType items

        int getValue() const;                   // gets private value

        void initialize(int num);               // initializes the private value
};

#endif