#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H

#include "../Area.hpp"
#include "Connection.h"
#include "Inventory.h"
#include <vector>

class Room {
public:
    explicit Room(const Area* area);
    const vector<Connection*>& getConnections() const;
    Inventory* getInventory() const;
    void addConnection(direction dir, Room* room);
    const string &getDescription() const;
    const string &getDoor() const;
    virtual ~Room();

private:
    const Area* area;
    std::vector<Connection*> connections;
    Inventory* inventory;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
