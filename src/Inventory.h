#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    Inventory();
    void addItem(Item* item);
    void removeItem(Item* item);
    void displayInventory() const;

private:
    std::vector<Item*> items;
    int weight;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
