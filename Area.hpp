#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#include <string>

using namespace std;

class Area
{
public:
    Area(const string& description) : description(description) {}

private:
    const string description;
};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
