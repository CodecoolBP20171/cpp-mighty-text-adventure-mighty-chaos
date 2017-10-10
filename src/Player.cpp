#include "Player.h"

Player::Player(Room* position) : position(position) {}

Room* Player::getPosition() const {
    return position;
}

void Player::setPosition(Room* position) {
    Player::position = position;
}
