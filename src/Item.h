#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H

#include "ItemDescriptor.h"

class Item {

public:
    Item(ItemDescriptor* descriptor, int count);
    int getCount() const;
    void changeCount(int diff);
    void setCount(int count);
    const std::string toString() const;
    const std::string& getKeyword() const;
    const int getWeight() const;
    ItemDescriptor* getDescriptor() const;

private:
    ItemDescriptor* descriptor;
    int count;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
