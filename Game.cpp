#include <iostream>
#include "Game.h"

void Game::init() {
    loadAreas();
    loadItems();
    player = Player(rooms[0]);
}

Game::Game() : player(nullptr) {}

void Game::loadAreas() {
    areas.emplace_back(
            "From the outside this house looks impressive.\nIt has been built with wood covered in render and "
                    "has oak wooden decorations.\nSmall, rounded windows let in plenty of light and have been "
                    "added to the house in a mostly symmetric way.",
            "an iron-reinforced wide framed and paneled wooden double door crafted of poplar that is stained "
                    "a vibrant color.");

    areas.emplace_back("This large, rectangular bedroom has matching wooden furniture.\nThe floor is wood and the walls"
                               " are textured and painted. Light is provided by ceiling lights.\nThe room is done in a "
                               "bird theme in warm bright colors and overall has a futuristic look.",
                       "a faded and aged wide battened and ledged wooden door crafted of pine that bears a narrow "
                               "iron-barred window.");

    areas.emplace_back("This spacious, square kitchen has tile counters and a sink with metal fixtures.\nThe floor is "
                               "stone and the walls are tiled.\nLight is provided by wall lamps and a ceiling light.\n"
                               "The room is done in stormy colors and overall has a clean look",
                       "an pinnacle-arched raised panel wooden door crafted of walnut that is carved with floral accents.");

    areas.emplace_back("This cramped, L-shaped office has matching wooden and metal furniture.\nThe floor is carpeted "
                               "and the walls are painted and decorated with a wallpaper border.\nLight is provided by "
                               "wall and floor lamps. The room has a clean look.",
                       "a cracked and crumbling arched solid stone double door carved from limestone that is covered "
                               "with dried blood splatter.");

    areas.emplace_back("This large bathroom has a shower and sink with porcelain fixtures.\nThe floor is stone and the "
                               "walls are tiled. Light is provided by ceiling lights.\nThe room is done in dark muted "
                               "colors and overall has a cluttered look.",
                       "a chipped and cracked wide solid stone door carved from sandstone with a rough and natural face.");

    areas.emplace_back("This small, square dining room/living room combo has matching wooden and metal furniture.\n"
                               "The dining seating is cushionless. The floor is tiled and the walls are papered.\n"
                               "Light is provided by wall lamps and a ceiling light.",
                       "a faded and aged short battened and ledged wooden double door crafted of maple that is seared "
                               "with arcane runes.");

    areas.emplace_back("This cramped, corridor leads to the exit. It has mismatched plastic furniture.\n"
                               "The floor is wood and the walls are painted and decorated with a wallpaper border.\n"
                               "Light is provided by ceiling lights. The room looks extraterrestrial.",
                       "a stout and sturdy wide flush-framed metal door forged of iron that is edged in intricate gilding.");
    buildRooms();
}

void Game::buildRooms() {

    rooms.emplace_back(new Room(&areas[0]));
    rooms.emplace_back(new Room(&areas[1]));
    rooms.emplace_back(new Room(&areas[3]));
    rooms.emplace_back(new Room(&areas[5]));
    rooms.emplace_back(new Room(&areas[4]));
    rooms.emplace_back(new Room(&areas[2]));
    rooms.emplace_back(new Room(&areas[3]));
    rooms.emplace_back(new Room(&areas[1]));
    rooms.emplace_back(new Room(&areas[5]));
    rooms.emplace_back(new Room(&areas[2]));
    rooms.emplace_back(new Room(&areas[4]));
    rooms.emplace_back(new Room(&areas[6]));

    rooms[0]->addConnection(direction::EAST, rooms[1]);
    rooms[1]->addConnection(direction::WEST, rooms[0]);
    rooms[1]->addConnection(direction::NORTH, rooms[2]);
    rooms[1]->addConnection(direction::EAST, rooms[9]);
    rooms[2]->addConnection(direction::NORTH, rooms[3]);
    rooms[2]->addConnection(direction::SOUTH, rooms[1]);
    rooms[3]->addConnection(direction::EAST, rooms[4]);
    rooms[3]->addConnection(direction::SOUTH, rooms[2]);
    rooms[4]->addConnection(direction::WEST, rooms[3]);
    rooms[4]->addConnection(direction::NORTH, rooms[5]);
    rooms[4]->addConnection(direction::EAST, rooms[6]);
    rooms[5]->addConnection(direction::SOUTH, rooms[4]);
    rooms[6]->addConnection(direction::WEST, rooms[4]);
    rooms[6]->addConnection(direction::SOUTH, rooms[7]);
    rooms[7]->addConnection(direction::NORTH, rooms[6]);
    rooms[7]->addConnection(direction::SOUTH, rooms[8]);
    rooms[8]->addConnection(direction::WEST, rooms[9]);
    rooms[8]->addConnection(direction::NORTH, rooms[7]);
    rooms[9]->addConnection(direction::WEST, rooms[1]);
    rooms[9]->addConnection(direction::SOUTH, rooms[10]);
    rooms[9]->addConnection(direction::EAST, rooms[8]);
    rooms[10]->addConnection(direction::NORTH, rooms[9]);
    rooms[10]->addConnection(direction::SOUTH, rooms[11]);
}

