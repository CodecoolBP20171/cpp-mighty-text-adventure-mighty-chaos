#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESC_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESC_H

#include <string>

class ItemDescriptor {
public:
    ItemDescriptor(const std::string& name, const std::string& decription, const std::string& keyword, const int weight);
    const std::string& getName() const;
    const std::string& getDecription() const;
    const std::string& getKeyword() const;
    const int getWeight() const;

private:
    const std::string name;
    const std::string decription;
    const std::string keyword;
    const int weight;

};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESC_H
