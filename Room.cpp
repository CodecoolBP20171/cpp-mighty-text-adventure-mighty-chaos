#include "Room.h"

Room::Room(const Area* area) : area(area) {}

const Area* Room::getArea() const {
    return area;
}

const vector<Connection*>& Room::getConnections() const {
    return connections;
}

void Room::addConnection(direction dir, Room* room) {
    auto con = new Connection(dir, room);
    Room::connections.emplace_back(con);
}
