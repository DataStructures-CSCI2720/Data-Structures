#include <iostream>
#include "ItemType.h"
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

ItemType::ItemType() {
    initialize(0);
}

Comparison ItemType::compareTo(ItemType item) {
    if (getValue() > item.getValue()) {
        return Comparison::GREATER;
    } else if (getValue() < item.getValue()) {
        return Comparison::LESS;
    } else {
        return Comparison::EQUAL;
    }
}

int ItemType::getValue() const {
    return this -> value;
}

void ItemType::initialize(int num) {
    value = num;
}