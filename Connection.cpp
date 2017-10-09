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
        case NORTH :
            return "N";
        case SOUTH :
            return "S";
        case WEST :
            return "W";
        case EAST :
            return "E";
    }
    return "INVALID";
}
