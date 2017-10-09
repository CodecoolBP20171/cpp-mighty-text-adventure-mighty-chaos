#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Room.h"

class Player {
public:
    Player(Room* position);
    Room* getPosition() const;
    void setPosition(Room* position);

private:
    Room* position;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
