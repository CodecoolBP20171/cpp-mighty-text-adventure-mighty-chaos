#include "Room.h"

Room::Room(Area* area) : area(area) {}

Area* Room::getArea() const {
    return area;
}

const vector<Connection*>& Room::getConnections() const {
    return connections;
}

void Room::addConnection(direction dir, Room* room) {
    Connection* con = new Connection(dir, room);
    Room::connections.emplace_back(con);
}
