#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H

#include <string>

enum class direction {
    NORTH, SOUTH, WEST, EAST
};

enum class action {
    NORTH, SOUTH, WEST, EAST, INVALID, HELP
};

class Connection {

public:
    Connection(direction dir, void* room);
    direction getDir() const;
    std::string getDirStr() const;
    void* getRoom() const;

private:
    direction dir;
    void* room;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_CONNECTION_H
