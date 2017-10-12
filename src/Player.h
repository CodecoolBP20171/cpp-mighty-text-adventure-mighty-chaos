#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Room.h"
#include "Inventory.h"
#include "Action.h"

class Player {
public:
    explicit Player(Room* position);
    Room* getPosition() const;
    void showInventory() const;
    void act(Action* activity);
    int getHealth() const;

private:
    Room* position;
    Inventory inventory;
    int health;
    bool isDirection(action act);
    void movePlayer(const action& type);
    void takeItem(const Action* activity);
    void dropItem(const Action* activity);
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
