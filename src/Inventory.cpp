#include <iostream>
#include "Inventory.h"

Inventory::Inventory() : weight(0) {}

void Inventory::addItem(Item* item) {

    auto newItemKeyword = item->getKeyword();
    for (auto i : items) {
        if (i->getKeyword() == newItemKeyword) {
            i->changeCount(item->getCount());
            weight += item->getCount() * item->getWeight();
            return;
        }
    }
    items.emplace_back(item);
    weight += item->getCount() * item->getWeight();
}

void Inventory::removeItem(Item* item) {
    auto& removedItemKeyword = item->getKeyword();
    auto iter = items.begin();
    while (iter < items.end()) {
        if ((*iter)->getKeyword() == removedItemKeyword) {
            auto diff = (*iter)->getCount() - item->getCount() < 0
                        ? (*iter)->getCount()
                        : item->getCount();
            (*iter)->changeCount(-(item->getCount()));
            if ((*iter)->getCount() <= 0) items.erase(iter);
            weight -= diff * item->getWeight();
            return;
        }
        iter++;
    }
}

void Inventory::displayInventory() const {
    for (auto item:items) {
        std::cout << item->getCount() << " " << item->getName()
                  << " (" << item->getKeyword() << ", "
                  << item->getWeight() << ")"
                  << std::endl;
    }
    std::cout << "Total weight: " << weight << std::endl;
}
