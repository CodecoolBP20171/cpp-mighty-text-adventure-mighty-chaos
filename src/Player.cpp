#include "Player.h"

Player::Player(Room* position) : position(position) {}

Room* Player::getPosition() const {
    return position;
}

void Player::setPosition(Room* position) {
    Player::position = position;
}

void Player::takeItem(Item* item) {
    inventory->addItem(item);
}

void Player::dropItem(Item* item) {
    inventory->removeItem(item);
}

void Player::showInventory() const {
    inventory->displayInventory();
}

void Player::act(action dir) {
    for (auto conn : position->getConnections()) {
        if (conn->getDir() == (direction) dir) {
            position = (Room*) conn->getRoom();
            return;
        }
    }
}
