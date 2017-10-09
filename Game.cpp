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
    auto playerPosition = player.getPosition();
    if (playerPosition == rooms[11]) return true;

    std::cout<<playerPosition->getArea()->getDescription()<<std::endl;

    for (auto conn : playerPosition->getConnections()) {
        std::cout<<conn->getDirStr()<<std::endl;
    }

    auto action = INVALID;
    do {
        action = getUserInput();
    } while (action == INVALID);

    for (auto conn : playerPosition->getConnections()) {
        if (conn->getDir() == action) {
            player.setPosition((Room*) conn->getRoom());
            break;
        }
    }

    return false;
}

direction Game::getUserInput() {
    auto in = std::string();
    getline(std::cin, in);
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    if ((in =="w")||(in =="west")) return WEST;
    if ((in =="n")||(in =="north")) return NORTH;
    if ((in =="s")||(in =="south")) return SOUTH;
    if ((in =="e")||(in =="east")) return EAST;
    return INVALID;
}
