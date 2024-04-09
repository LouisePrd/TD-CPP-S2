#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

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

    int hashCard(Card const &c, size_t max);
};

int addValue(Card const &c);
bool operator==(Card const &c1, Card const &c2);