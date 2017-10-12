#include "Connection.h"

Connection::Connection(direction dir, void* room) : dir(dir), room(room) {}

direction Connection::getDir() const {
    return dir;
}

void* Connection::getRoom() const {
    return room;
}

std::string Connection::getDirStr() const {

    switch (dir) {
        case direction::NORTH :
            return "North";
        case direction::SOUTH :
            return "South";
        case direction::WEST :
            return "West";
        case direction::EAST :
            return "East";
    }
}
