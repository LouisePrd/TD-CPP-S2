#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include "card.hpp"

size_t folding_string_hash(std::string const &s, size_t max)
{
    std::unordered_map<char, float> mapChar;
    size_t hash = 0;

    for (char c : s)
    {
        float ASCII = (float)c;
        mapChar[c] = ASCII;
        hash += ASCII;
    }

    return hash % max;
}

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    std::unordered_map<char, float> mapCharOrdered;
    size_t hash = 0;
    for (char c : s)
    {
        int pos = mapCharOrdered.size();
        float ASCII = (float)c;
        mapCharOrdered[c] = ASCII;
        hash += ASCII * pos;
    }

    return hash % max;
}

size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m)
{
    int power = 1;
    size_t hash = 0;

    for (unsigned long i = 0; i < s.size(); i++)
    {
        float ASCII = (float)s[i]; // s[i]
        for (unsigned long j = 0; j < i; j++)
        {
            power *= p; // p^i
        }
        hash += (ASCII * power); // s[i]× p^i
        hash = hash % m;         // s[i]× p^i mod m
    }

    return hash;
}

// ROBOTS

std::string random_name(size_t size)
{
    std::string name{""};
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        std::string robotName{random_name(2)}; // random name
        // random cost
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> robots_fixes_map{};

    for (unsigned long i = 0; i < robots_fixes.size(); i++)
    {
        auto nameRobot = robots_fixes_map.find(robots_fixes[i].first); // On cherche s'il existe deja
        if (nameRobot != robots_fixes_map.end())
        {
            robots_fixes_map[robots_fixes[i].first].push_back(robots_fixes[i].second);
            /*std::cout << "Robot :" << robots_fixes[i].first << std::endl;
            std::cout << "Réparations : ";
            for (unsigned long j = 0; j < robots_fixes_map[robots_fixes[i].first].size(); j++)
            {
                std::cout << robots_fixes_map[robots_fixes[i].first][j] << ", ";
            }
            std::cout << std::endl;*/
        }
        else
        {
            robots_fixes_map[robots_fixes[i].first] = {robots_fixes[i].second};
        }
    }

    return robots_fixes_map;
}

float sumReparation(std::unordered_map<std::string, std::vector<float>> robots_fixes_map, std::string robotName)
{
    float sum = 0;
    for (unsigned long i = 0; i < robots_fixes_map[robotName].size(); i++)
    {
        sum += robots_fixes_map[robotName][i];
    }
    return sum;
}

int main()
{
    // Exercice 1 (fonction de hachage)
    // Question 1
    folding_string_hash("Hello world", 1024);
    // Question 2
    folding_string_ordered_hash("abc", 1024);
    folding_string_ordered_hash("cab", 1024);
    // Question 3
    polynomial_rolling_hash("abc", 31, 1024);
    polynomial_rolling_hash("cab", 31, 1024);

    // Exercice 2 (Réparation de Robots)
    std::unordered_map<std::string, std::vector<float>> robots_fixes = robots_fixes_map(get_robots_fix(676));
    std::cout << "Réparations du robot YM : " << sumReparation(robots_fixes, "YM") << std::endl; // Robot YM trouve 509.626 pour réparations 423.845, 17.5173, 68.2637,

    // Exercice 3 (hash sur une structure)
    Card c1{CardKind::Heart, CardValue::Ace};
    c1.hashCard(c1, 1024);
    return 0;
}