#include <iostream>
#include "Game.h"

void Game::init() {
    loadAreas();
    player = Player(rooms[0]);
}

Game::Game() : player(nullptr) {}

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

void Game::buildRooms() {

    rooms.emplace_back(new Room(&areas[0]));
    rooms.emplace_back(new Room(&areas[1]));
    rooms.emplace_back(new Room(&areas[3]));
    rooms.emplace_back(new Room(&areas[5]));
    rooms.emplace_back(new Room(&areas[4]));
    rooms.emplace_back(new Room(&areas[2]));
    rooms.emplace_back(new Room(&areas[3]));
    rooms.emplace_back(new Room(&areas[1]));
    rooms.emplace_back(new Room(&areas[5]));
    rooms.emplace_back(new Room(&areas[2]));
    rooms.emplace_back(new Room(&areas[4]));
    rooms.emplace_back(new Room(&areas[5]));
    rooms.emplace_back(new Room(&areas[7]));

    rooms[0]->addConnection(direction::EAST, rooms[1]);
    rooms[1]->addConnection(direction::WEST, rooms[0]);
    rooms[1]->addConnection(direction::NORTH, rooms[2]);
    rooms[1]->addConnection(direction::EAST, rooms[9]);
    rooms[2]->addConnection(direction::NORTH, rooms[3]);
    rooms[2]->addConnection(direction::SOUTH, rooms[1]);
    rooms[3]->addConnection(direction::EAST, rooms[4]);
    rooms[3]->addConnection(direction::SOUTH, rooms[2]);
    rooms[4]->addConnection(direction::WEST, rooms[3]);
    rooms[4]->addConnection(direction::NORTH, rooms[5]);
    rooms[4]->addConnection(direction::EAST, rooms[6]);
    rooms[5]->addConnection(direction::SOUTH, rooms[4]);
    rooms[6]->addConnection(direction::WEST, rooms[4]);
    rooms[6]->addConnection(direction::SOUTH, rooms[7]);
    rooms[7]->addConnection(direction::NORTH, rooms[6]);
    rooms[7]->addConnection(direction::SOUTH, rooms[8]);
    rooms[8]->addConnection(direction::WEST, rooms[9]);
    rooms[8]->addConnection(direction::NORTH, rooms[7]);
    rooms[9]->addConnection(direction::WEST, rooms[1]);
    rooms[9]->addConnection(direction::SOUTH, rooms[10]);
    rooms[9]->addConnection(direction::EAST, rooms[8]);
    rooms[10]->addConnection(direction::NORTH, rooms[9]);
    rooms[10]->addConnection(direction::SOUTH, rooms[11]);
    rooms[11]->addConnection(direction::NORTH, rooms[10]);
}

void Game::run() {
    while (!step()) {}
}

bool Game::step() {
    auto playerPosition = player.getPosition();
    if (playerPosition == rooms[11]) return true;

    std::cout << playerPosition->getArea()->getDescription() << std::endl;

    for (auto conn : playerPosition->getConnections()) {
        std::cout << conn->getDirStr() << std::endl;
    }

    action act;
    do {
        act = getUserInput();
        if (act == action::HELP) showHelp();
    } while (act == action::INVALID || act == action::HELP);

    for (auto conn : playerPosition->getConnections()) {
        if (conn->getDir() == (direction) act) {
            player.setPosition((Room*) conn->getRoom());
            break;
        }
    }

    return false;
}

action Game::getUserInput() {
    auto in = std::string();
    getline(std::cin, in);
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    if (in == "w" || in == "west") return action::WEST;
    if (in == "n" || in == "north") return action::NORTH;
    if (in == "s" || in == "south") return action::SOUTH;
    if (in == "e" || in == "east") return action::EAST;
    if (in == "h" || in == "help") return action::HELP;
    return action::INVALID;
}

void Game::showHelp() {
    std::cout << "Next room: w/n/s/e, help: h" << std::endl;
}
