#include "Item.h"
#include "ItemDescriptor.h"

Item::Item(ItemDescriptor* descriptor, int count = 0) : descriptor(descriptor), count(count) {}

int Item::getCount() const {
    return count;
}

void Item::changeCount(int diff) {
    Item::count += diff;
}

const std::string& Item::getName() const {
    return descriptor->getName();
}

const std::string& Item::getDecription() const {
    return descriptor->getDescription();
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
