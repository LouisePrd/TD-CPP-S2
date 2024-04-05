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

std::vector<std::string> split_string(std::string const &str)
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

bool palindrome(std::string const &str)
{
    // std::string::const_iterator begin_iterator { str.cbegin() };
    auto begin_iterator{str.begin()};
    auto end_iterator{str.end()};

    for (unsigned int i = 0; i < str.size() / 2; i++)
    {
        end_iterator--;
        if (*(begin_iterator) != *(end_iterator))
        {
            return false;
        }
        begin_iterator++;
    }

    return true;
}

int lambda(std::vector<int> elements)
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        elements[i] = elements[i] * elements[i];
    }

    int sum{std::accumulate(elements.begin(), elements.end(), 0, [](int acc, int current_element)
                            { return acc + current_element; })};
    
    std::cout << "Somme des elements : " << sum << std::endl;
    return sum;
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
    /*std::string phrase("je suis une phrase");
    findFirstWord(phrase);
    split_string(phrase);*/

    // Exercice 3 (Palindrome)
    /*std::string phrase("phrase");
    std::cout << "Phrase palindrome : " << std::boolalpha << palindrome(phrase) << std::endl;*/

    // Pour aller plus loin (lambda)
    std::vector<int> elements = {2, 3};
    lambda(elements);

    return 0;
}