//
// Created by jeannie on 2017.10.11..
//

#include <sstream>
#include <iostream>
#include "Action.h"

action Action::getType() const {
    return type;
}

std::string Action::getItem() const {
    return item;
}

int Action::getAmount() const {
    return amount;
}

void Action::Parse(std::string &row, const std::vector<std::string>& kywrd) {
    std::stringstream ss(row);
    std::string word;
    ss >> word;

    if (word == "w" || word == "west") {
        type = action::WEST;
    } else if (word == "n" || word == "north") {
        type = action::NORTH;
    } else if (word == "s" || word == "south") {
        type = action::SOUTH;
    } else if (word == "e" || word == "east") {
        type = action::EAST;
    } else if (word == "h" || word == "help") {
        type = action::HELP;
    } else if (word == "t" || word == "take") {
        type = action::TAKE;
    } else if (word == "d" || word == "drop") {
        type = action::DROP;
    } else if (word == "i" || word == "inv") {
        type = action::INV;
    } else if (word == "info") {
        type = action::INFO;
    } else type = action ::INVALID;

    ss >> word;
    if (type == action::TAKE || type == action::DROP) {

        if (word == "all") {
            amount = 0;
            item = "all";
            return;
        }
    }

    if (type == action::TAKE || type == action::DROP || type == action::INFO) {
        item = "";
        for (std::string itemkwd : kywrd) {
            if (word == itemkwd) {
                item = word;
                break;
            }
        }
        if (item == "") {
            type = action::INVALID;
            return;

        } else if (type != action::INFO) {
            word = "";
            ss >> word;

            if (word == "all") {
                amount = 0;
            } else {

                if (word == "") {
                    amount = 1;
                    return;
                }

                try {
                    amount = std::stoi(word);
                } catch (std::invalid_argument) {
                    type = action ::INVALID;
                } catch (std::out_of_range) {
                    type = action ::INVALID;
                }
            }
        }
    }
    return;
}

ItemDescriptor* Action::getItemDescriptor() const {
    return itemDescriptor;
}

void Action::setItemDescriptor(ItemDescriptor* itemDescriptor) {
    Action::itemDescriptor = itemDescriptor;
}
