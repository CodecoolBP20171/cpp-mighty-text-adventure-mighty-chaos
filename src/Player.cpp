#include <iostream>
#include "Player.h"

Player::Player(Room* position) : position(position) {}

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
    if (type == action::TAKE) {
        takeItem(activity);
        return;
    }
    if (type == action::DROP) {
        dropItem(activity);
        return;
    }
    if (type == action::INV) {
        std::cout << "\nYour inventory:" << std::endl;
        showInventory();
        return;
    }
}

void Player::dropItem(const Action* activity) {
    auto item = new Item(activity->getItemDescriptor(), activity->getAmount());
    auto taken = inventory.removeItem(item);
    item->setCount(taken);
    position->getInventory()->addItem(item);
}

void Player::takeItem(const Action* activity) {
    auto item = new Item(activity->getItemDescriptor(), activity->getAmount());
    auto taken = position->getInventory()->removeItem(item);
    item->setCount(taken);
    inventory.addItem(item);
}

void Player::movePlayer(const action& type) {
    if(inventory.getWeight() > 50){
        std::cout << "You have too much stuff you can't move." << std::endl;
        return;
    }
    for (auto conn : position->getConnections()) {
        if (conn->getDir() == (direction) type) {
            position = (Room*) conn->getRoom();
            break;
        }
    }
}

bool Player::isDirection(action act) {
    return act == action::WEST ||
           act == action::EAST ||
           act == action::NORTH ||
           act == action::SOUTH;
}
