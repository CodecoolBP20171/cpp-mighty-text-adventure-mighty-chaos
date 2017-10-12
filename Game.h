#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include <algorithm>
#include "Area.hpp"
#include "src/Room.h"
#include "src/Player.h"
#include "src/ItemDescriptor.h"
#include "src/Action.h"

using namespace std;

class Game {
public:
    Game();
    virtual ~Game();

    void init();
    void run();

private:
    vector<Area> areas; // areas has only non-changeable information
    vector<ItemDescriptor> items; // items has only non-changeable information
    vector<string> itemKeywords;
    vector<Room*> rooms;
    Player player;

    void loadAreas();
    bool step();
    void buildRooms();
    void getUserInput(Action* a);
    void showHelp();
    void loadItems();
    void placeItems();
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
