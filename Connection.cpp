#include "Connection.h"

Connection::Connection(direction dir, Room* room) : dir(dir), room(room) {}

direction Connection::getDir() const {
    return dir;
}

Room* Connection::getRoom() const {
    return room;
}
