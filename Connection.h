#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H

#include "Room.h"

enum direction {
    NORTH, SOUTH, WEST, EAST
};

class Connection {
public:
    Connection(direction dir, Room* room);
    direction getDir() const;
    Room* getRoom() const;

private:
    direction dir;
    Room* room;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H
