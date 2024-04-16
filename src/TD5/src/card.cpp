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
        return true;
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
    int valueInt = static_cast<int>(Card::value);
    int kindInt = static_cast<int>(Card::kind);
    size_t hash = valueInt * 4 + kindInt;
    return hash;
}

std::string card_name(Card const& card) {
    std::string name {};
    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}