#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {

public:
    Inventory();
    bool addItem(Item* item);
    int removeItem(const Item* item);
    void displayInventory() const;
    int getWeight() const;

    void tansferAllFrom(Inventory* other);
    void transferAllTo(Inventory* other);
private:
    std::vector<Item*> items;
    int weight;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
