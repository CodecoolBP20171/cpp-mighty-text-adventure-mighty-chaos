#include <iostream>
#include "Item.h"

Item::Item(ItemDescriptor* descriptor, int count = 0) : descriptor(descriptor), count(count) {}

int Item::getCount() const {
    return count;
}

void Item::changeCount(int diff) {
    Item::count += diff;
}

const std::string Item::toString() const {
    return std::to_string(count) + " " + descriptor->getName()
              + " (" + descriptor->getKeyword() + ", "
              + std::to_string(descriptor->getWeight()) + ")";
}

const std::string& Item::getKeyword() const {
    return descriptor->getKeyword();
}

const int Item::getWeight() const {
    return descriptor->getWeight();
}

void Item::setCount(int count) {
    Item::count = count;
}

ItemDescriptor* Item::getDescriptor() const {
    return descriptor;
}
