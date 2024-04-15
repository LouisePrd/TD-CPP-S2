#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <map>
#include "card.hpp"

bool operator==(Card const &c1, Card const &c2)
{
    if (c1.kind == c2.kind && c1.value == c2.value)
    {
        return true;
    }
}

size_t Card::hash() const
{
    // Question 2
    //int valueInt = static_cast<int>(Card::value);
    //int kindInt = static_cast<int>(Card::kind);
    //std::string concat = std::to_string(valueInt) + std::to_string(kindInt);
    //size_t hash = stoi(concat);
    //std::cout << hash << std::endl;

    // Question 3
    size_t hash = 0;
    int valueInt = static_cast<int>(Card::value);
    int kindInt = static_cast<int>(Card::kind);
    hash = valueInt * 4 + kindInt;


    std::cout << hash << std::endl;

    return hash;
}