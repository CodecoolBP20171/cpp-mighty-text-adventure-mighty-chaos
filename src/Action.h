//
// Created by jeannie on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H

#include <string>
#include <vector>
#include "ItemDescriptor.h"

enum class action {
    NORTH, SOUTH, WEST, EAST, INVALID, HELP, TAKE, DROP, INV, INFO
};

class Action {

public:
    void Parse(const std::string& row, const std::vector<std::string>& kywrd);

    action getType() const;
    std::string getItem() const;
    int getAmount() const;
    ItemDescriptor* getItemDescriptor() const;
    void setItemDescriptor(ItemDescriptor* itemDescriptor);

private:
    action type;
    std::string item;
    int amount;
    ItemDescriptor* itemDescriptor;
    bool isOneWordAction() const;
    void parseActionWord(const std::string& word);
    bool isTakeAllOrDropAll(const std::string& word) const;
    void parseItemKwd(const std::vector<std::string>& kywrd, const std::string& word);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H
