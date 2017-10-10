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
            return "N";
        case direction::SOUTH :
            return "S";
        case direction::WEST :
            return "W";
        case direction::EAST :
            return "E";
    }
    return "INV";
}
