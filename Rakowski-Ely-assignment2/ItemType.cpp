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
    // if item.getValue() > this.getValue ...
    // write later lol
    return Comparison::LESS;
}

int ItemType::getValue() const {
    return this -> value;
}

void ItemType::initialize(int num) {
    value = num;
}