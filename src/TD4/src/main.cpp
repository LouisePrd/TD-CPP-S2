#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>

void beginAndEnd(std::vector<int> randoms)
{
    std::vector<int>::iterator end_iterator{randoms.end()};
    std::cout << "Affichage des randoms : ";
    for (std::vector<int>::iterator it{randoms.begin()}; it != end_iterator; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void findAndCount(std::vector<int> randoms)
{
    std::string saisie;
    std::cout << "Votre saisie : ";
    std::getline(std::cin, saisie);

    // Utilisation de l'algo find
    auto it2{std::find(randoms.begin(), randoms.end(), stoi(saisie))};
    if (it2 != randoms.end())
        std::cout << "Trouvé :)" << std::endl;
    else
        std::cout << "Pas trouvé :(" << std::endl;

    // Utilisation de count
    const int num_items = std::count(randoms.cbegin(), randoms.cend(), stoi(saisie));
    std::cout << "number: " << saisie << ", count: " << num_items << '\n';
}

void sortMethod(std::vector<int> randoms)
{
    std::sort(randoms.begin(), randoms.end());
    std::cout << "Tri des randoms : ";
    for (std::vector<int>::size_type i = 0; i < randoms.size(); i++)
    {
        std::cout << randoms[i] << " ";
    }
    std::cout << std::endl;
}

void accumulation(std::vector<int> randoms)
{
    int sum{std::accumulate(randoms.begin(), randoms.end(), 0, [](int acc, int current_element)
                            { return acc + current_element; })};
    std::cout << "Somme des randoms : " << sum << std::endl;
}

auto const is_space = [](char letter)
{
    return letter == ' ';
};

int findFirstWord(std::string const &phrase)
{
    int nbLettres{0};

    auto it{std::find(phrase.begin(), phrase.end(), ' ')};
    if (it != phrase.end())
    {
        nbLettres = std::distance(phrase.begin(), it);
    }
    // ou avec find if :
    /*auto it{std::find_if(phrase.begin(), phrase.end(), is_space)};
    if (it != phrase.end())
    {
        nbLettres = std::distance(phrase.begin(), it);
    }*/

    return nbLettres;
}

std::vector<std::string> split_string(std::string const& str)
{
    std::vector<std::string> mots;
    int itCourant{0};

    auto it{std::find(str.begin(), str.end(), ' ')};
    while (it != str.end())
    {
        std::string motCourant(str.begin() + itCourant, it);
        itCourant = std::distance(str.begin(), it);
        it = std::find(it + 1, str.end(), ' ');
        mots.push_back(motCourant);
        if (it == str.end())
        {
            std::string motCourant(str.begin() + itCourant, str.end());
            mots.push_back(motCourant);
        }
    }

    return mots;
}

int main()
{
    // Exercice 1 (Vector and Algorithm)
    /*std::vector<int> randoms;
    std::cout << "Generation de randoms : ";
    for (int i = 0; i < 10; i++)
    {
        randoms.push_back(rand() % 100);
        std::cout << randoms[i] << " ";
    }
    std::cout << std::endl;
    beginAndEnd(randoms);
    findAndCount(randoms);
    sortMethod(randoms);
    accumulation(randoms);*/

    // Exercice 2 (String)
    std::string phrase{"je suis une phrase"};
    findFirstWord(phrase);
    split_string(phrase);

    //Exercice 3 (Palindrome)

    return 0;
}