void Game::loadItems() {
    //name, decription, keyword, weight

    items.emplace_back("Chaos Creamy Meal",
                       "This delicious, tasty meal fully restore your HP",
                       "food", 1);

    items.emplace_back("Thunder Steel Katana",
                       "A thin, smooth blade made of adamantium is held by a grip wrapped in dull crocodile leather.\n"
                               "This weapon is the ideal choice to turn your enemies into Swiss cheese.\n"
                               "The blade has a small, curled cross-guard with a jeweled lion head on each side,\n"
                               "this weapon was clearly a custom order, probably by an important figure.\n"
                               "A wide pommel is decorated with gilded linings, no expense is spared for this gorgeous weapon.\n"
                               "The blade itself is fairly simple, but the blade will surely be decorated in battle.",
                       "sword", 3);

    items.emplace_back("Insane Heartseeker Battle Axe",
                       "A large, sharp, dual-edged blade axe made of copper is held by a grip wrapped in sapphire blue boar hide\n"
                               "This is the ideal weapon if you're looking to slice, dice, stab and jab your enemies.\n"
                               "The blade itself is fairly simple. No decorations of any sorts are on it, an everyday weapon.",
                       "axe", 7);

    items.emplace_back("Key",
                       "A key.",
                       "key", 0);

    items.emplace_back("Potion of Daze",
                       "A potion\nThis potion stuns monsters, allows you to escape.",
                       "stun", 0);

    items.emplace_back("Light Wraps of Binding Warlords",
                       "This is a set of leather armor.\nIt covers everything from the neck down and ending at the groin,\n"
                               "It has a coif with two small horns. The breastplate is made from many v-shaped layers of leather and fur.\n"
                               "The legs are protected by leather greaves. Thin leather pants are worn beneath this all.",
                       "armor", 3);

    items.emplace_back("Heavy Armor of Broken Misery",
                       "This is a set of heavy armor.\nIt is made from many layers of squared metal sheets.\n"
                               "It has a squared helm with half a face guard shaped like the eyes of an angel.\n"
                               "The breastplate has a metal, mohawk-like ornament with a row of feathers inserted into it.\n"
                               "The legs are covered by pointed, half covering cuisses.",
                       "harmor", 7);

    items.emplace_back("Crying Heavy Shield",
                       "This sturdy rounded oval shield, made from ebonsteel, offers heavy duty protection.\n"
                               "This shield was forged by abyss dwarves in a cryo workshop.\n"
                               "The shield's edges are enhanced with metal plating and have been decorated\n"
                               "with small repeated symbols. Its center is embellished with metalwork wings.",
                       "shield", 5);
}

void Game::run() {
    while (!step()) {}
}

bool Game::step() {
    auto playerPosition = player.getPosition();

    std::cout << std::endl << playerPosition->getArea()->getDescription() << std::endl << std::endl;

    for (auto conn : playerPosition->getConnections()) {
        std::cout << "To the " << conn->getDirStr() << " is ";
        std::cout << ((Room*) (conn->getRoom()))->getArea()->getDoor() << std::endl;
    }
    if (playerPosition == rooms[11]) {

        std::cout << "To the South is " << rooms[0]->getArea()->getDoor() << std::endl;
        std::cout << "\nYou head out the door.\n\nSo long and thanks for all the fish!\n\n";

        return true;
    }

    action act;
    do {
        act = getUserInput();
        if (act == action::HELP) showHelp();
        if (act == action::INVALID) std::cout << "Whaat?!";
    } while (act == action::INVALID || act == action::HELP);

    for (auto conn : playerPosition->getConnections()) {
        if (conn->getDir() == (direction) act) {
            player.setPosition((Room*) conn->getRoom());
            break;
        }
    }

    return false;
}

action Game::getUserInput() {
    auto in = std::string();
    std::cout << "\nWhat do you do? ";
    getline(std::cin, in);
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    if (in == "w" || in == "west") return action::WEST;
    if (in == "n" || in == "north") return action::NORTH;
    if (in == "s" || in == "south") return action::SOUTH;
    if (in == "e" || in == "east") return action::EAST;
    if (in == "h" || in == "help") return action::HELP;
    return action::INVALID;
}

void Game::showHelp() {
    std::cout << "Next room: w/n/s/e, help: h" << std::endl;
}

