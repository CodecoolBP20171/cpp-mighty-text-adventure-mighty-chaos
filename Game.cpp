#include <iostream>
#include "Game.h"

void Game::init() {
    loadAreas();
    player = Player(rooms[0]);
}

void Game::loadAreas() {
    areas.emplace_back("start room");
    areas.emplace_back("room 1");
    areas.emplace_back("room 2");
    areas.emplace_back("room 3");
    areas.emplace_back("room 4");
    areas.emplace_back("room 5");
    areas.emplace_back("end room");
    buildRooms();
}

void Game::buildRooms() const {
    rooms[0] = new Room(&areas[0]);
    rooms[1] = new Room(&areas[1]);
    rooms[2] = new Room(&areas[3]);
    rooms[3] = new Room(&areas[5]);
    rooms[4] = new Room(&areas[4]);
    rooms[5] = new Room(&areas[2]);
    rooms[6] = new Room(&areas[3]);
    rooms[7] = new Room(&areas[1]);
    rooms[8] = new Room(&areas[5]);
    rooms[9] = new Room(&areas[2]);
    rooms[10] = new Room(&areas[4]);
    rooms[11] = new Room(&areas[5]);
    rooms[12] = new Room(&areas[7]);
    rooms[0]->addConnection(EAST, rooms[1]);
    rooms[1]->addConnection(WEST, rooms[0]);
    rooms[1]->addConnection(NORTH, rooms[2]);
    rooms[1]->addConnection(EAST, rooms[9]);
    rooms[2]->addConnection(NORTH, rooms[3]);
    rooms[2]->addConnection(SOUTH, rooms[1]);
    rooms[3]->addConnection(EAST, rooms[4]);
    rooms[3]->addConnection(SOUTH, rooms[2]);
    rooms[4]->addConnection(WEST, rooms[3]);
    rooms[4]->addConnection(NORTH, rooms[5]);
    rooms[4]->addConnection(EAST, rooms[6]);
    rooms[5]->addConnection(SOUTH, rooms[4]);
    rooms[6]->addConnection(WEST, rooms[4]);
    rooms[6]->addConnection(SOUTH, rooms[7]);
    rooms[7]->addConnection(NORTH, rooms[6]);
    rooms[7]->addConnection(SOUTH, rooms[8]);
    rooms[8]->addConnection(WEST, rooms[9]);
    rooms[8]->addConnection(NORTH, rooms[7]);
    rooms[9]->addConnection(WEST, rooms[1]);
    rooms[9]->addConnection(SOUTH, rooms[10]);
    rooms[9]->addConnection(EAST, rooms[8]);
    rooms[10]->addConnection(NORTH, rooms[9]);
    rooms[10]->addConnection(SOUTH, rooms[11]);
    rooms[11]->addConnection(NORTH, rooms[10]);
}

void Game::run() {
    while (!step()) {}
}

bool Game::step() {
    if (player.getPosition() == rooms[11]) return true;
    auto validInput = false;
    auto action;
    do {
        action = getUserInput(validInput);
    } while (!validInput)
    return false;
}

direction Game::getUserInput(bool& validInput) {
    auto in = std::string();
    getline(std::cin, in);
    std::transform(in.begin(), in.end(), in.begin(), std::tolower);
    if ("");
    return WEST;
}
