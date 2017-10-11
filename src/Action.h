//
// Created by jeannie on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H

#include <string>
#include <vector>


enum class action {
    NORTH, SOUTH, WEST, EAST, INVALID, HELP, TAKE, DROP, INV, INFO
};

class Action {

public:
    void Parse(std::string& row, const std::vector<std::string>& kywrd);

    action getType() const;
    std::string getItem() const;
    int getAmount()const;

private:
    action type;
    std::string item;
    int amount;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ACTION_H
