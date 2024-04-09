#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include "card.hpp"
#include <map>

bool operator==(Card const &c1, Card const &c2)
{
    if (c1.kind == c2.kind && c1.value == c2.value)
    {
        return true;
    }
}


// oui je suis en roue libre, ce switch est trop douteux 🥸
int addValue(Card const &c)
{
    CardValue value = c.value;
    switch (value)
    {
    case CardValue::Two:
        return 2;
        break;
    case CardValue::Three:
        return 3;
        break;
    case CardValue::Four:
        return 4;
        break;
    case CardValue::Five:
        return 5;
        break;
    case CardValue::Six:
        return 6;
        break;
    case CardValue::Seven:
        return 7;
        break;
    case CardValue::Eight:
        return 8;
        break;
    case CardValue::Nine:
        return 9;
        break;
    case CardValue::Ten:
        return 10;
        break;
    case CardValue::Jack:
        return 11;
        break;
    case CardValue::Queen:
        return 12;
        break;
    case CardValue::King:
        return 13;
        break;
    case CardValue::Ace:
        return 14;
        break;
    default:
        return 0;
        break;
    }
}

int hashCard(Card const &c, size_t max)
{
    int hash = 0;
    int value = addValue(c);
    std::cout << "value: " << value << std::endl;
    
    return hash;
}