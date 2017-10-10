#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Room.h"
#include "Inventory.h"

class Player {
public:
    Player(Room* position);
    Room* getPosition() const;
    void setPosition(Room* position);
    void takeItem(Item* item);
    void dropItem(Item* item);
    void showInventory() const;
    void act(action dir);

private:
    Room* position;
    Inventory* inventory;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
