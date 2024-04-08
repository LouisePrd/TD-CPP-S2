#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

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

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
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
        hash += (ASCII * power);  // s[i]× p^i
        hash = hash % m; // s[i]× p^i mod m
    }

    return hash;
}


// ROBOT

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> robots_fixes_map {};
    return robots_fixes_map;
}

int main()
{
    // Exercice 1 (fonction de hachage)
    // Question 1
    std::string str = "Hello world";
    folding_string_hash(str, 1024);
    // Question 2
    folding_string_ordered_hash("abc", 1024);
    folding_string_ordered_hash("cab", 1024);
    // Question 3
    polynomial_rolling_hash("abc", 31, 1024);
    polynomial_rolling_hash("cab", 31, 1024);

    // Exercice 2 (Réparation de Robots)
    std::cout << "Test nom robot : " << random_name(2) << std::endl;
    std::vector<std::pair<std::string, float>> robots_fix = get_robots_fix(10);
    std::unordered_map<std::string, std::vector<float>> robots_fixes = robots_fixes_map(robots_fix);

    return 0;
}