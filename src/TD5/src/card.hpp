#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <map>


enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;
    
    size_t hash() const;
};

bool operator==(Card const &c1, Card const &c2);
std::vector<Card> get_cards(size_t const size);