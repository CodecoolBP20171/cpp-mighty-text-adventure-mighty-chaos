#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include <algorithm>
#include "Area.hpp"
#include "Room.h"
#include "Player.h"

using namespace std;

class Game {
public:
    Game();

    void init();
    void run();

private:
    vector<Area> areas; // areas has only non-changeable information
    vector<Room*> rooms;
    Player player;

    void loadAreas();
    bool step();
    void buildRooms();
    direction getUserInput();
    void showHelp();
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
