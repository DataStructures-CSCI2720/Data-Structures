#include <iostream>
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;

/*
 * ItemType constructor which initializes the values to zero.
 */
ItemType::ItemType() {
    initialize(0);
} // constructor

/*
 * Compares the ItemType to the value of the inputted ItemType.
 * @param item contains an item value that is used for comparison.
 * @return Comparison::GREATER indicates the item is greater than the comparison.
 * @retrun Comparison::LESS indicates the item is less than the comparison.
 * @return Comparison::EQUAL indicates the item is equal to the comparison.
 */
Comparison ItemType::compareTo(ItemType item) {
    if (getValue() > item.getValue()) {
        return Comparison::GREATER;
    } else if (getValue() < item.getValue()) {
        return Comparison::LESS;
    } else {
        return Comparison::EQUAL;
    } // if
} // compareTo

/*
 * getValue is a getter. Finds the value stored in an ItemType.
 * @return values is the value stored in the ItemType
 */
int ItemType::getValue() const {
    return this -> value;
} // getValue

/*
 * Setter method that sets the value of the user inputted integer to the item.
 * @param num is the integer the user is setting the ItemType value too
 */
void ItemType::initialize(int num) {
    value = num;
} // initialize
