#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// Exercice 1 (tri itératif)
void bubble_sort(std::vector<int> &vec)
{
    ScopedTimer timer("Itératif");
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        for (unsigned int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Exercice 2 (tri récursif)
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot)
{
    std::swap(vec[pivot], vec[right]);
    int pivotValue = vec[right];
    size_t index = left;

    for (size_t i = left; i < right; i++) {
        if (vec[i] < pivotValue) {
            std::swap(vec[i], vec[index]);
            index++;
        }
    }
    std::swap(vec[index], vec[right]);
    return index;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left < right) {
        size_t pivot = (left + right) / 2;
        pivot = quick_sort_partition(vec, left, right, pivot);
        if (pivot > 0) {
            quick_sort(vec, left, pivot - 1);
        }
        quick_sort(vec, pivot + 1, right);
    }
}


void quick_sort(std::vector<float> & vec) {
    ScopedTimer timer("QuickSort");
    quick_sort(vec, 0, vec.size() - 1);
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

// Exercice 4 : dichotomie
int search(std::vector<int> const &vec, int const value)
{
    int left = 0;
    int right = vec.size() - 1;
    int middle = (left + right) / 2;

    if (vec[middle] < value)
    {
        left = middle + 1;
        for (int i = left; i <= right; i++)
        {
            if (vec[i] == value)
                return i;
        }
    } else if (vec[middle] > value)
    {
        right = middle - 1;
        for (int i = right; i >= left; i--)
        {
            if (vec[i] == value)
                return i;
        }
    } else
    {
        return middle;
    }
    

    return -1;
}

int main()
{
    // Tri à bulle
    std::vector<int> array{1, 2, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    std::vector<int> arrayGenerate = generate_random_vector(1000);
    bubble_sort(array);
    for (unsigned int i = 0; i < array.size(); i++)
    {
        //std::cout << array[i] << ", ";
    }

    // Tri rapide
    std::vector<float> array2{1, 9, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    std::vector<int> arrayGenerate2 = generate_random_vector(1000);
    quick_sort(array2);
    for (unsigned int i = 0; i < array2.size(); i++)
    {
        //std::cout << array2[i] << ", ";
    }


    // Comparaison des algorithmes de tri
    std::vector<int> arrayComp {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::sort(arrayComp.begin(), arrayComp.end());


    // Recherche dichotomique
    std::vector<int> arraySearch {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int searching = search(arraySearch, 5);
    if (searching != -1)
        std::cout << "La valeur se trouve à l'index " << searching << std::endl;
    else
        std::cout << "La valeur n'a pas été trouvée" << std::endl;
    

    return 0;
}