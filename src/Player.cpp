#include <iostream>
#include "Player.h"

Player::Player(Room* position) : position(position), health(7), maxWeight(120) {}

Room* Player::getPosition() const {
    return position;
}

void Player::showInventory() const {
    inventory.displayInventory();
}

void Player::act(Action* activity) {
    auto type = activity->getType();
    if (isDirection(type)) {
        movePlayer(type);
        return;
    }
    switch (type) {
        case action::TAKE : {

            if (activity->getItem() == "all") {
                std::cout << "You take all the items." << std::endl;
                inventory.transferAllFrom(position->getInventory());
            } else {
                std::cout << "You take the " << activity->getItem() << std::endl;
                takeItem(activity);
            }
            return;
        }

        case action::DROP : {

            if (activity->getItem() == "all") {
                std::cout << "You drop all your items." << std::endl;
                inventory.transferAllTo(position->getInventory());
            } else {
                std::cout << "You drop your " << activity->getItem() << std::endl;
                dropItem(activity);
            }
            return;
        }

        case action::INV : {

            std::cout << "\nYour inventory:" << std::endl;
            showInventory();
            return;
        }

        case action::USE : {

            if (activity->getItem() == "stun") {
                if (inventory.checkItem("stun")) {
                    inventory.removeAnItem("stun");
                    health--;
                    std::cout << "You use your stun potion to knock yourself out.\n"
                            "You lost 1 health. You still have "
                              << health
                              << " health."
                              << std::endl;
                    return;
                }
            }
            std::cout << "You can't use this yet." << std::endl;
            return;
        }
    }
}

void Player::dropItem(const Action* activity) {
    auto item = new Item(activity->getItemDescriptor(), activity->getAmount());
    auto taken = inventory.removeItem(item);
    item->setCount(taken);
    if(!position->getInventory()->addItem(item)) delete item;
}

void Player::takeItem(const Action* activity) {
    auto item = new Item(activity->getItemDescriptor(), activity->getAmount());
    auto taken = position->getInventory()->removeItem(item);
    item->setCount(taken);
    if(!inventory.addItem(item)) delete item;
}

void Player::movePlayer(const action& type) {
    if(inventory.getWeight() > 120){
        std::cout << "You have too much stuff you can't move. Try go below "
                  << maxWeight
                  << "!"
                  << std::endl;
        return;
    }
    for (auto conn : position->getConnections()) {
        if (conn->getDir() == (direction) type) {
            if (((Room*) conn->getRoom())->isRoomOpen()) {
                position = (Room*) conn->getRoom();
                return;
            } else if (inventory.checkItem("key")) {
                inventory.removeAnItem("key");
                std::cout << "You use your key to open the door." <<std::endl;
                position = (Room*) conn->getRoom();
                return;
            }
            std::cout << "You can't open the door." <<std::endl;
            return;
        }
    }
    std::cout << "BAAANG! You hit the wall. Try a door." << std::endl;
}

bool Player::isDirection(action act) {
    return act == action::WEST ||
           act == action::EAST ||
           act == action::NORTH ||
           act == action::SOUTH;
}

int Player::getHealth() const {
    return health;
}

