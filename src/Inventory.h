#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {

public:
    Inventory();
    bool addItem(Item* item);
    int removeItem(const Item* item);
    int removeAnItem(std::string keyWord);
    bool checkItem(std::string keyWord);

    void displayInventory() const;

    int getWeight() const;

    void transferAllFrom(Inventory *other);
    void transferAllTo(Inventory* other);

    virtual ~Inventory();

private:
    std::vector<Item*> items;
    int weight;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVENTORY_H
