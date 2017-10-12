#include "ItemDescriptor.h"

ItemDescriptor::ItemDescriptor(const std::string& name, const std::string& description, const std::string& keyword, const int weight) : name(
        name), description(description), keyword(keyword), weight(weight) {}

const std::string& ItemDescriptor::getName() const {
    return name;
}

const std::string& ItemDescriptor::getDescription() const {
    return description;
}

const std::string& ItemDescriptor::getKeyword() const {
    return keyword;
}

const int ItemDescriptor::getWeight() const {
    return weight;
}
