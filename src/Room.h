#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H

#include "../Area.hpp"
#include "Connection.h"
#include <vector>

class Room {
public:
    Room(const Area* area);
    const Area* getArea() const;
    const vector<Connection*>& getConnections() const;
    void addConnection(direction dir, Room* room);
    const string &getDescription() const;
    const string &getDoor() const;

private:
    const Area* area;
    std::vector<Connection*> connections;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
