#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>

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

    return 0;
}