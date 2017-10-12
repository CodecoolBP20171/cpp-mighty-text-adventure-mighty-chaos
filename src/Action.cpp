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

void Action::Parse(const std::string& row, const std::vector<std::string>& kywrd) {
    if (row.empty()) {
        type = action::INVALID;
        return;
    }

    std::stringstream ss(row);
    std::string word;

    ss >> word;
    parseActionWord(word);
    if (isOneWordAction()) return;

    word.clear();

    ss >> word;
    if (word.empty()) { // no parameter provided where needed
        type = action::INVALID;
        return;
    }
    if (isTakeAllOrDropAll(word)) { // 'take all' or 'drop all'
        amount = 0;
        item = "all";
        return;
    }
    parseItemKwd(kywrd, word);
    if (item.empty()) { // no valid item keyword found
        type = action::INVALID;
        return;
    }
    if (type == action::INFO) return; // 'info <item>' action parsing done
    // parsing amount
    word.clear();
    ss >> word;
    if (word.empty()) { // default case (no amount given)
        amount = 1;
        return;
    }
    if (word == "all") amount = 0;
    else {
        try {
            amount = std::stoi(word);
        } catch (std::invalid_argument&) {
            type = action::INVALID;
        } catch (std::out_of_range&) {
            type = action::INVALID;
        }
    }
}

void Action::parseItemKwd(const std::vector<std::string>& kywrd, const std::string& word) {
    item.clear();
    for (auto& itemkwd : kywrd) {
        if (word == itemkwd) {
            item = word;
            break;
        }
    }
}

bool Action::isTakeAllOrDropAll(const std::string& word) const {
    return (type == action::TAKE || type == action::DROP) &&
           word == "all";
}

void Action::parseActionWord(const std::string& word) {
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
    } else {
        type = action::INVALID;
    }
}

bool Action::isOneWordAction() const {
    return type == action::NORTH ||
           type == action::SOUTH ||
           type == action::EAST ||
           type == action::WEST ||
           type == action::HELP ||
           type == action::INV ||
           type == action::INVALID;
}

ItemDescriptor* Action::getItemDescriptor() const {
    return itemDescriptor;
}

void Action::setItemDescriptor(ItemDescriptor* itemDescriptor) {
    Action::itemDescriptor = itemDescriptor;
}