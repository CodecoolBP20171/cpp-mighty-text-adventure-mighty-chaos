#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#include <string>

using namespace std;

class Area
{
public:
    Area(const string& description, const string& door) : description(description), door(door) {}

    const string &getDescription() const {
        return description;
    }

    const string &getDoor() const {
        return door;
    }

private:
    const string description;
    const string door;
};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
