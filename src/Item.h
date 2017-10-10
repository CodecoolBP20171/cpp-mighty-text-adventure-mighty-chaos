#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H

#include "ItemDescriptor.h"

class Item {
public:
    Item(ItemDescriptor* descriptor, int count);
    int getCount() const;
    void changeCount(int diff);
    const std::string& getName() const;
    const std::string& getDecription() const;
    const std::string& getKeyword() const;
    const int getWeight() const;

private:
    ItemDescriptor* descriptor;
    int count;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
