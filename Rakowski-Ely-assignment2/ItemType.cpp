#include <iostream>
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;

ItemType::ItemType() {
    initialize(0);
} // constructor

Comparison ItemType::compareTo(ItemType item) {
    if (getValue() > item.getValue()) {
        return Comparison::GREATER;
    } else if (getValue() < item.getValue()) {
        return Comparison::LESS;
    } else {
        return Comparison::EQUAL;
    } // if
} // compareTo

int ItemType::getValue() const {
    return this -> value;
} // getValue

void ItemType::initialize(int num) {
    value = num;
} // initialize
