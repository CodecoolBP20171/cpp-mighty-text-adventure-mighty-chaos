#include <iostream>
#include "Inventory.h"

Inventory::Inventory() : weight(0) {}

int Inventory::getWeight() const {
    return weight;
}

bool Inventory::addItem(Item* item) {
    auto& newItemKeyword = item->getKeyword();
    for (auto i : items) {
        if (i->getKeyword() == newItemKeyword) {
            i->changeCount(item->getCount());
            weight += item->getCount() * item->getWeight();
            return false;
        }
    }
    items.push_back(item);
    weight += item->getCount() * item->getWeight();
    return true;
}

int Inventory::removeItem(const Item* item) {
    auto& removedItemKeyword = item->getKeyword();
    auto iter = items.begin();
    while (iter < items.end()) {
        if ((*iter)->getKeyword() == removedItemKeyword) {
            auto diff = ((*iter)->getCount() - item->getCount() < 0) ||
                        item->getCount() == 0
                        ? (*iter)->getCount()
                        : item->getCount();
            (*iter)->changeCount(-(item->getCount()));
            weight -= diff * item->getWeight();
            if ((*iter)->getCount() <= 0) {
                items.erase(iter);
                delete *iter;
            }
            return diff;
        }
        iter++;
    }
    return 0;
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

void Inventory::tansferAllFrom(Inventory* other) {
    for (auto item = items.end() - 1; item >= items.begin(); --item) {
        addItem(new Item((*item)->getDescriptor(), (*item)->getCount()));
        other->removeItem(*item);
    }
}

void Inventory::transferAllTo(Inventory* other) {
    for (auto item = items.end() - 1; item >= items.begin(); --item) {
        other->addItem(new Item((*item)->getDescriptor(), (*item)->getCount()));
        removeItem(*item);
    }
}
